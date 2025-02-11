cmake_minimum_required(VERSION 3.29)
project(TestingC C)

set(CMAKE_C_STANDARD 11)

include_directories(lib)

add_executable(TestingC
    lib/lib.c
    lib/lib.h
    main.c
        lib/incremental/incremental.h
        lib/incremental/incremental.c
        lib/sorting/sorting.c
        lib/sorting/sorting.h
)
