cmake_minimum_required(VERSION 3.23)
project(_ C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(task1 lab4/task1.c)
add_executable(task2 lab4/task2.c)
add_executable(task3 lab4/task3.c)
add_executable(task5.1 lab5/task1.c)
add_executable(task5.3 lab5/task3.c)
add_executable(task5.2 lab5/task2.c)