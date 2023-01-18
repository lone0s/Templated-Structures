cmake_minimum_required(VERSION 3.23)
project(T_List)

set(CMAKE_CXX_STANDARD 14)

add_executable(T_List main.cpp Templated_List/T_List.h Successeur.h Sommet.h Graph.h PriorityQueue/T_PriorityQueue.h)
