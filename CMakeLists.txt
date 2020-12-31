cmake_minimum_required(VERSION 3.8)
project(Stencil C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

SET(CMAKE_C_FLAGS  -mavx2)

add_executable(Stencil
        src/main.c
        src/base.c
        src/permutation.c
        src/utils.c)

add_executable(Test src/original.c)

find_package(OpenMP)
if (OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif ()

if (SIZE)
    add_definitions(-DSIZE=${SIZE})
endif ()

if (TIME)
    add_definitions(-DTIME=${TIME})
endif ()

if (IJK)
    add_definitions(-DIJK)
endif ()

if (IKJ)
    add_definitions(-DIKJ)
endif ()

if (JIK)
    add_definitions(-DJIK)
endif ()

if (JKI)
    add_definitions(-DJKI)
endif ()

if (KIJ)
    add_definitions(-DKIJ)
endif ()

if (KJI)
    add_definitions(-DKJI)
endif ()


