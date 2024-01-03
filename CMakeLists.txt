cmake_minimum_required(VERSION 3.5)

project(PG2_PR2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PG2_PR2 main.cpp
    support_functions.h support_functions.cpp



)

include(GNUInstallDirs)
install(TARGETS PG2_PR2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
