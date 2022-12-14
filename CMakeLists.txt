cmake_minimum_required(VERSION 3.23)
project(oaip_lab C)

set(CMAKE_C_STANDARD 17)

add_subdirectory(lab-lib lab-lib)
link_libraries(lab-lib)

add_executable(task1 lab4/task1.c)
add_executable(task2 lab4/task2.c)
add_executable(task3 lab4/task3.c)
add_executable(task5.1 lab5/task1.c)
add_executable(task5.3 lab5/task3.c)
add_executable(task5.2 lab5/task2.c)
add_executable(task6.1 lab6/task1.c)
add_executable(task6.2 lab6/task2.c)
add_executable(task7.1 lab7/task1.c)
add_executable(task7.2 lab7/task2.c)
add_executable(task8.1 lab8/task1.c)