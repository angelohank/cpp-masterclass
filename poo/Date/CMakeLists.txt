cmake_minimum_required(VERSION 3.28) #versao minima para usar modules

project(Date LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#define o caminho de saida do binario
set(BIN_DIR ${CMAKE_BINARY_DIR}/bin)

#copia o module que tem no diretorio de instalacao do visual studio para a pasta bin
file(COPY "$ENV{VCToolsInstallDir}/modules/std.ixx"
    DESTINATION ${BIN_DIR}
)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE FILE_SET CXX_MODULES FILES
        ${BIN_DIR}/std.ixx
        date.ixx

    PRIVATE
        main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${BIN_DIR})

include(GNUInstallDirs)
install(TARGETS Date
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
