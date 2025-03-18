cmake_minimum_required(VERSION 3.18)
project(
    matrixlib                    
    VERSION 0.0.0
    DESCRIPTION "matrixlib"
    LANGUAGES CXX
)   
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
set(MATH_USE_DOUBLE_PRECISION "Use double precision" ON)

# Создаем список исходных файлов, которые будут использоваться в проекте
set(sources
    <lib/matrix.cpp>
    <lib/matrix.h>
    <lib/export.h>
    <lib/c_api.h>
    <lib/c_api.cpp>
)

# Включаем модуль GenerateExportHeader для автоматической генерации заголовочного файла экспорта
include(GenerateExportHeader)

# Создаем динамическую библиотеку (shared library) с именем "shared-matrixlib" из указанных исходных файлов
add_library(shared-matrixlib SHARED ${sources}) 



# Указываем директории, где находятся заголовочные файлы для библиотеки shared-matrixlib
target_include_directories(shared-matrixlib
PUBLIC
"<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/lib>"
"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_BINARY_DIR}>"
)

# Добавляем определение препроцессора MATH_DOUBLE_PREC_DEFINE, если опция MATH_USE_DOUBLE_PRECISION включена
target_compile_definitions(
    shared-matrixlib
    PUBLIC
    "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)

# Определяем макрос MATRIXLIB_EXPORTS при сборке библиотеки
target_compile_definitions(shared-matrixlib
    PRIVATE
        MATRIXLIB_EXPORTS  # Этот макрос активирует __declspec(dllexport) в matrix.h
)


#set_target_properties(shared-matrixlib PROPERTIES PREFIX "")
# Установка выходных файлов в папку lib
set_target_properties(shared-matrixlib PROPERTIES
    OUTPUT_NAME "matrix"
    PREFIX "lib"
    SUFFIX ".dll"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/"
)

# Генерируем заголовочный файл экспорта для библиотеки shared-matrixlib
generate_export_header(
    shared-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrixlib
)

# Создаем исполняемый файл "test-shared-matrix" из исходного файла test-shared-matrix.cpp
add_executable(
    test-shared-matrix
    lib/test-shared-matrix.cpp
    )

# Указываем директории, где находятся заголовочные файлы для исполняемого файла test-shared-matrix
target_include_directories(test-shared-matrix
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_BINARY_DIR}>"
)

# Связываем исполняемый файл test-shared-matrix с библиотекой shared-matrixlib
target_link_libraries(test-shared-matrix PRIVATE shared-matrixlib)


# Копируем libmatrix.dll и libmatrix.dll.a в папку lib после сборки
add_custom_command(TARGET shared-matrixlib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:shared-matrixlib>
        ${CMAKE_SOURCE_DIR}/lib
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_LINKER_FILE:shared-matrixlib>
        ${CMAKE_SOURCE_DIR}/lib
)