cmake_minimum_required(VERSION 3.23)
project(T_List)

set(CMAKE_CXX_STANDARD 14)

add_executable(T_List main.cpp T_List.h T_Node.h Successeur.h Sommet.h Graph.h)
