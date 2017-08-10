cmake_minimum_required(VERSION 3.0.2)
include_directories(../)
include_directories(../include/)

set(SRC
  dummy.cpp
)

if (BUILD_SHARED_LIBS)
  add_library(
    opengl_graphics
    SHARED
    ${SRC}
  )
  add_definitions(
    -DOPENGL_GRAPHICS_SHARED
    -DOPENGL_GRAPHICS_EXPORTS
  )
else()
  add_library(
    opengl_graphics
    STATIC
    ${SRC}
  )
  add_definitions(
    -DOPENGL_GRAPHICS_STATIC
  )
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  add_definitions(
    _CRT_SECURE_NO_WARNINGS
  )
else()
  set_target_properties(
    opengl_graphics
    PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall \
      -fno-strict-aliasing -std=c++11"
  )
endif()
