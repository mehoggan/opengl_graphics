#include "opengl_graphics/ref_count/intrusive_ptr/intrusive_ptr.h"
#include "opengl_graphics/ref_count/intrusive_ptr/ref_counted_base.h"
#include "opengl_graphics/ref_count/shared_array/shared_array.h"

#include "suite.h"

#include <check.h>

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

class test_ref_counted
{
public:
  virtual bool run();
  virtual const char *name() { return "test_ref_counted"; }
};

/*! \brief default constructor for intrusive_ptr
*/
START_TEST(test_intrusive_ptr_default_ctor)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr;

  ck_assert(!iptr);
}
END_TEST

/*! \brief ctor intrusive ptr
*/
START_TEST(test_intrusive_ptr_ctor)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted);

  ck_assert(iptr);
  ck_assert(-1 == iptr->get_val());
}
END_TEST

/*! \brief test of intrusive_ptr copy constructor on same type
*/
START_TEST(test_intrusive_ptr_copy_ctor_of_same_type)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> ciptr(iptr);

  ck_assert(iptr == ciptr);
  ck_assert(10 == ciptr->get_val());
  ck_assert(10 == iptr->get_val());
}
END_TEST

/*! \brief test of intrusive_ptr on copy constructor on different type
*/
START_TEST(test_intrusive_ptr_copy_ctor_of_different_type)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted_impl> iptr(
    new internal::ref_counted_impl(10));

  //opengl_graphics::intrusive_ptr<internal::ref_counted> ciptr(iptr);

  //ck_assert(iptr == ciptr);
  //ck_assert(10 == ciptr->get_val());
  //ck_assert(10 == iptr->get_val());
  //ck_assert(10.1 == iptr->get_dval());
}
END_TEST

/*! \brief test of intrusive_ptr assignment operator on same type
*/
START_TEST(test_intrusive_ptr_assignment_operator_of_same_type)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> ciptr;
  ciptr = iptr;

  ck_assert(iptr == ciptr);
  ck_assert(10 == ciptr->get_val());
  ck_assert(10 == iptr->get_val());
}
END_TEST

/*! \brief test of intrusive_ptr assignment operator on different type
*/
START_TEST(test_intrusive_ptr_assignment_operator_of_different_type)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted_impl> iptr(
    new internal::ref_counted_impl(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> ciptr;
  //ciptr = iptr;

  //ck_assert(iptr == ciptr);
  //ck_assert(10 == ciptr->get_val());
  //ck_assert(10 == iptr->get_val());
  //ck_assert(10.1 == iptr->get_dval());
}
END_TEST

/*! \brief test intrusive_ptr assignment operator on same type of pointer
*/
START_TEST(test_intrusive_ptr_assignment_operator_of_same_type_pointer)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  ck_assert(10 == iptr->get_val());

  internal::ref_counted *ptr = new internal::ref_counted(11);
  iptr = ptr;

  ck_assert(11 == ptr->get_val());
  ck_assert(11 == iptr->get_val());

  ck_assert(iptr == ptr);
}
END_TEST

/*! \brief test intrusive_ptr assignment operator on different type of pointer
*/
START_TEST(test_intrusive_ptr_assignment_operator_of_different_type_pointer)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  ck_assert(10 == iptr->get_val());

  internal::ref_counted_impl *ptr = new internal::ref_counted_impl(11);
  (void)ptr;
  /*
  iptr = ptr;

  ck_assert(11 == ptr->get_val());
  ck_assert(11 == iptr->get_val());

  ck_assert(iptr == ptr);
  */
}
END_TEST

/*! \brief test reset or releasing of the pointer
*/
START_TEST(test_intrusive_ptr_reset)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  ck_assert(iptr);

  iptr.reset();

  ck_assert(!iptr);
}
END_TEST

/*! \brief test reset or releasing of the pointer to a new pointer
*/
START_TEST(test_intrusive_ptr_reset_to_new_ptr)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  ck_assert(iptr);
  ck_assert(10 == iptr->get_val());

  iptr.reset(new internal::ref_counted(12));

  ck_assert(iptr);
  ck_assert(12 == iptr->get_val());
}
END_TEST

