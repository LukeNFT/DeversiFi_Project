cmake_minimum_required(VERSION 3.1)

project(DeversiFi)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./..")

# The following folder will be included
include_directories("./inc")

add_executable(TradingBot ./src/main.cpp)