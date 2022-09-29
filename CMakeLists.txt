cmake_minimum_required(VERSION 3.0.0)
set(PROJECT_NAME_STR schedule-CANBus-rpi)
project(${PROJECT_NAME_STR} VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

find_package(Boost 1.67 COMPONENTS program_options REQUIRED)

if(NOT fastcdr_FOUND)
    find_package(fastcdr REQUIRED)
endif()

if(NOT fastrtps_FOUND)
    find_package(fastrtps REQUIRED)
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

file(GLOB DDS_SOURCES_CXX "*.cpp")
add_library(data_lib data.cxx)
target_link_libraries(data_lib)

add_executable(${PROJECT_NAME_STR} ${DDS_SOURCES_CXX})
target_link_libraries(${PROJECT_NAME_STR} ${Boost_LIBRARIES} data_lib fastcdr fastrtps)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
