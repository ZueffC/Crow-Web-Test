cmake_minimum_required(VERSION 3.5)

project(TestCMake)

include_directories(include)

file(COPY templates DESTINATION .)
file(COPY static DESTINATION .)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(TestCMake
    main.cpp
    include/parseBody.h
    include/crow_all.h
    include/sysinfo.h
    include/sqlite3.h
    include/sqlite3.c
    include/ormlite.h
    include/nullable.h
)

