#ifndef TEST_TEST_BASE_H_INCLUDED
#define TEST_TEST_BASE_H_INCLUDED

#include <cassert>
#include <iostream>

#define OPENGL_GRAPHICS_ASSERT_EQUALS(rhs, lhs) \
  if (!(rhs == lhs)) { \
    std::cout << "Failure on " << __LINE__ << " in " << __FILE__ << " in " \
      << __FUNCTION__ << std::endl; \
  } \
  assert(rhs == lhs);

#define OPENGL_GRAPHICS_ASSERT(expression) \
  if (!expression) { \
    std::cout << "Failure on " << __LINE__ << " in " << __FILE__ << " in " \
      << __FUNCTION__ << std::endl; \
  } \
  assert(expression);

class test_base
{
public:
  ~test_base()
  {}

  virtual bool run() = 0;
  virtual const char *name() = 0;
};

#endif
