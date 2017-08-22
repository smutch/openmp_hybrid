# project setup
cmake_minimum_required(VERSION 3.5)
project(openmp_hybrid_test)

# MPI
find_package(MPI REQUIRED)
include_directories(SYSTEM ${MPI_INCLUDE_PATH})
link_libraries(${MPI_C_LIBRARIES})

# OpenMP
find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")

# executable
add_executable(omp_hybrid omp_hybrid.c)
