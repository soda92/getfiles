project(get-files)
cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(CURL CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(Boost 1.56 COMPONENTS date_time filesystem REQUIRED)
add_executable(main src.c)
target_link_libraries(main PRIVATE CURL::libcurl)

add_subdirectory(test)