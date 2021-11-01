find_package(CURL CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(Boost 1.56 COMPONENTS filesystem REQUIRED)
# find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)

find_package(QT NAMES QT5 Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# add_executable(main main.cpp)
# target_link_libraries(main PRIVATE CURL::libcurl fmt::fmt Boost::boost)

# file(COPY ${CMAKE_SOURCE_DIR}/config/
#         DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
# add_executable(server server.cpp)
# target_link_libraries(server PRIVATE fineftp::fineftp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(PROJECT_SOURCES
        mainui.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(mainui
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(mainui SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(mainui
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(mainui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


if (WIN32)
    set_property(TARGET mainui PROPERTY WIN32_EXECUTABLE true)
endif (WIN32)

#set_target_properties(mainui PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(mainui)
endif()
