# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté 
project(FileManager)

find_package(Qt6 REQUIRED COMPONENTS 
    Core
    Widgets 
    )

# Crée des variables avec les fichiers à compiler
set(SRCS
filemanager.cpp
    )
    
set(HEADERS
filemanager.h
    )

add_library(FileManager ${SRCS} ${HEADERS})

target_include_directories(FileManager PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))

target_link_libraries(FileManager PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)