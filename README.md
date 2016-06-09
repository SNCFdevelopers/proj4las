# proj4las
Un petit soft en c++ pour changer de système de coordonnées géographiques.

1. Installer 
-proj4
-boost
-liblas

2. Modifier le CMakeLists.txt

3. Utiliser Cmake pour génerer le projet

4. Compiler

5. Faire un test :
par exemple passer du RGF93 CC45 (en mètre) au RGF93 Lambert 93 (en mètre)
proj4las.exe in.las out.las 3945 2154 0 0

Pour plus d'information sur les systèmes géodesiques :  http://geodesie.ign.fr/index.php?page=srt
