cmake_minimum_required(VERSION 3.23)
project(SmokinStats)

set(CMAKE_CXX_STANDARD 14)

add_executable(SmokinStats main.cpp SmokingHashMap.h SmokingHashMap.cpp SmokingStat.h SmokingStat.cpp SmokingGraph.cpp SmokingGraph.h)
