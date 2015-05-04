// auteur jean christophe michelin
// jean-christophe.michelin@sncf.fr
// date de creation          17/02/2014
// derniere modification     24/02/2014
// outils.cpp

#include "outils.h"
#include <sstream>
#include <iostream>
#include<string.h>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <fstream>


//------------------------------------------------------------
std::string outils::ToString( double x)
  {
      std::ostringstream oss;
      oss.precision(12);
      oss << x;
      std::string s = oss.str();
      return s;
  }

//------------------------------------------------------------
std::string outils::ToString( unsigned long int x)
{
    std::ostringstream oss;
    oss.precision(12);
    oss << x;
    std::string s = oss.str();
    return s;
}


//------------------------------------------------------------
std::string outils::ToString( long int x)
{
    std::ostringstream oss;
    oss.precision(12);
    oss << x;
    std::string s = oss.str();
    return s;
}
