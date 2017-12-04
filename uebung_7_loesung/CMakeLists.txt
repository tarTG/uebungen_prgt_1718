#the cmake version
cmake_minimum_required(VERSION 2.8)
#project name
project(uebung_7)
#project version
set(PROJECT_VERSION 0.1)
#generate a message
message(STATUS "~~~ ${PROJECT_NAME} - v${PROJECT_VERSION} ~~~")
#set cmake module path
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

#set include dirctories
include_directories("include" )

include_directories("3rdParty" )

#load SFML
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)

include_directories(${SFML_INCLUDE_DIR})
#set C++ standart
set (CMAKE_CXX_STANDARD 14)
#add source directory
add_subdirectory("src")

