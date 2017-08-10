enable_testing()
find_package(Check REQUIRED)
include_directories(${CHECK_include_DIRS})
set(LIBS ${LIBS} ${CHECK_LIBRARIES} opengl_graphics)
include_directories(include ../include)

set(unit_tests "mesh_types" "ref_counted")

foreach(unit_test ${unit_tests})
  add_executable("check_${unit_test}"
    check_${unit_test}.cpp
    suite.cpp
  )
  target_link_libraries("check_${unit_test}" ${LIBS})
  add_test("check_${unit_test}" "${CMAKE_CURRENT_BINARY_DIR}/${unit_test}/")

  if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definitions(
      _CRT_SECURE_NO_WARNINGS
    )
  else()
    set_target_properties(
      "check_${unit_test}"
      PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall \
        -fno-strict-aliasing -std=c++11 -Wno-reserved-user-defined-literal"
    )
  endif()
endforeach()
