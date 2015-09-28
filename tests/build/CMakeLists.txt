cmake_minimum_required(VERSION 3.0.2)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/../includes)
include_directories(${CMAKE_SOURCE_DIR}/../)

set(src ${CMAKE_SOURCE_DIR}/../tests/main.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_base.h
  ${CMAKE_SOURCE_DIR}/../tests/test_mesh_types.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_mesh_types.h
  ${CMAKE_SOURCE_DIR}/../tests/test_ref_counted.cpp
  ${CMAKE_SOURCE_DIR}/../tests/test_ref_counted.h)

  
include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

add_executable(opengl_graphics_tests ${src})

add_definitions(-DUNICODE -D_UNICODE)
  
target_link_libraries(opengl_graphics_tests opengl_graphics_static)

install(TARGETS opengl_graphics_tests DESTINATION bin)
