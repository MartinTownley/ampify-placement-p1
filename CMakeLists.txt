 
cmake_minimum_required(VERSION 3.12)

project(Calculator)

add_executable(calcu
    source/calculator-main.cpp
    README.md
)

target_compile_features(calcu PRIVATE cxx_std_17)
