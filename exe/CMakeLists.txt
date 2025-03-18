cmake_minimum_required(VERSION 3.18)
project(MatrixExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем путь к библиотеке
set(LIBRARY_DIR "${CMAKE_SOURCE_DIR}/libs/matrixlib")

# Подключаем библиотеку
link_directories(${LIBRARY_DIR})

# Создаем исполняемый файл
add_executable(matrix_example main.cpp)

# Подключаем библиотеку импорта (libmatrix.dll.a)
target_link_libraries(matrix_example PRIVATE matrix)