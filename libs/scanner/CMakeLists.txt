# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté 
project(Scanner)

find_package(Qt6 REQUIRED COMPONENTS 
    Core
    Network 
    )

# Crée des variables avec les fichiers à compiler
set(SRCS
scanner.cpp
    )
    
set(HEADERS
scanner.h
    )

add_library(Scanner ${SRCS} ${HEADERS})

target_include_directories(Scanner PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))

target_link_libraries(Scanner PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)