cmake_minimum_required(VERSION 3.16)

project(poo-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20) #alterando para usar recursos do c++ 20
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(poo-cpp main.cpp
    date.h date.cpp)

include(GNUInstallDirs)
install(TARGETS poo-cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
