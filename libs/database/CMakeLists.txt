# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté 
project(Database)

find_package(Qt6 REQUIRED COMPONENTS 
    Core 
    Sql
    )

# Crée des variables avec les fichiers à compiler
set(SRCS
database.cpp
    )
    
set(HEADERS
database.hpp
    )

add_library(Database ${SRCS} ${HEADERS})

target_include_directories(Database PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))

target_link_libraries(Database PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql)