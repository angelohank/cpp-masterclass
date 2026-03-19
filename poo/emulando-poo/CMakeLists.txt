cmake_minimum_required(VERSION 3.16)

project(emulando-poo LANGUAGES C)

add_executable(emulando-poo main.c)

include(GNUInstallDirs)
install(TARGETS emulando-poo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
