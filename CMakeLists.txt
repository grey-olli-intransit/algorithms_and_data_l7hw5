cmake_minimum_required(VERSION 2.8)
add_compile_options(-Wall)
project(L7HW5)
add_executable(l7hw5 src/l7hw5.c)
target_include_directories(l7hw5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(l7hw5 PRIVATE m)