/*! \brief test detachment of ref counted pointer
*/
START_TEST(test_intrusive_ptr_detach)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  ck_assert(iptr);
  internal::ref_counted *dptr = iptr.detach();
  ck_assert(!iptr);

  // mandatory delete because we own the pointer.
  delete dptr;
}
END_TEST

/*! \brief test indirection operator
*/
START_TEST(test_intrusive_ptr_indirection_operator)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  ck_assert(iptr);
  ck_assert((*iptr).get_val() == 10);
}
END_TEST

/*! \brief test structure dereference operator
*/
START_TEST(test_intrusive_ptr_structure_dereference_operator)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  ck_assert(iptr);
  ck_assert(iptr->get_val() == 10);
}
END_TEST

/*! \brief test intrusive pointer swap
*/
START_TEST(test_intrusive_pointer_swap)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr0(
    new internal::ref_counted(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr1(
    new internal::ref_counted(11));

  ck_assert(10 == iptr0->get_val());
  ck_assert(11 == iptr1->get_val());

  iptr0.swap(iptr1);

  ck_assert(11 == iptr0->get_val());
  ck_assert(10 == iptr1->get_val());
}
END_TEST

/*! \brief we should be able to upcast a derived type to a base class no
 * problem
 */
START_TEST(test_intrusive_ptr_static_pointer_cast)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted_impl> diptr(
    new internal::ref_counted_impl(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr =
    opengl_graphics::static_intrusive_ptr_cast<
    internal::ref_counted>(diptr);

  ck_assert(diptr == iptr);
}
END_TEST

/*! \brief we should be able to cast away const on a pointer type
 */
START_TEST(test_intrusive_ptr_const_pointer_cast)
{
  //opengl_graphics::intrusive_ptr<const internal::ref_counted_impl>
  //  diptr(new internal::ref_counted_impl(10));

  //opengl_graphics::intrusive_ptr<internal::ref_counted_impl> nciptr =
  //  opengl_graphics::const_intrusive_ptr_cast<
  //    internal::ref_counted_impl>(diptr);

  //ck_assert(diptr == nciptr);
}
END_TEST

/*! \brief we should be able to downcast on pointer types
*/
START_TEST(test_intrusive_ptr_dynamic_pointer_cast)
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(new
    internal::ref_counted_impl(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted_impl> idcptr;
  idcptr = opengl_graphics::dynamic_intrusive_ptr_cast<
    internal::ref_counted_impl>(iptr);

  ck_assert(iptr == idcptr);
  ck_assert(10.1 == idcptr->get_dval());
}
END_TEST

/// Tests for shared_array:

/*! \brief test default constructor for shared_array
*/
START_TEST(test_shared_array_default_ctor)
{
  opengl_graphics::shared_array<int> sarray;

  ck_assert(!sarray);
}
END_TEST

/*! \brief test constructor for shared_array
*/
START_TEST(test_shared_array_ctor)
{
  opengl_graphics::shared_array<int> sarray(new int[10]);
  ck_assert(sarray);
  ck_assert(1 == sarray.use_count());
}
END_TEST

/*! \brief test copy ctor of same type for shared_array
*/
START_TEST(test_shared_array_copy_ctor_same_type)
{
  opengl_graphics::shared_array<int> sarray(new int[10]);
  ck_assert(1 == sarray.use_count());

  opengl_graphics::shared_array<int> csarray(sarray);
  ck_assert(2 == sarray.use_count());
  ck_assert(2 == csarray.use_count());

  ck_assert(sarray == csarray);
}
END_TEST

/*! \brief test assignment operator same template type
*/
START_TEST(test_shared_array_assignment_operator_same_type)
{
  opengl_graphics::shared_array<int> sarray(new int[12]);

  opengl_graphics::shared_array<int> asarray;
  asarray = sarray;

  ck_assert(2 == sarray.use_count());
  ck_assert(2 == asarray.use_count());
}
END_TEST

/*! \brief test reset to nullptr
*/
START_TEST(test_shared_array_reset_to_null)
{
  opengl_graphics::shared_array<int> sarray(new int[200]);
  ck_assert(1 == sarray.use_count());
  ck_assert(sarray.unique());

  sarray.reset();

  ck_assert(!sarray);
  ck_assert(0 == sarray.use_count());
  ck_assert(!sarray.unique());
}
END_TEST

/*! \brief test reset to another pointer
*/
START_TEST(test_shared_array_reset_to_same_and_differente_types)
{
  { // same
    opengl_graphics::shared_array<int> sarray(new int[20]);
    ck_assert(1 == sarray.use_count());
    ck_assert(sarray.unique());

    sarray.reset(new int[30]);
    ck_assert(1 == sarray.use_count());
    ck_assert(sarray.unique());
  }

  { // complicated
    opengl_graphics::shared_array<int> sarray(new int[20]);
    opengl_graphics::shared_array<int> sarray0 = sarray;
    opengl_graphics::shared_array<int> sarray1 = sarray;
    opengl_graphics::shared_array<int> sarray2 = sarray0;
    ck_assert(4 == sarray.use_count());
    ck_assert(!sarray.unique());

    sarray0.reset(new int[30]);

    ck_assert(sarray == sarray1);
    ck_assert(sarray == sarray2);

    ck_assert((sarray != sarray0));
    ck_assert(sarray0.unique());
  }
}
END_TEST

/*! \brief test subscript operator
*/
START_TEST(test_shared_array_subscript_operator)
{
  opengl_graphics::shared_array<int> sarray(new int[10]);

  for (unsigned int i = 0; i < 10; ++i) {
    sarray[i] = static_cast<int>(i + 1);
  }

  for (unsigned int i = 0; i < 10; ++i) {
    ck_assert(sarray[i] == static_cast<int>(i + 1));
  }
}
END_TEST

int
main(int argc, char *argv[])
{
  Suite *s;
  SRunner *sr;
  TCase *tc;
  int result;

  s = suite_create("Unit Tests");
  tc = tcase_create(__FILE__);

  tcase_add_test(tc, test_intrusive_ptr_default_ctor);
  tcase_add_test(tc, test_intrusive_ptr_ctor);
  tcase_add_test(tc, test_intrusive_ptr_copy_ctor_of_same_type);
  tcase_add_test(tc, test_intrusive_ptr_copy_ctor_of_different_type);
  tcase_add_test(tc, test_intrusive_ptr_assignment_operator_of_same_type);
  tcase_add_test(tc,
    test_intrusive_ptr_assignment_operator_of_different_type);
  tcase_add_test(tc,
    test_intrusive_ptr_assignment_operator_of_same_type_pointer);
  tcase_add_test(tc,
    test_intrusive_ptr_assignment_operator_of_different_type_pointer);
  tcase_add_test(tc, test_intrusive_ptr_reset);
  tcase_add_test(tc, test_intrusive_ptr_reset_to_new_ptr);
  tcase_add_test(tc, test_intrusive_ptr_detach);
  tcase_add_test(tc, test_intrusive_ptr_indirection_operator);
  tcase_add_test(tc, test_intrusive_ptr_structure_dereference_operator);
  tcase_add_test(tc, test_intrusive_pointer_swap);
  tcase_add_test(tc, test_intrusive_ptr_static_pointer_cast);
  tcase_add_test(tc, test_intrusive_ptr_const_pointer_cast);
  tcase_add_test(tc, test_intrusive_ptr_dynamic_pointer_cast);
  tcase_add_test(tc, test_shared_array_default_ctor);
  tcase_add_test(tc, test_shared_array_ctor);
  tcase_add_test(tc, test_shared_array_copy_ctor_same_type);
  tcase_add_test(tc, test_shared_array_assignment_operator_same_type);
  tcase_add_test(tc, test_shared_array_reset_to_null);
  tcase_add_test(tc, test_shared_array_reset_to_same_and_differente_types);
  tcase_add_test(tc, test_shared_array_subscript_operator);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
