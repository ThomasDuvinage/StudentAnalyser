# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté 
project(SerialLib)

find_package(Qt6 COMPONENTS Core REQUIRED)

# Crée des variables avec les fichiers à compiler
set(SRCS
serialib.cpp
    )
    
set(HEADERS
serialib.h
    )

add_library(SerialLib ${SRCS} ${HEADERS})

target_include_directories(SerialLib PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))
