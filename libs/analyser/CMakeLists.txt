# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté 
project(Analyser)

find_package(Qt6 COMPONENTS Core REQUIRED)

# Crée des variables avec les fichiers à compiler
set(SRCS
analyser.cpp
    )
    
set(HEADERS
analyser.h
    )

add_library(Analyser ${SRCS} ${HEADERS})

target_include_directories(Analyser PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))

target_link_libraries(Analyser PRIVATE Scanner Qt${QT_VERSION_MAJOR}::Core )