cmake_minimum_required(VERSION 3.16)

project(emulando-programacao-generica LANGUAGES C)

add_executable(emulando-programacao-generica main.c)

include(GNUInstallDirs)
install(TARGETS emulando-programacao-generica
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
