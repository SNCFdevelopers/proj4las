#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <proj_api.h>
#include "affichage_console.h"
#include "../../../noyau/calcul_geodesique.h"
#include "outils.h"
#include <liblas/liblas.hpp>

int Convertion(double &x, double &y, double &z, unsigned long int EPSG_In, unsigned long int EPSG_Out)
{
	std::string input = "+init=epsg:" + outils::ToString(EPSG_In);
	std::string output = "+init=epsg:" + outils::ToString(EPSG_Out);
	
	projPJ source = pj_init_plus(input.c_str());
  	projPJ target = pj_init_plus(output.c_str());

	if(source == NULL || target == NULL) return 1;

	return pj_transform(source, target, 1, 1, &x, &y, &z );
}

//---------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
	// quelques exemples d'EPSG
	// RGF93 4171 coordonnees sur l ellipsoide (latitude longitude)
	// RGF 93 CC45 3945 
	// RGF93 L93 2154

	std::string message_erreur = "erreur attendu nom_exe fichier_las_in fichier_las_out epsg_in epsg_out  type_unite_entree (0 radian/metres 1-> degrees decimaux) type_unite_sortie (0 radian metre 1 -> degrees decimaux)";
	affichage_console::afficheLogoSncf();

	if(argc != 7)
	{
		std::cerr << message_erreur << std::endl;
		return 1;
	}

	std::string fichier_in_las = argv[1];
	std::string fichier_out_las = argv[2];


	unsigned long int EPSG_IN = std::atoi(argv[3]);
	unsigned long int EPSG_OUT = std::atoi(argv[4]);
	unsigned long int type_entree = std::atoi(argv[5]); // 0 metres ou des radians 1 degrees decimaux
	unsigned long int type_sortie = std::atoi(argv[6]); // 0 metres ou des radians 1 degree decimaux

	std::string input = "+init=epsg:" + outils::ToString(EPSG_IN);
	std::string output = "+init=epsg:" + outils::ToString(EPSG_OUT);
	
	projPJ source = pj_init_plus(input.c_str());
	projPJ target = pj_init_plus(output.c_str());

	if(source==NULL || target==NULL)
	{
		std::cerr << "erreur a la definition de la projection" << std::endl;
	    	return 1;
	}

	// je cree les flux
	std::ifstream ifs(fichier_in_las.c_str(), std::ios::in | std::ios::binary);

	if(ifs.fail())
	{
		std::cerr << "erreur d ouvrir un flux de lecture pour " << fichier_in_las<< std::endl;
		return 1;
	}


	liblas::ReaderFactory f;
	liblas::Reader reader = f.CreateWithStream(ifs);

	liblas::Header header = reader.GetHeader();

	std::ofstream flux_out(fichier_out_las.c_str(), std::ios::out | std::ios::trunc | std::ios::binary);
	
	if(flux_out.fail())
	{

		std::cerr<<"erreur a l ouverture du flux pour "<<fichier_out_las<<std::endl;
		return 1;
	}
	
	// modification du header
	liblas::Header header_writer = header;

	double x_offset = header.GetOffsetX();
	double y_offset = header.GetOffsetY();
	double z_offset = header.GetOffsetZ();

	double x_max = header.GetMaxX();
	double y_max = header.GetMaxY();
	double z_max = header.GetMaxZ();

	double x_min = header.GetMinX();
	double y_min = header.GetMinY();
	double z_min = header.GetMinZ();

	if(type_entree == 1)
	{
		x_offset = outils::DegToRad(x_offset);
		y_offset = outils::DegToRad(y_offset);

		x_max = outils::DegToRad(x_max);
		y_max = outils::DegToRad(y_max);
		
		x_min = outils::DegToRad(x_min);
		y_min = outils::DegToRad(y_min);
	}
	
	if(0 != Convertion(x_offset,y_offset,z_offset,EPSG_IN,EPSG_OUT))
	{
		std::cerr << "erreur a la convertion de coordonnee" << std::endl;
		return 1;
	}



	if(0 != Convertion(x_max,y_max,z_max,EPSG_IN,EPSG_OUT))
	{
		std::cerr << "erreur a la convertion de coordonnee" << std::endl;
		return 1;
	}


	if(0 != Convertion(x_min,y_min,z_min,EPSG_IN,EPSG_OUT))
	{
		std::cerr <<"erreur a la convertion de coordonnee" << std::endl;
		return 1;
	}

	header_writer.SetSoftwareId("SNCF lidar tools");

	if(type_sortie == 0) header_writer.SetScale(0.0001, 0.0001, 0.0001);
	else if(type_sortie == 1) header_writer.SetScale(0.0000000001, 0.0000000001, 0.0001);
	
	if(type_sortie == 1)
	{
		x_offset=outils::RadToDeg(x_offset);
		y_offset=outils::RadToDeg(y_offset);
		x_max=outils::RadToDeg(x_max);
		y_max=outils::RadToDeg(y_max);
		x_min=outils::RadToDeg(x_min);
		y_min=outils::RadToDeg(y_min);
	}

	header_writer.SetOffset(x_offset, y_offset, z_offset);

	liblas::Bounds<double > mon_bounds(x_min,y_min,z_min,x_max,y_max,z_max);
	header_writer.SetExtent(mon_bounds);


	// ici d'autres modif eventuelles;
	liblas::Writer writer(flux_out, header_writer);
	unsigned long int compteur = 0;
	while (reader.ReadNextPoint())
    	{
		compteur++;
		if(compteur % 1000000 == 0) std::cerr << "pts traite : " << compteur << std::endl;
		
		liblas::Point const& p_read = reader.GetPoint();
		liblas::Point p_write(&(writer.GetHeader()));;
		
		p_write.SetData(p_read.GetData());

		double x = p_read.GetX();
		double y = p_read.GetY();
		double z = p_read.GetZ();

		if(type_entree == 1)
		{
			x = outils::DegToRad(x);
			y = outils::DegToRad(y);
			z = outils::DegToRad(z);
		}


		if(0 != pj_transform(source, target, 1, 1, &x, &y, &z ))
		{
	
			std::cerr << "erreur a la convertion de coordonnee" << std::endl;
			return 1;
		}

	
		if(type_sortie == 1)
		{
			x = outils::RadToDeg(x);
			y = outils::RadToDeg(y);
		}

   		p_write.SetX(x);
		p_write.SetY(y);
		p_write.SetZ(z);
		
	        writer.WritePoint(p_write);
	}
	
	ifs.close();

	std::cerr << "succes" << std::endl;

	return 0;
}
