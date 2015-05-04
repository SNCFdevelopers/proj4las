// auteur jean christophe michelin
// jean-christophe.michelin@sncf.fr
// date de creation          17/02/2014
// derniere modification     17/02/2014
// affichage_console.h




#ifndef AFFICHAGE_CONSOLE_H
#define AFFICHAGE_CONSOLE_H
#include <iostream>
#include <time.h>
#include <cstdlib>
class affichage_console
{
public:
    affichage_console(){;}


    //---------------------------------------------
    static void afficheLogoSncf(){
     std::cerr.precision(12); // je le fait une fois pour toute
srand(time(NULL));
    std::cerr<<" .```                                  "<<std::endl;
    std::cerr<<"'''''''''''''',                        "<<std::endl;
    std::cerr<<"''''''''''''''''''',                   "<<std::endl;
    std::cerr<<"'''''''''''''''''''''''                "<<std::endl;
    std::cerr<<"''''''''''''''''''''''''';             "<<std::endl;
    std::cerr<<"''''''''''''''''''''''''''''           "<<std::endl;
    std::cerr<<"''''''''''''''''''''''''''''''         "<<std::endl;
    std::cerr<<"''''.     :'''; ''`  :  ````:',        "<<std::endl;
    std::cerr<<"'''  ''';  `''. ` `''' ,''''''         "<<std::endl;
    std::cerr<<"'''  .'', ; `'   ,'''' '''''''         "<<std::endl;
    std::cerr<<"''''.  `: ': '   '''':     '':         "<<std::endl;
    std::cerr<<"''''''; `''' `   ''''  ''''''          "<<std::endl;
    std::cerr<<"'''''''  ''';` ; `;'' .''''''          "<<std::endl;
    std::cerr<<"''     .'''''  ';` `` '''''':          "<<std::endl;
    std::cerr<<"''''''''''''''''''''''''''''           "<<std::endl;
    std::cerr<<"''''''''''''''''''''''''''''           "<<std::endl;
}
	};

#endif // AFFICHAGE_CONSOLE_H
