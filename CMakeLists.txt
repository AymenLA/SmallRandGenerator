# Specify the minimum version.
cmake_minimum_required(VERSION 3.9)

# Specify the project info.
project(srng VERSION 1.0.0 DESCRIPTION "Small durty Random number generator library")

set(LIB_SOURCE_DIR "src")
set(LIB_INCLUDE_DIR "include")

add_library(${PROJECT_NAME} STATIC           
		    ${LIB_SOURCE_DIR}/SmallRandGenerator.c
        	${LIB_INCLUDE_DIR}/SmallRandGenerator.h)


# Configure the directories to search for header files.
target_include_directories(${PROJECT_NAME} PRIVATE ${LIB_INCLUDE_DIR})

# Set the public header property to the one with the actual API.
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${LIB_INCLUDE_DIR}/SmallRandGenerator.h)

# For access to standard installation directory variables (CMAKE_INSTALL_xDIR).
include(GNUInstallDirs)

# Set library shared object and API header file to install.
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)