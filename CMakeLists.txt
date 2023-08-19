cmake_minimum_required(VERSION 3.26)
project(MathematicsFinalProject)

set(CMAKE_CXX_STANDARD 17)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(Python3 COMPONENTS NumPy)

# Add the path to matplotlib_cpp to the CMake module path
list(APPEND CMAKE_MODULE_PATH "/home/mwichabe/matplotlib-cpp")

find_package(matplotlib_cpp REQUIRED)

add_executable(MathematicsFinalProject main.cpp
        plotting.cpp
        Grid.cpp
        LinearSolver.cpp
        NavierStokesSolver.cpp
        TestCases.cpp
)

target_link_libraries(MathematicsFinalProject PRIVATE
        ${Python3_LIBRARIES}
        ${matplotlib_cpp_LIBRARIES}
)
