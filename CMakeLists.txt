cmake_minimum_required(VERSION 3.31)
project(Dexcom_ESP32)

set(CMAKE_CXX_STANDARD 26)

include_directories(src)

add_library(Dexcom_ESP32 STATIC src/DexcomESP32.cpp)

add_executable(test_app test/main.cpp)
target_link_libraries(test_app Dexcom_ESP32)