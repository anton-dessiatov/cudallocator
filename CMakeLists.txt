cmake_minimum_required(VERSION 3.22)
project(cudallocator)

find_package(CUDAToolkit REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} src/main.cc)
target_link_libraries(${CMAKE_PROJECT_NAME} CUDA::cudart)

install(TARGETS ${CMAKE_PROJECT_NAME})
