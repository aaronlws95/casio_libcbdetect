cmake_minimum_required(VERSION 3.14)
project(casio_libcbdetect)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

set(_MODULE_NAME cbdetect)
file(GLOB _MODULE_SOURCES src/*.cc)
add_library(${_MODULE_NAME} ${_MODULE_SOURCES})
find_package(opencv)
target_link_libraries(${_MODULE_NAME} opencv::opencv)

target_include_directories(${_MODULE_NAME} PUBLIC include)

install(TARGETS ${_MODULE_NAME} ARCHIVE DESTINATION lib LIBRARY DESTINATION lib)

