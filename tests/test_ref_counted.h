#ifndef REF_COUNT_SMART_PTR_TESTS
#define REF_COUNT_SMART_PTR_TESTS

#include "test_base.h"

#include "ref_count/intrusive_ptr/intrusive_ptr.h"
#include "ref_count/intrusive_ptr/ref_counted_base.h"
#include "ref_count/shared_array/shared_array.h"

#include <algorithm>
#include <cstring>

namespace internal
{
  class base
  {
  private:
    int m_val;
  public:
    base() :
      m_val(-1)
    {}

    base(int val) :
      m_val(val)
    {}

    int get_val() const
    {
      return m_val;
    }
  };

  class derived : public base
  {
  private:
    int m_dval;

  public:
    derived() :
      base()
    {}

    derived(int val) :
      base(val)
    {}

    void set_dval(int val)
    {
      m_dval = val;
    }

    int get_dval() const
    {
      return m_dval;
    }
  };

  class ref_counted : public opengl_graphics::ref_counted_base
  {
  private:
    // Pointer used to test for memory leaks when deleting derived through
    // base pointer.
    int *_val;

  public:
    explicit ref_counted(int val = -1) :
      _val(new int(val))
    {}

    ~ref_counted()
    {
      delete _val;
    }

    int get_val() const
    {
      return *_val;
    }
  };

  class ref_counted_impl : public ref_counted
  {
  private:
    // Pointer used to test for memory leaks
    double *_dval;

  public:
    explicit ref_counted_impl(int val = -1) :
      ref_counted(val),
      _dval(new double(val + 0.1))
    {}

    ~ref_counted_impl()
    {
      delete _dval;
    }

    double get_dval() const
    {
      return *_dval;
    }
  };
}

class test_ref_counted : public test_base
{
public:
  virtual bool run();
  virtual const char *name() { return "test_ref_counted"; }
};

#endif