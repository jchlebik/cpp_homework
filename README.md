# Roboauto Interview Process C++ Homework Assignment
Implemented c++ assignment from Roboauto's job interview process.

Implementation of the assignment can be found inside the [src folder](src/assignment.cpp). Also implemented some tests inside the [tests folder](tests/). Everything can be compiled using the CMake build system. The result of the compilation is a statically build library inside the build/src folder and 4 exectuables inside the build/tests folder.

Tested and implemented using Ubuntu/24.04

## Installation
To install and run this project, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/jchlebik/cpp_homework.git
    ```
2. Navigate to the project directory:
    ```sh
    cd cpp_homework
    ```
4. Build the project using the provided CMAKE:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```
5. Run tests using CTest
    ```
    ctest
    ```
