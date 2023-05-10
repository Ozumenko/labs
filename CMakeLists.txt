cmake_minimum_required(VERSION 3.23)
project(oaip_lab C)

set(CMAKE_C_STANDARD 17)

add_subdirectory(lab-lib lab-lib)
link_libraries(lab-lib)

add_executable(lab1 lab1/main.c)
add_executable(compress "lab2/main.compress.c" lab2/comp.h lab2/compress.c)
add_executable(decompress "lab2/main.decompress.c"  lab2/decomp.h lab2/decompress.c  lab2/comp.h lab2/compress.c)
add_executable(lab3 "lab3/task.c")
add_executable(filters "lab3/files.c")
add_executable(main "lab3/main.c")