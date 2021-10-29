find_package(CURL CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(Boost 1.56 COMPONENTS date_time filesystem REQUIRED)

add_executable(t test.c)
target_link_libraries(t PRIVATE CURL::libcurl fmt::fmt Boost::boost)

add_executable(location location.cpp)
target_link_libraries(location PRIVATE fmt::fmt)

file(COPY ${CMAKE_SOURCE_DIR}/config/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug/)
