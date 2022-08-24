cmake_minimum_required(VERSION 3.18)

set(LIB_SOURCE_DIR "src" PUBLIC)
set(LIB_INCLUDE_DIR "include" PUBLIC)

add_library(libsrg 
            ${LIB_SOURCE_DIR}/SmallRandGenerator.c
            ${LIB_INCLUDE_DIR}/SmallRandGenerator.h)