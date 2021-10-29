find_package(CURL CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(Boost 1.56 COMPONENTS date_time filesystem REQUIRED)

add_executable(main src.c)
target_link_libraries(main PRIVATE CURL::libcurl)
