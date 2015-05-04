// auteur jean christophe michelin
// jean-christophe.michelin@sncf.fr
// date de creation          17/02/2014
// derniere modification     24/02/2014
// outils.h


#ifndef OUTILS_H
#define OUTILS_H
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
class outils
{
public:
    outils(){;}


  static   std::string ToString( double x);
  static   std::string ToString( unsigned long int x);
  static   std::string ToString( long int x);

static inline double DegToRad(double deg) {return deg*std::atan((double)1)*4/180;} 
static inline double RadToDeg(double deg) {return deg*45/std::atan((double)1);} 


};

#endif // OUTILS_H
