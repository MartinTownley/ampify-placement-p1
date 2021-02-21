 
cmake_minimum_required(VERSION 3.12)

project(Calculator)

add_executable(calcu
    source/main.cpp
    source/calculator.h
    source/constants.h
    source/inputProcessor.h
    source/resultChecker.h
    source/tokeniser.h
    README.md
)

target_compile_features(calcu PRIVATE cxx_std_17)
