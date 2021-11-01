find_package(CURL CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(Boost 1.56 COMPONENTS date_time filesystem REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE CURL::libcurl fmt::fmt Boost::boost)

# file(COPY ${CMAKE_SOURCE_DIR}/config/
#         DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
