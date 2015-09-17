#include "test_ref_counted.h"

/// Tests for intrusive_ptr:

/*! \brief default constructor for intrusive_ptr
*/
void test_intrusive_ptr_default_ctor()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr;

  OPENGL_GRAPHICS_ASSERT(!iptr);
}

/*! \brief ctor intrusive ptr
*/
void test_intrusive_ptr_ctor()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted);

  OPENGL_GRAPHICS_ASSERT(iptr);
  OPENGL_GRAPHICS_ASSERT_EQ(-1, iptr->get_val());
}

/*! \brief test of intrusive_ptr copy constructor on same type
*/
void test_intrusive_ptr_copy_ctor_of_same_type()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> ciptr(iptr);

  OPENGL_GRAPHICS_ASSERT_EQ(iptr, ciptr);
  OPENGL_GRAPHICS_ASSERT_EQ(10, ciptr->get_val());
  OPENGL_GRAPHICS_ASSERT_EQ(10, iptr->get_val());
}

/*! \brief test of intrusive_ptr on copy constructor on different type
*/
void test_intrusive_ptr_copy_ctor_of_different_type()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted_impl> iptr(
    new internal::ref_counted_impl(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> ciptr(iptr);

  OPENGL_GRAPHICS_ASSERT_EQ(iptr, ciptr);
  OPENGL_GRAPHICS_ASSERT_EQ(10, ciptr->get_val());
  OPENGL_GRAPHICS_ASSERT_EQ(10, iptr->get_val());
  OPENGL_GRAPHICS_ASSERT_EQ(10.1, iptr->get_dval());
}

/*! \brief test of intrusive_ptr assignment operator on same type
*/
void test_intrusive_ptr_assignment_operator_of_same_type()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> ciptr;
  ciptr = iptr;

  OPENGL_GRAPHICS_ASSERT_EQ(iptr, ciptr);
  OPENGL_GRAPHICS_ASSERT_EQ(10, ciptr->get_val());
  OPENGL_GRAPHICS_ASSERT_EQ(10, iptr->get_val());
}

/*! \brief test of intrusive_ptr assignment operator on different type
*/
void test_intrusive_ptr_assignment_operator_of_different_type()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted_impl> iptr(
    new internal::ref_counted_impl(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> ciptr;
  ciptr = iptr;

  OPENGL_GRAPHICS_ASSERT_EQ(iptr, ciptr);
  OPENGL_GRAPHICS_ASSERT_EQ(10, ciptr->get_val());
  OPENGL_GRAPHICS_ASSERT_EQ(10, iptr->get_val());
  OPENGL_GRAPHICS_ASSERT_EQ(10.1, iptr->get_dval());
}

/*! \brief test intrusive_ptr assignment operator on same type of pointer
*/
void test_intrusive_ptr_assignment_operator_of_same_type_pointer()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  OPENGL_GRAPHICS_ASSERT_EQ(10, iptr->get_val());

  internal::ref_counted *ptr = new internal::ref_counted(11);
  iptr = ptr;

  OPENGL_GRAPHICS_ASSERT_EQ(11, ptr->get_val());
  OPENGL_GRAPHICS_ASSERT_EQ(11, iptr->get_val());

  OPENGL_GRAPHICS_ASSERT_EQ(iptr, ptr);
}

/*! \brief test intrusive_ptr assignment operator on different type of pointer
*/
void test_intrusive_ptr_assignment_operator_of_different_type_pointer()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  OPENGL_GRAPHICS_ASSERT_EQ(10, iptr->get_val());

  internal::ref_counted_impl *ptr = new internal::ref_counted_impl(11);
  iptr = ptr;

  OPENGL_GRAPHICS_ASSERT_EQ(11, ptr->get_val());
  OPENGL_GRAPHICS_ASSERT_EQ(11, iptr->get_val());

  OPENGL_GRAPHICS_ASSERT_EQ(iptr, ptr);
}

/*! \brief test reset or releasing of the pointer
*/
void test_intrusive_ptr_reset()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  OPENGL_GRAPHICS_ASSERT(iptr);

  iptr.reset();

  OPENGL_GRAPHICS_ASSERT(!iptr);
}

