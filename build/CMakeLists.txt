cmake_minimum_required(VERSION 3.0.2)

project(opengl_graphics CXX)

add_subdirectory(${CMAKE_SOURCE_DIR}/../tests/build ${CMAKE_CURRENT_BINARY_DIR}/tests)

include_directories(${CMAKE_SOURCE_DIR}/../includes)
include_directories(${CMAKE_SOURCE_DIR}/../)

set(src ${CMAKE_SOURCE_DIR}/../src/dummy.cpp
  ${CMAKE_SOURCE_DIR}/../declspec.h
  ${CMAKE_SOURCE_DIR}/../includes/core/memory_leaks.h
  ${CMAKE_SOURCE_DIR}/../includes/core/platform.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/batch_data.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/batch_data.inl
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/batch_traits.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_2d.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_2d.inl
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_3d.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_3d.inl
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_4d.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_4d.inl
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_5d.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_5d.inl
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_6d.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_6d.inl
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_7d.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_7d.inl
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_8d.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_8d.inl
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_9d.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/datums/interleaved_datum_9d.inl
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/interleaved_data.h
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/interleaved_data.inl
  ${CMAKE_SOURCE_DIR}/../includes/mesh_types/interleaved_traits.h
  ${CMAKE_SOURCE_DIR}/../includes/ref_count/intrusive_ptr/intrusive_ptr.h
  ${CMAKE_SOURCE_DIR}/../includes/ref_count/intrusive_ptr/ref_counted_base.h
  ${CMAKE_SOURCE_DIR}/../includes/ref_count/shared_array/shared_array.h
  ${CMAKE_SOURCE_DIR}/../includes/ref_count/shared_array/shared_count.h
  ${CMAKE_SOURCE_DIR}/../includes/ref_count/utils/non_copyable.h
  ${CMAKE_SOURCE_DIR}/../includes/ref_count/utils/sp_counted_base.h
  ${CMAKE_SOURCE_DIR}/../includes/type_traits/dimension.h
  ${CMAKE_SOURCE_DIR}/../includes/type_traits/sizeof.h
  ${CMAKE_SOURCE_DIR}/../includes/utils/non_copyable.h
  ${CMAKE_SOURCE_DIR}/../includes/utils/utils.h)

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

add_library(opengl_graphics_static STATIC ${src})
add_library(opengl_graphics_shared SHARED ${src})

add_definitions(-DUNICODE -D_UNICODE)

enable_testing()
add_test(NAME tests COMMAND graphics_tests)
