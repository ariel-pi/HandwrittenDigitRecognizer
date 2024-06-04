cmake_minimum_required(VERSION 3.23)
project(ex4_ariel_pinhas)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4_ariel_pinhas
        Activation.h
        Dense.h
        main.cpp
        Matrix.cpp
        Activation.cpp
        Dense.cpp
        MlpNetwork.cpp
        Matrix.h
        MlpNetwork.h)