/*! \brief test reset or releasing of the pointer to a new pointer
*/
void test_intrusive_ptr_reset_to_new_ptr()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  OPENGL_GRAPHICS_ASSERT(iptr);
  OPENGL_GRAPHICS_ASSERT_EQ(10, iptr->get_val());

  iptr.reset(new internal::ref_counted(12));

  OPENGL_GRAPHICS_ASSERT(iptr);
  OPENGL_GRAPHICS_ASSERT_EQ(12, iptr->get_val());
}

/*! \brief test detachment of ref counted pointer
*/
void test_intrusive_ptr_detach()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  OPENGL_GRAPHICS_ASSERT(iptr);
  internal::ref_counted *dptr = iptr.detach();
  OPENGL_GRAPHICS_ASSERT(!iptr);

  // mandatory delete because we own the pointer.
  delete dptr;
}

/*! \brief test indirection operator
*/
void test_intrusive_ptr_indirection_operator()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  OPENGL_GRAPHICS_ASSERT(iptr);
  OPENGL_GRAPHICS_ASSERT_EQ((*iptr).get_val(), 10);
}

/*! \brief test structure dereference operator
*/
void test_intrusive_ptr_structure_dereference_operator()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(
    new internal::ref_counted(10));

  OPENGL_GRAPHICS_ASSERT(iptr);
  OPENGL_GRAPHICS_ASSERT_EQ(iptr->get_val(), 10);
}

