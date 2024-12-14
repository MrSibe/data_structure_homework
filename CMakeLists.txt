cmake_minimum_required(VERSION 3.10)

add_compile_options("-fexec-charset=gbk")

project(data_structure_homework)

aux_source_directory(src SRC_DIR)
include_directories(include INC_DIR)

add_executable(data_structure_homework ${SRC_DIR} ${INC_DIR})