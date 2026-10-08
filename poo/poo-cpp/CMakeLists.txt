cmake_minimum_required(VERSION 3.16)

project(poo-cpp LANGUAGES CXX)

#versoes minimas de compilador para usar printlib:
# gcc > 14
# clang > 17 (parsial, completa na 18)

set(CMAKE_CXX_STANDARD 23) #alterando para usar recursos do c++ 23 -> printlib
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(poo-cpp main.cpp
    date.h)

include(GNUInstallDirs)
install(TARGETS poo-cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
