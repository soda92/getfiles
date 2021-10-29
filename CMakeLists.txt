project(get-files)
cmake_minimum_required(VERSION 3.21)

find_package(CURL CONFIG REQUIRED)
add_executable(main src.c)
target_link_libraries(main PRIVATE CURL::libcurl)

