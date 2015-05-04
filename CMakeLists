#auteur jean christophe michelin 
#date 29/04/2015

# Pour éviter un warning au lancement de CMake, on doit préciser la version minimale
cmake_minimum_required(VERSION 2.6) 
# Nom du projet
project(proj4las)

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules${CMAKE_MODULE_PATH}")


FIND_PACKAGE(LIBLAS REQUIRED)
IF(LIBLAS_FOUND)
        message(STATUS "LIBLAS found !")
        include_directories(${LIBLAS_INCLUDE_DIR})
        MESSAGE(STATUS LIBLAS_INCLUDE_DIR=${LIBLAS_INCLUDE_DIR})
 message(STATUS LIBLAS_LIB= ${LIBLAS_LIBRARY})
ELSE(LIBLAS_FOUND)
        MESSAGE(SEND_ERROR "LIBLAS not found ! Install it from synaptic or internet")
ENDIF(LIBLAS_FOUND)




# le dossier de boost
    include_directories(C:/bibliotheque_visual_2010/boost/include)
# le dossier ou proj4 est installe	
    include_directories(C:/OSGeo4W/include)



#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% creation fichier emprise et sommet pva %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#Declaration de l'executable
add_executable(proj4las
        main.cpp
		outils.cpp
        )

TARGET_LINK_LIBRARIES(proj4las
${LIBLAS_LIBRARY}
C:/bibliotheque_visual_2010/boost/lib/libboost_thread-vc100-mt-1_50.lib
C:/bibliotheque_visual_2010/boost/lib/libboost_system-vc100-mt-1_50.lib
C:/bibliotheque_visual_2010/boost/lib/libboost_thread-vc100-mt-1_50.lib
C:/OSGeo4W/lib/proj_i.lib
)
