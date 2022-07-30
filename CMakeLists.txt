cmake_minimum_required(VERSION 3.0.0)
project(schedule-CANBus-rpi VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(Boost 1.67 COMPONENTS program_options REQUIRED)

add_executable(schedule-CANBus-rpi main.cpp)
target_link_libraries(schedule-CANBus-rpi Boost::program_options)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
