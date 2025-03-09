cmake_minimum_required(VERSION 3.18)
project(
    matrix_class                    
    VERSION 0.0.0
    DESCRIPTION "matrixlib"
    LANGUAGES CXX
)   
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

set(MATH_USE_DOUBLE_PRECISION "Use double precision" ON)

set(sources
    matrix.cpp
    matrix.h
    export.h
    c_api.h
    c_api.cpp
)

include(GenerateExportHeader)

add_library(static-matrixlib STATIC ${sources})

target_include_directories(static-matrixlib
PUBLIC
"<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_BINARY_DIR}>"
)

target_compile_definitions(
    static-matrixlib
    PUBLIC
    MATH_STATIC_DEFINE
    "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)

set_target_properties(static-matrixlib PROPERTIES PREFIX "")

generate_export_header(
    static-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_static.h"
    BASE_NAME matrixlib
)

add_library(shared-matrixlib SHARED ${sources})

target_include_directories(shared-matrixlib
PUBLIC
"<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_BINARY_DIR}>"
)

target_compile_definitions(
    shared-matrixlib
    PUBLIC
    "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)

set_target_properties(shared-matrixlib PROPERTIES PREFIX "")

generate_export_header(
    shared-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrixlib
)





add_executable(
    test-static-matrix
    test-static-matrix.cpp
    )

target_include_directories(test-static-matrix
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_BINARY_DIR}>"
)

target_link_libraries(test-static-matrix PRIVATE static-matrixlib)



add_executable(
    test-shared-matrix
    test-shared-matrix.cpp
    )

target_include_directories(test-shared-matrix
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_BINARY_DIR}>"
)

target_link_libraries(test-shared-matrix PRIVATE shared-matrixlib)