cmake_minimum_required(VERSION 3.20)
project(Books)

set(CMAKE_CXX_STANDARD 14)

add_executable(Books main.cpp Book.cpp Book.h LinkedList.cpp LinkedList.h NodeDouble.h ManagementBook.cpp ManagementBook.h)
