find_package(CURL CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(Boost 1.56 COMPONENTS date_time filesystem REQUIRED)

add_executable(t test.cc)
target_link_libraries(t PRIVATE CURL::libcurl fmt::fmt Boost::boost)

add_executable(location location.cpp)

add_executable(t3 test3.c)
target_link_libraries(t3 PRIVATE CURL::libcurl fmt::fmt Boost::boost)