/*! \brief test intrusive pointer swap
*/
void test_intrusive_pointer_swap()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr0(
    new internal::ref_counted(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr1(
    new internal::ref_counted(11));

  OPENGL_GRAPHICS_ASSERT_EQ(10, iptr0->get_val());
  OPENGL_GRAPHICS_ASSERT_EQ(11, iptr1->get_val());

  iptr0.swap(iptr1);

  OPENGL_GRAPHICS_ASSERT_EQ(11, iptr0->get_val());
  OPENGL_GRAPHICS_ASSERT_EQ(10, iptr1->get_val());
}

/*! \brief we should be able to upcast a derived type to a base class no problem
*/
void test_intrusive_ptr_static_pointer_cast()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted_impl> diptr(
    new internal::ref_counted_impl(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr =
    opengl_graphics::static_intrusive_ptr_cast<
    internal::ref_counted>(diptr);

  OPENGL_GRAPHICS_ASSERT(diptr == iptr);
}

/*! \brief we should be able to cast away const on a pointer type
*/
void test_intrusive_ptr_const_pointer_cast()
{
  //opengl_graphics::intrusive_ptr<const internal::ref_counted_impl>
  //  diptr(new internal::ref_counted_impl(10));

  //opengl_graphics::intrusive_ptr<internal::ref_counted_impl> nciptr =
  //  opengl_graphics::const_intrusive_ptr_cast<
  //    internal::ref_counted_impl>(diptr);

  //OPENGL_GRAPHICS_ASSERT(diptr == nciptr);
}

/*! \brief we should be able to downcast on pointer types
*/
void test_intrusive_ptr_dynamic_pointer_cast()
{
  opengl_graphics::intrusive_ptr<internal::ref_counted> iptr(new
    internal::ref_counted_impl(10));

  opengl_graphics::intrusive_ptr<internal::ref_counted_impl> idcptr;
  idcptr = opengl_graphics::dynamic_intrusive_ptr_cast<
    internal::ref_counted_impl>(iptr);

  OPENGL_GRAPHICS_ASSERT(iptr == idcptr);
  OPENGL_GRAPHICS_ASSERT_EQ(10.1, idcptr->get_dval());
}

/// Tests for shared_array:

/*! \brief test default constructor for shared_array
*/
void test_shared_array_default_ctor()
{
  opengl_graphics::shared_array<int> sarray;

  OPENGL_GRAPHICS_ASSERT(!sarray);
}

/*! \brief test constructor for shared_array
*/
void test_shared_array_ctor()
{
  opengl_graphics::shared_array<int> sarray(new int[10]);
  OPENGL_GRAPHICS_ASSERT(sarray);
  OPENGL_GRAPHICS_ASSERT_EQ(1, sarray.use_count());
}

/*! \brief test copy ctor of same type for shared_array
*/
void test_shared_array_copy_ctor_same_type()
{
  opengl_graphics::shared_array<int> sarray(new int[10]);
  OPENGL_GRAPHICS_ASSERT_EQ(1, sarray.use_count());

  opengl_graphics::shared_array<int> csarray(sarray);
  OPENGL_GRAPHICS_ASSERT_EQ(2, sarray.use_count());
  OPENGL_GRAPHICS_ASSERT_EQ(2, csarray.use_count());

  OPENGL_GRAPHICS_ASSERT_EQ(sarray, csarray);
}

/*! \brief test assignment operator same template type
*/
void test_shared_array_assignment_operator_same_type()
{
  opengl_graphics::shared_array<int> sarray(new int[12]);

  opengl_graphics::shared_array<int> asarray;
  asarray = sarray;

  OPENGL_GRAPHICS_ASSERT_EQ(2, sarray.use_count());
  OPENGL_GRAPHICS_ASSERT_EQ(2, asarray.use_count());
}

/*! \brief test reset to nullptr
*/
void test_shared_array_reset_to_null()
{
  opengl_graphics::shared_array<int> sarray(new int[200]);
  OPENGL_GRAPHICS_ASSERT_EQ(1, sarray.use_count());
  OPENGL_GRAPHICS_ASSERT(sarray.unique());

  sarray.reset();

  OPENGL_GRAPHICS_ASSERT(!sarray);
  OPENGL_GRAPHICS_ASSERT_EQ(0, sarray.use_count());
  OPENGL_GRAPHICS_ASSERT(!sarray.unique());
}

/*! \brief test reset to another pointer
*/
void test_shared_array_reset_to_same_and_differente_types()
{
    { // same
      opengl_graphics::shared_array<int> sarray(new int[20]);
      OPENGL_GRAPHICS_ASSERT_EQ(1, sarray.use_count());
      OPENGL_GRAPHICS_ASSERT(sarray.unique());

      sarray.reset(new int[30]);
      OPENGL_GRAPHICS_ASSERT_EQ(1, sarray.use_count());
      OPENGL_GRAPHICS_ASSERT(sarray.unique());
    }

    { // complicated
      opengl_graphics::shared_array<int> sarray(new int[20]);
      opengl_graphics::shared_array<int> sarray0 = sarray;
      opengl_graphics::shared_array<int> sarray1 = sarray;
      opengl_graphics::shared_array<int> sarray2 = sarray0;
      OPENGL_GRAPHICS_ASSERT_EQ(4, sarray.use_count());
      OPENGL_GRAPHICS_ASSERT(!sarray.unique());

      sarray0.reset(new int[30]);

      OPENGL_GRAPHICS_ASSERT_EQ(sarray, sarray1);
      OPENGL_GRAPHICS_ASSERT_EQ(sarray, sarray2);

      OPENGL_GRAPHICS_ASSERT((sarray != sarray0));
      OPENGL_GRAPHICS_ASSERT(sarray0.unique());
    }
}

/*! \brief test subscript operator
*/
void test_shared_array_subscript_operator()
{
  opengl_graphics::shared_array<int> sarray(new int[10]);

  for (unsigned int i = 0; i < 10; ++i) {
    sarray[i] = static_cast<int>(i + 1);
  }

  for (unsigned int i = 0; i < 10; ++i) {
    OPENGL_GRAPHICS_ASSERT(sarray[i] == static_cast<int>(i + 1));
  }
}

bool test_ref_counted::run()
{;
  test_intrusive_ptr_default_ctor();
  test_intrusive_ptr_ctor();
  test_intrusive_ptr_copy_ctor_of_same_type();
  test_intrusive_ptr_copy_ctor_of_different_type();
  test_intrusive_ptr_assignment_operator_of_same_type();
  test_intrusive_ptr_assignment_operator_of_different_type();
  test_intrusive_ptr_assignment_operator_of_same_type_pointer();
  test_intrusive_ptr_assignment_operator_of_different_type_pointer();
  test_intrusive_ptr_reset();
  test_intrusive_ptr_reset_to_new_ptr();
  test_intrusive_ptr_detach();
  test_intrusive_ptr_indirection_operator();
  test_intrusive_ptr_structure_dereference_operator();
  test_intrusive_pointer_swap();
  test_intrusive_ptr_static_pointer_cast();
  test_intrusive_ptr_const_pointer_cast();
  test_intrusive_ptr_dynamic_pointer_cast();
  test_shared_array_default_ctor();
  test_shared_array_ctor();
  test_shared_array_copy_ctor_same_type();
  test_shared_array_assignment_operator_same_type();
  test_shared_array_reset_to_null();
  test_shared_array_reset_to_same_and_differente_types();
  test_shared_array_subscript_operator();

  return true;
}