cmake_minimum_required(VERSION 3.5)

project(StudentAnalyser VERSION 0.1 LANGUAGES CXX)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 COMPONENTS 
    Widgets
    Core
    REQUIRED)

add_subdirectory(libs/scanner)
add_subdirectory(libs/analyser)
add_subdirectory(libs/FileManager)
add_subdirectory(libs/Logger)
add_subdirectory(libs/Dataviewer)
add_subdirectory(libs/seriallib)


# Crée des variables avec les fichiers à compiler
set(SRCS
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.ui
    )

set(HEADERS
    include/mainwindow.h
    
        ) 
    
# Notre exécutable
add_executable(StudentAnalyser ${SRCS} ${HEADERS})


# if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#     qt_add_executable(StudentAnalyser
#         MANUAL_FINALIZATION
#         ${SRCS}
#     )
# # Define target properties for Android with Qt 6 as:
# #    set_property(TARGET StudentAnalyser APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
# else()
#     if(ANDROID)
#         add_library(StudentAnalyser SHARED
#             ${SRCS}
#         )
# # Define properties for Android with Qt 5 after find_package() calls as:
# #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#     else()
#         add_executable(StudentAnalyser
#             ${SRCS}
#         )
#     endif()
# endif()

target_link_libraries(StudentAnalyser PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets 
    Qt${QT_VERSION_MAJOR}::Core
    Analyser
    Scanner
    FileManager
    Logger
    Dataviewer
    )

target_include_directories(StudentAnalyser PRIVATE
    include/
    )

set_target_properties(StudentAnalyser PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(StudentAnalyser)
endif()
