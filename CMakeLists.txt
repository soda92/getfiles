project(get-files)
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# include_directories(fineftp-server/fineftp-server/include)

# add_subdirectory(fineftp-server)
add_subdirectory(test)
add_subdirectory(src)

# add_subdirectory(fineftp-server)
