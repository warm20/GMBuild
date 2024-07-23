cmake_minimum_required(VERSION 3.10)
project(GMBuild)

set(SRC_LIST)
set(CORE_LIST)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/core CORE_LIST)

add_compile_options(-Wall -std=c17)

add_executable(${PROJECT_NAME} ${SRC_LIST} ${CORE_LIST})