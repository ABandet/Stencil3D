cmake_minimum_required(VERSION 3.12)
project(Stencil C)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()

set(CMAKE_C_STANDARD 11)

include_directories(include)

SET(CMAKE_C_FLAGS  -mavx2)

add_executable(Stencil
        src/main.c
        src/base.c
        src/permutation.c
        src/utils.c src/vecto.c src/blocks.c)

add_executable(Test src/original.c)

find_package(OpenMP REQUIRED)
target_link_libraries(Stencil PRIVATE OpenMP::OpenMP_C)

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

if (VECTO)
    add_definitions(-DVECTO)
endif ()




