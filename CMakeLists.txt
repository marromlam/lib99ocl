cmake_minimum_required(VERSION 3.13)
project(lib99ocl)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")
find_package(OpenCL REQUIRED)

include_directories( ${OPENCL_INCLUDE_DIR} )
# set(CMAKE_C_STANDARD 99)
# set(CMAKE_C_STANDARD_REQUIRED TRUE)

include_directories($CONDA_PREFIX/include)
set(CMAKE_CXX_FLAGS_INIT "-Werror -Wall -Wextra -Wpedantic")

add_link_options(-lOpenCL)
set(CMAKE_CXX_FLAGS "-std=c99 -pedantic-errors -lm -pthread -lOpenCL")


# Compiler flags
if (CMAKE_COMPILER_IS_GNUCC)
    set (CMAKE_CXX_FLAGS "-D_REETRANT -Wall -Wextra -pedantic -Wno-long-long")
	if (CMAKE_BUILD_TYPE STREQUAL "Debug")
   	    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3 -O0")
	elseif( CMAKE_BUILD_TYPE STREQUAL "Release" )
	    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG -O3 -fno-strict-aliasing")
	endif ()
endif (CMAKE_COMPILER_IS_GNUCC)


# add_compile_options(-lOpenCL)
add_compile_options(-std=c99 -pedantic-errors -lm -pthread -lOpenCL)

add_executable(Tutorial test2.c)
target_link_libraries(Tutorial -lOpenCL)
