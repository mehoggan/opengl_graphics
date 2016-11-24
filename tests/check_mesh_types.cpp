#include "opengl_graphics/mesh_types/batch_data.h"
#include "opengl_graphics/mesh_types/batch_traits.h"
#include "opengl_graphics/mesh_types/datums/interleaved_datum_2d.h"
#include "opengl_graphics/mesh_types/datums/interleaved_datum_3d.h"
#include "opengl_graphics/mesh_types/datums/interleaved_datum_4d.h"
#include "opengl_graphics/mesh_types/datums/interleaved_datum_5d.h"
#include "opengl_graphics/mesh_types/datums/interleaved_datum_6d.h"
#include "opengl_graphics/mesh_types/datums/interleaved_datum_7d.h"
#include "opengl_graphics/mesh_types/datums/interleaved_datum_8d.h"
#include "opengl_graphics/mesh_types/datums/interleaved_datum_9d.h"
#include "opengl_graphics/mesh_types/indices.h"
#include "opengl_graphics/mesh_types/interleaved_data.h"
#include "opengl_graphics/type_traits/dimension.h"
#include "opengl_graphics/type_traits/sizeof.h"

#include "suite.h"

#include <algorithm>
#include <cstdlib>
#include <fstream>

#include <check.h>

namespace internal
{
  template <typename T1, typename T2>
  class pod_2
  {
  public:
    static const size_t dimension = 2u;
    T1 t1_;
    T2 t2_;

    pod_2() :
      t1_(),
      t2_()
    {}

    pod_2(T1 t1, T2 t2) :
      t1_(t1),
      t2_(t2)
    {}

    pod_2(const pod_2 &other) :
      t1_(other.t1_),
      t2_(other.t2_)
    {}

    pod_2 &operator=(pod_2 rhs)
    {
      std::swap(t1_, rhs.t1_);
      std::swap(t2_, rhs.t2_);

      return (*this);
    }
  };

  template <typename T1, typename T2, typename T3>
  class pod_3
  {
  public:
    static const size_t dimension = 3u;
    T1 t1_;
    T2 t2_;
    T3 t3_;

    pod_3() :
      t1_(),
      t2_(),
      t3_()
    {}

    pod_3(T1 t1, T2 t2, T3 t3) :
      t1_(t1),
      t2_(t2),
      t3_(t3)
    {}

    pod_3(const pod_3 &other) :
      t1_(other.t1_),
      t2_(other.t2_),
      t3_(other.t3_)
    {}

    pod_3 &operator=(pod_3 rhs)
    {
      std::swap(t1_, rhs.t1_);
      std::swap(t2_, rhs.t2_);
      std::swap(t3_, rhs.t3_);

      return (*this);
    }
  };

  template <typename T1, typename T2, typename T3, typename T4>
  class pod_4
  {
  public:
    static const size_t dimension = 4u;
    T1 t1_;
    T2 t2_;
    T3 t3_;
    T4 t4_;

    pod_4() :
      t1_(),
      t2_(),
      t3_(),
      t4_()
    {}

    pod_4(T1 t1, T2 t2, T3 t3, T4 t4) :
      t1_(t1),
      t2_(t2),
      t3_(t3),
      t4_(t4)
    {}

    pod_4(const pod_4 &other) :
      t1_(other.t1_),
      t2_(other.t2_),
      t3_(other.t3_),
      t4_(other.t4_)
    {}

    pod_4 &operator=(pod_4 rhs)
    {
      std::swap(t1_, rhs.t1_);
      std::swap(t2_, rhs.t2_);
      std::swap(t3_, rhs.t3_);
      std::swap(t4_, rhs.t4_);

      return (*this);
    }

  };
}

class test_mesh_types
{
  virtual bool run();
  virtual const char *name() { return "test_mesh_types"; }

public:
  // 2D datums
  typedef opengl_graphics::interleaved_datum_2d <internal::pod_2<int, int>,
    internal::pod_3<int, int, int> > id2d_2X3i;

  // 3D datums
  typedef opengl_graphics::interleaved_datum_3d <internal::pod_2<int, int>,
    internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int> >
    id3d_2X3X4i;

  // 4D datums
  typedef opengl_graphics::interleaved_datum_4d <internal::pod_2<int, int>,
    internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
    internal::pod_2<int, int> > id4d_2X3X4X2i;

  // 5D datums
  typedef opengl_graphics::interleaved_datum_5d <internal::pod_2<int, int>,
    internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
    internal::pod_2<int, int>, internal::pod_3<int, int, int> >
    id5d_2X3X4X2X3i;

  // 6D datums
  typedef opengl_graphics::interleaved_datum_6d <internal::pod_2<int, int>,
    internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
    internal::pod_2<int, int>, internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int> > id6d_2X3X4X2X3X4i;

  // 7D datums
  typedef opengl_graphics::interleaved_datum_7d <internal::pod_2<int, int>,
    internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
    internal::pod_2<int, int>, internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>, internal::pod_2<int, int> >
    id7d_2X3X4X2X3X4X2i;

  // 8D datums
  typedef opengl_graphics::interleaved_datum_8d <internal::pod_2<int, int>,
    internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
    internal::pod_2<int, int>, internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>, internal::pod_2<int, int>,
    internal::pod_3<int, int, int> >
    id8d_2X3X4X2X3X4X2X3i;

  // 9D datums
  typedef opengl_graphics::interleaved_datum_9d <internal::pod_2<int, int>,
    internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
    internal::pod_2<int, int>, internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>, internal::pod_2<int, int>,
    internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int> >
    id9d_2X3X4X2X3X4X2X3X4i;
};

/*! \brief This is a test for the default ctor in the interleaved_datum_2d
 * interleaved_datum_3d ... interleaved_datum_10d classes. To ensure
 * interleaved datum calls default constructor with defined behavior.
 */
START_TEST(test_default_interleaved_datum_2d_constructor)
{
  test_mesh_types::id2d_2X3i data;

  ck_assert(0 == data._datum1.t1_);
  ck_assert(0 == data._datum1.t2_);

  ck_assert(0 == data._datum2.t1_);
  ck_assert(0 == data._datum2.t2_);
  ck_assert(0 == data._datum2.t3_);
}
END_TEST

START_TEST(test_default_interleaved_datum_3d_constructor)
{
  test_mesh_types::id3d_2X3X4i data;

  ck_assert(0 == data._datum1.t1_);
  ck_assert(0 == data._datum1.t2_);

  ck_assert(0 == data._datum2.t1_);
  ck_assert(0 == data._datum2.t2_);
  ck_assert(0 == data._datum2.t3_);

  ck_assert(0 == data._datum3.t1_);
  ck_assert(0 == data._datum3.t2_);
  ck_assert(0 == data._datum3.t3_);
  ck_assert(0 == data._datum3.t4_);
}
END_TEST

START_TEST(test_default_interleaved_datum_4d_constructor)
{
  test_mesh_types::id4d_2X3X4X2i data;

  ck_assert(0 == data._datum1.t1_);
  ck_assert(0 == data._datum1.t2_);

  ck_assert(0 == data._datum2.t1_);
  ck_assert(0 == data._datum2.t2_);
  ck_assert(0 == data._datum2.t3_);

  ck_assert(0 == data._datum3.t1_);
  ck_assert(0 == data._datum3.t2_);
  ck_assert(0 == data._datum3.t3_);
  ck_assert(0 == data._datum3.t4_);

  ck_assert(0 == data._datum4.t1_);
  ck_assert(0 == data._datum4.t2_);
}
END_TEST

START_TEST(test_default_interleaved_datum_5d_constructor)
{
  test_mesh_types::id5d_2X3X4X2X3i data;

  ck_assert(0 == data._datum1.t1_);
  ck_assert(0 == data._datum1.t2_);

  ck_assert(0 == data._datum2.t1_);
  ck_assert(0 == data._datum2.t2_);
  ck_assert(0 == data._datum2.t3_);

  ck_assert(0 == data._datum3.t1_);
  ck_assert(0 == data._datum3.t2_);
  ck_assert(0 == data._datum3.t3_);
  ck_assert(0 == data._datum3.t4_);

  ck_assert(0 == data._datum4.t1_);
  ck_assert(0 == data._datum4.t2_);

  ck_assert(0 == data._datum5.t1_);
  ck_assert(0 == data._datum5.t2_);
  ck_assert(0 == data._datum5.t3_);
}
END_TEST

START_TEST(test_default_interleaved_datum_6d_constructor)
{
  test_mesh_types::id6d_2X3X4X2X3X4i data;

  ck_assert(0 == data._datum1.t1_);
  ck_assert(0 == data._datum1.t2_);

  ck_assert(0 == data._datum2.t1_);
  ck_assert(0 == data._datum2.t2_);
  ck_assert(0 == data._datum2.t3_);

  ck_assert(0 == data._datum3.t1_);
  ck_assert(0 == data._datum3.t2_);
  ck_assert(0 == data._datum3.t3_);
  ck_assert(0 == data._datum3.t4_);

  ck_assert(0 == data._datum4.t1_);
  ck_assert(0 == data._datum4.t2_);

  ck_assert(0 == data._datum5.t1_);
  ck_assert(0 == data._datum5.t2_);
  ck_assert(0 == data._datum5.t3_);

  ck_assert(0 == data._datum6.t1_);
  ck_assert(0 == data._datum6.t2_);
  ck_assert(0 == data._datum6.t3_);
  ck_assert(0 == data._datum6.t4_);
}
END_TEST

START_TEST(test_default_interleaved_datum_7d_constructor)
{
  test_mesh_types::id7d_2X3X4X2X3X4X2i data;

  ck_assert(0 == data._datum1.t1_);
  ck_assert(0 == data._datum1.t2_);

  ck_assert(0 == data._datum2.t1_);
  ck_assert(0 == data._datum2.t2_);
  ck_assert(0 == data._datum2.t3_);

  ck_assert(0 == data._datum3.t1_);
  ck_assert(0 == data._datum3.t2_);
  ck_assert(0 == data._datum3.t3_);
  ck_assert(0 == data._datum3.t4_);

  ck_assert(0 == data._datum4.t1_);
  ck_assert(0 == data._datum4.t2_);

  ck_assert(0 == data._datum5.t1_);
  ck_assert(0 == data._datum5.t2_);
  ck_assert(0 == data._datum5.t3_);

  ck_assert(0 == data._datum6.t1_);
  ck_assert(0 == data._datum6.t2_);
  ck_assert(0 == data._datum6.t3_);
  ck_assert(0 == data._datum6.t4_);

  ck_assert(0 == data._datum7.t1_);
  ck_assert(0 == data._datum7.t2_);
}
END_TEST

START_TEST(test_default_interleaved_datum_8d_constructor)
{
  test_mesh_types::id8d_2X3X4X2X3X4X2X3i data;

  ck_assert(0 == data._datum1.t1_);
  ck_assert(0 == data._datum1.t2_);

  ck_assert(0 == data._datum2.t1_);
  ck_assert(0 == data._datum2.t2_);
  ck_assert(0 == data._datum2.t3_);

  ck_assert(0 == data._datum3.t1_);
  ck_assert(0 == data._datum3.t2_);
  ck_assert(0 == data._datum3.t3_);
  ck_assert(0 == data._datum3.t4_);

  ck_assert(0 == data._datum4.t1_);
  ck_assert(0 == data._datum4.t2_);

  ck_assert(0 == data._datum5.t1_);
  ck_assert(0 == data._datum5.t2_);
  ck_assert(0 == data._datum5.t3_);

  ck_assert(0 == data._datum6.t1_);
  ck_assert(0 == data._datum6.t2_);
  ck_assert(0 == data._datum6.t3_);
  ck_assert(0 == data._datum6.t4_);

  ck_assert(0 == data._datum7.t1_);
  ck_assert(0 == data._datum7.t2_);

  ck_assert(0 == data._datum8.t1_);
  ck_assert(0 == data._datum8.t2_);
  ck_assert(0 == data._datum8.t3_);
}
END_TEST

START_TEST(test_default_interleaved_datum_9d_constructor)
{
  test_mesh_types::id9d_2X3X4X2X3X4X2X3X4i data;

  ck_assert(0 == data._datum1.t1_);
  ck_assert(0 == data._datum1.t2_);

  ck_assert(0 == data._datum2.t1_);
  ck_assert(0 == data._datum2.t2_);
  ck_assert(0 == data._datum2.t3_);

  ck_assert(0 == data._datum3.t1_);
  ck_assert(0 == data._datum3.t2_);
  ck_assert(0 == data._datum3.t3_);
  ck_assert(0 == data._datum3.t4_);

  ck_assert(0 == data._datum4.t1_);
  ck_assert(0 == data._datum4.t2_);

  ck_assert(0 == data._datum5.t1_);
  ck_assert(0 == data._datum5.t2_);
  ck_assert(0 == data._datum5.t3_);

  ck_assert(0 == data._datum6.t1_);
  ck_assert(0 == data._datum6.t2_);
  ck_assert(0 == data._datum6.t3_);
  ck_assert(0 == data._datum6.t4_);

  ck_assert(0 == data._datum7.t1_);
  ck_assert(0 == data._datum7.t2_);

  ck_assert(0 == data._datum8.t1_);
  ck_assert(0 == data._datum8.t2_);
  ck_assert(0 == data._datum8.t3_);

  ck_assert(0 == data._datum9.t1_);
  ck_assert(0 == data._datum9.t2_);
  ck_assert(0 == data._datum9.t3_);
  ck_assert(0 == data._datum9.t4_);
}
END_TEST

/*! \brief This is a test for the ctor in the interleaved_datum_2d
 * interleaved_datum_3d ... interleaved_datum_10d classes.
 */
START_TEST(test_interleaved_datum_2d_constructor)
{
  test_mesh_types::id2d_2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5));

  ck_assert(1 == data._datum1.t1_);
  ck_assert(2 == data._datum1.t2_);

  ck_assert(3 == data._datum2.t1_);
  ck_assert(4 == data._datum2.t2_);
  ck_assert(5 == data._datum2.t3_);
}
END_TEST

START_TEST(test_interleaved_datum_3d_constructor)
{
  test_mesh_types::id3d_2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9));

  ck_assert(1 == data._datum1.t1_);
  ck_assert(2 == data._datum1.t2_);

  ck_assert(3 == data._datum2.t1_);
  ck_assert(4 == data._datum2.t2_);
  ck_assert(5 == data._datum2.t3_);

  ck_assert(6 == data._datum3.t1_);
  ck_assert(7 == data._datum3.t2_);
  ck_assert(8 == data._datum3.t3_);
  ck_assert(9 == data._datum3.t4_);
}
END_TEST

START_TEST(test_interleaved_datum_4d_constructor)
{
  test_mesh_types::id4d_2X3X4X2i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11));

  ck_assert(1 == data._datum1.t1_);
  ck_assert(2 == data._datum1.t2_);

  ck_assert(3 == data._datum2.t1_);
  ck_assert(4 == data._datum2.t2_);
  ck_assert(5 == data._datum2.t3_);

  ck_assert(6 == data._datum3.t1_);
  ck_assert(7 == data._datum3.t2_);
  ck_assert(8 == data._datum3.t3_);
  ck_assert(9 == data._datum3.t4_);

  ck_assert(10 == data._datum4.t1_);
  ck_assert(11 == data._datum4.t2_);
}
END_TEST

START_TEST(test_interleaved_datum_5d_constructor)
{
  test_mesh_types::id5d_2X3X4X2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14));

  ck_assert(1 == data._datum1.t1_);
  ck_assert(2 == data._datum1.t2_);

  ck_assert(3 == data._datum2.t1_);
  ck_assert(4 == data._datum2.t2_);
  ck_assert(5 == data._datum2.t3_);

  ck_assert(6 == data._datum3.t1_);
  ck_assert(7 == data._datum3.t2_);
  ck_assert(8 == data._datum3.t3_);
  ck_assert(9 == data._datum3.t4_);

  ck_assert(10 == data._datum4.t1_);
  ck_assert(11 == data._datum4.t2_);

  ck_assert(12 == data._datum5.t1_);
  ck_assert(13 == data._datum5.t2_);
  ck_assert(14 == data._datum5.t3_);
}
END_TEST

START_TEST(test_interleaved_datum_6d_constructor)
{
  test_mesh_types::id6d_2X3X4X2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18));

  ck_assert(1 == data._datum1.t1_);
  ck_assert(2 == data._datum1.t2_);

  ck_assert(3 == data._datum2.t1_);
  ck_assert(4 == data._datum2.t2_);
  ck_assert(5 == data._datum2.t3_);

  ck_assert(6 == data._datum3.t1_);
  ck_assert(7 == data._datum3.t2_);
  ck_assert(8 == data._datum3.t3_);
  ck_assert(9 == data._datum3.t4_);

  ck_assert(10 == data._datum4.t1_);
  ck_assert(11 == data._datum4.t2_);

  ck_assert(12 == data._datum5.t1_);
  ck_assert(13 == data._datum5.t2_);
  ck_assert(14 == data._datum5.t3_);

  ck_assert(15 == data._datum6.t1_);
  ck_assert(16 == data._datum6.t2_);
  ck_assert(17 == data._datum6.t3_);
  ck_assert(18 == data._datum6.t4_);
}
END_TEST

START_TEST(test_interleaved_datum_7d_constructor)
{
  test_mesh_types::id7d_2X3X4X2X3X4X2i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18),
    internal::pod_2<int, int>(19, 20));

  ck_assert(1 == data._datum1.t1_);
  ck_assert(2 == data._datum1.t2_);

  ck_assert(3 == data._datum2.t1_);
  ck_assert(4 == data._datum2.t2_);
  ck_assert(5 == data._datum2.t3_);

  ck_assert(6 == data._datum3.t1_);
  ck_assert(7 == data._datum3.t2_);
  ck_assert(8 == data._datum3.t3_);
  ck_assert(9 == data._datum3.t4_);

  ck_assert(10 == data._datum4.t1_);
  ck_assert(11 == data._datum4.t2_);

  ck_assert(12 == data._datum5.t1_);
  ck_assert(13 == data._datum5.t2_);
  ck_assert(14 == data._datum5.t3_);

  ck_assert(15 == data._datum6.t1_);
  ck_assert(16 == data._datum6.t2_);
  ck_assert(17 == data._datum6.t3_);
  ck_assert(18 == data._datum6.t4_);

  ck_assert(19 == data._datum7.t1_);
  ck_assert(20 == data._datum7.t2_);
}
END_TEST

START_TEST(test_interleaved_datum_8d_constructor)
{
  test_mesh_types::id8d_2X3X4X2X3X4X2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18),
    internal::pod_2<int, int>(19, 20),
    internal::pod_3<int, int, int>(21, 22, 23));

  ck_assert(1 == data._datum1.t1_);
  ck_assert(2 == data._datum1.t2_);

  ck_assert(3 == data._datum2.t1_);
  ck_assert(4 == data._datum2.t2_);
  ck_assert(5 == data._datum2.t3_);

  ck_assert(6 == data._datum3.t1_);
  ck_assert(7 == data._datum3.t2_);
  ck_assert(8 == data._datum3.t3_);
  ck_assert(9 == data._datum3.t4_);

  ck_assert(10 == data._datum4.t1_);
  ck_assert(11 == data._datum4.t2_);

  ck_assert(12 == data._datum5.t1_);
  ck_assert(13 == data._datum5.t2_);
  ck_assert(14 == data._datum5.t3_);

  ck_assert(15 == data._datum6.t1_);
  ck_assert(16 == data._datum6.t2_);
  ck_assert(17 == data._datum6.t3_);
  ck_assert(18 == data._datum6.t4_);

  ck_assert(19 == data._datum7.t1_);
  ck_assert(20 == data._datum7.t2_);

  ck_assert(21 == data._datum8.t1_);
  ck_assert(22 == data._datum8.t2_);
  ck_assert(23 == data._datum8.t3_);
}
END_TEST

START_TEST(test_interleaved_datum_9d_constructor)
{
  test_mesh_types::id9d_2X3X4X2X3X4X2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18),
    internal::pod_2<int, int>(19, 20),
    internal::pod_3<int, int, int>(21, 22, 23),
    internal::pod_4<int, int, int, int>(24, 25, 26, 27));

  ck_assert(1 == data._datum1.t1_);
  ck_assert(2 == data._datum1.t2_);

  ck_assert(3 == data._datum2.t1_);
  ck_assert(4 == data._datum2.t2_);
  ck_assert(5 == data._datum2.t3_);

  ck_assert(6 == data._datum3.t1_);
  ck_assert(7 == data._datum3.t2_);
  ck_assert(8 == data._datum3.t3_);
  ck_assert(9 == data._datum3.t4_);

  ck_assert(10 == data._datum4.t1_);
  ck_assert(11 == data._datum4.t2_);

  ck_assert(12 == data._datum5.t1_);
  ck_assert(13 == data._datum5.t2_);
  ck_assert(14 == data._datum5.t3_);

  ck_assert(15 == data._datum6.t1_);
  ck_assert(16 == data._datum6.t2_);
  ck_assert(17 == data._datum6.t3_);
  ck_assert(18 == data._datum6.t4_);

  ck_assert(19 == data._datum7.t1_);
  ck_assert(20 == data._datum7.t2_);

  ck_assert(21 == data._datum8.t1_);
  ck_assert(22 == data._datum8.t2_);
  ck_assert(23 == data._datum8.t3_);

  ck_assert(24 == data._datum9.t1_);
  ck_assert(25 == data._datum9.t2_);
  ck_assert(26 == data._datum9.t3_);
  ck_assert(27 == data._datum9.t4_);
}
END_TEST

/*! \brief This is a test for the copy ctor in the interleaved_datum_2d
 * interleaved_datum_3d ... interleaved_datum_10d classes.
 */
START_TEST(test_interleaved_datum_2d_copy_constructor)
{
  test_mesh_types::id2d_2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5));

  test_mesh_types::id2d_2X3i data_copy(data);

  ck_assert(1 == data_copy._datum1.t1_);
  ck_assert(2 == data_copy._datum1.t2_);

  ck_assert(3 == data_copy._datum2.t1_);
  ck_assert(4 == data_copy._datum2.t2_);
  ck_assert(5 == data_copy._datum2.t3_);

  //ck_assert(data == data_copy);
  //ck_assert(!(data != data_copy));
}
END_TEST

START_TEST(test_interleaved_datum_3d_copy_constructor)
{
  test_mesh_types::id3d_2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9));

  test_mesh_types::id3d_2X3X4i data_copy(data);

  ck_assert(1 == data_copy._datum1.t1_);
  ck_assert(2 == data_copy._datum1.t2_);

  ck_assert(3 == data_copy._datum2.t1_);
  ck_assert(4 == data_copy._datum2.t2_);
  ck_assert(5 == data_copy._datum2.t3_);

  ck_assert(6 == data_copy._datum3.t1_);
  ck_assert(7 == data_copy._datum3.t2_);
  ck_assert(8 == data_copy._datum3.t3_);
  ck_assert(9 == data_copy._datum3.t4_);

  //ck_assert(data == data_copy);
  //ck_assert(!(data != data_copy));
}
END_TEST

START_TEST(test_interleaved_datum_4d_copy_constructor)
{
  test_mesh_types::id4d_2X3X4X2i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11));

  test_mesh_types::id4d_2X3X4X2i data_copy(data);

  ck_assert(1 == data_copy._datum1.t1_);
  ck_assert(2 == data_copy._datum1.t2_);

  ck_assert(3 == data_copy._datum2.t1_);
  ck_assert(4 == data_copy._datum2.t2_);
  ck_assert(5 == data_copy._datum2.t3_);

  ck_assert(6 == data_copy._datum3.t1_);
  ck_assert(7 == data_copy._datum3.t2_);
  ck_assert(8 == data_copy._datum3.t3_);
  ck_assert(9 == data_copy._datum3.t4_);

  ck_assert(10 == data_copy._datum4.t1_);
  ck_assert(11 == data_copy._datum4.t2_);

  //ck_assert(data == data_copy);
  //ck_assert(!(data != data_copy));
}
END_TEST

START_TEST(test_interleaved_datum_5d_copy_constructor)
{
  test_mesh_types::id5d_2X3X4X2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14));

  test_mesh_types::id5d_2X3X4X2X3i data_copy(data);

  ck_assert(1 == data_copy._datum1.t1_);
  ck_assert(2 == data_copy._datum1.t2_);

  ck_assert(3 == data_copy._datum2.t1_);
  ck_assert(4 == data_copy._datum2.t2_);
  ck_assert(5 == data_copy._datum2.t3_);

  ck_assert(6 == data_copy._datum3.t1_);
  ck_assert(7 == data_copy._datum3.t2_);
  ck_assert(8 == data_copy._datum3.t3_);
  ck_assert(9 == data_copy._datum3.t4_);

  ck_assert(10 == data_copy._datum4.t1_);
  ck_assert(11 == data_copy._datum4.t2_);

  ck_assert(12 == data_copy._datum5.t1_);
  ck_assert(13 == data_copy._datum5.t2_);
  ck_assert(14 == data_copy._datum5.t3_);

  //ck_assert(data == data_copy);
  //ck_assert(!(data != data_copy));
}
END_TEST

START_TEST(test_interleaved_datum_6d_copy_constructor)
{
  test_mesh_types::id6d_2X3X4X2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18));

  test_mesh_types::id6d_2X3X4X2X3X4i data_copy(data);

  ck_assert(1 == data_copy._datum1.t1_);
  ck_assert(2 == data_copy._datum1.t2_);

  ck_assert(3 == data_copy._datum2.t1_);
  ck_assert(4 == data_copy._datum2.t2_);
  ck_assert(5 == data_copy._datum2.t3_);

  ck_assert(6 == data_copy._datum3.t1_);
  ck_assert(7 == data_copy._datum3.t2_);
  ck_assert(8 == data_copy._datum3.t3_);
  ck_assert(9 == data_copy._datum3.t4_);

  ck_assert(10 == data_copy._datum4.t1_);
  ck_assert(11 == data_copy._datum4.t2_);

  ck_assert(12 == data_copy._datum5.t1_);
  ck_assert(13 == data_copy._datum5.t2_);
  ck_assert(14 == data_copy._datum5.t3_);

  ck_assert(15 == data_copy._datum6.t1_);
  ck_assert(16 == data_copy._datum6.t2_);
  ck_assert(17 == data_copy._datum6.t3_);
  ck_assert(18 == data_copy._datum6.t4_);

  //ck_assert(data == data_copy);
  //ck_assert(!(data != data_copy));
}
END_TEST

START_TEST(test_interleaved_datum_7d_copy_constructor)
{
  test_mesh_types::id7d_2X3X4X2X3X4X2i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18),
    internal::pod_2<int, int>(19, 20));

  test_mesh_types::id7d_2X3X4X2X3X4X2i data_copy(data);

  ck_assert(1 == data_copy._datum1.t1_);
  ck_assert(2 == data_copy._datum1.t2_);

  ck_assert(3 == data_copy._datum2.t1_);
  ck_assert(4 == data_copy._datum2.t2_);
  ck_assert(5 == data_copy._datum2.t3_);

  ck_assert(6 == data_copy._datum3.t1_);
  ck_assert(7 == data_copy._datum3.t2_);
  ck_assert(8 == data_copy._datum3.t3_);
  ck_assert(9 == data_copy._datum3.t4_);

  ck_assert(10 == data_copy._datum4.t1_);
  ck_assert(11 == data_copy._datum4.t2_);

  ck_assert(12 == data_copy._datum5.t1_);
  ck_assert(13 == data_copy._datum5.t2_);
  ck_assert(14 == data_copy._datum5.t3_);

  ck_assert(15 == data_copy._datum6.t1_);
  ck_assert(16 == data_copy._datum6.t2_);
  ck_assert(17 == data_copy._datum6.t3_);
  ck_assert(18 == data_copy._datum6.t4_);

  ck_assert(19 == data_copy._datum7.t1_);
  ck_assert(20 == data_copy._datum7.t2_);

  //ck_assert(data == data_copy);
  //ck_assert(!(data != data_copy));
}
END_TEST

START_TEST(test_interleaved_datum_8d_copy_constructor)
{
  test_mesh_types::id8d_2X3X4X2X3X4X2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18),
    internal::pod_2<int, int>(19, 20),
    internal::pod_3<int, int, int>(21, 22, 23));

  test_mesh_types::id8d_2X3X4X2X3X4X2X3i data_copy(data);

  ck_assert(1 == data_copy._datum1.t1_);
  ck_assert(2 == data_copy._datum1.t2_);

  ck_assert(3 == data_copy._datum2.t1_);
  ck_assert(4 == data_copy._datum2.t2_);
  ck_assert(5 == data_copy._datum2.t3_);

  ck_assert(6 == data_copy._datum3.t1_);
  ck_assert(7 == data_copy._datum3.t2_);
  ck_assert(8 == data_copy._datum3.t3_);
  ck_assert(9 == data_copy._datum3.t4_);

  ck_assert(10 == data_copy._datum4.t1_);
  ck_assert(11 == data_copy._datum4.t2_);

  ck_assert(12 == data_copy._datum5.t1_);
  ck_assert(13 == data_copy._datum5.t2_);
  ck_assert(14 == data_copy._datum5.t3_);

  ck_assert(15 == data_copy._datum6.t1_);
  ck_assert(16 == data_copy._datum6.t2_);
  ck_assert(17 == data_copy._datum6.t3_);
  ck_assert(18 == data_copy._datum6.t4_);

  ck_assert(19 == data_copy._datum7.t1_);
  ck_assert(20 == data_copy._datum7.t2_);

  ck_assert(21 == data_copy._datum8.t1_);
  ck_assert(22 == data_copy._datum8.t2_);
  ck_assert(23 == data_copy._datum8.t3_);

  //ck_assert(data == data_copy);
  //ck_assert(!(data != data_copy));
}
END_TEST

START_TEST(test_interleaved_datum_9d_copy_constructor)
{
  test_mesh_types::id9d_2X3X4X2X3X4X2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18),
    internal::pod_2<int, int>(19, 20),
    internal::pod_3<int, int, int>(21, 22, 23),
    internal::pod_4<int, int, int, int>(24, 25, 26, 27));

  test_mesh_types::id9d_2X3X4X2X3X4X2X3X4i data_copy(data);

  ck_assert(1 == data_copy._datum1.t1_);
  ck_assert(2 == data_copy._datum1.t2_);

  ck_assert(3 == data_copy._datum2.t1_);
  ck_assert(4 == data_copy._datum2.t2_);
  ck_assert(5 == data_copy._datum2.t3_);

  ck_assert(6 == data_copy._datum3.t1_);
  ck_assert(7 == data_copy._datum3.t2_);
  ck_assert(8 == data_copy._datum3.t3_);
  ck_assert(9 == data_copy._datum3.t4_);

  ck_assert(10 == data_copy._datum4.t1_);
  ck_assert(11 == data_copy._datum4.t2_);

  ck_assert(12 == data_copy._datum5.t1_);
  ck_assert(13 == data_copy._datum5.t2_);
  ck_assert(14 == data_copy._datum5.t3_);

  ck_assert(15 == data_copy._datum6.t1_);
  ck_assert(16 == data_copy._datum6.t2_);
  ck_assert(17 == data_copy._datum6.t3_);
  ck_assert(18 == data_copy._datum6.t4_);

  ck_assert(19 == data_copy._datum7.t1_);
  ck_assert(20 == data_copy._datum7.t2_);

  ck_assert(21 == data_copy._datum8.t1_);
  ck_assert(22 == data_copy._datum8.t2_);
  ck_assert(23 == data_copy._datum8.t3_);

  ck_assert(24 == data_copy._datum9.t1_);
  ck_assert(25 == data_copy._datum9.t2_);
  ck_assert(26 == data_copy._datum9.t3_);
  ck_assert(27 == data_copy._datum9.t4_);

  //ck_assert(data == data_copy);
  //ck_assert(!(data != data_copy));
}
END_TEST

/*! \brief This is a test for the assignment operator in the
 * interleaved_datum_2d interleaved_datum_3d ... interleaved_datum_10d
 * classes.
 */
START_TEST(test_interleaved_datum_2d_assignment_operator)
{
  test_mesh_types::id2d_2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5));

  test_mesh_types::id2d_2X3i data_assign = data;

  ck_assert(1 == data_assign._datum1.t1_);
  ck_assert(2 == data_assign._datum1.t2_);

  ck_assert(3 == data_assign._datum2.t1_);
  ck_assert(4 == data_assign._datum2.t2_);
  ck_assert(5 == data_assign._datum2.t3_);

  //ck_assert(data == data_assign);
  //ck_assert(!(data != data_assign));
}
END_TEST

START_TEST(test_interleaved_datum_3d_assignment_operator)
{
  test_mesh_types::id3d_2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9));

  test_mesh_types::id3d_2X3X4i data_assign = data;

  ck_assert(1 == data_assign._datum1.t1_);
  ck_assert(2 == data_assign._datum1.t2_);

  ck_assert(3 == data_assign._datum2.t1_);
  ck_assert(4 == data_assign._datum2.t2_);
  ck_assert(5 == data_assign._datum2.t3_);

  ck_assert(6 == data_assign._datum3.t1_);
  ck_assert(7 == data_assign._datum3.t2_);
  ck_assert(8 == data_assign._datum3.t3_);
  ck_assert(9 == data_assign._datum3.t4_);

  //ck_assert(data == data_assign);
  //ck_assert(!(data != data_assign));
}
END_TEST

START_TEST(test_interleaved_datum_4d_assignment_operator)
{
  test_mesh_types::id4d_2X3X4X2i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11));

  test_mesh_types::id4d_2X3X4X2i data_assign = data;

  ck_assert(1 == data_assign._datum1.t1_);
  ck_assert(2 == data_assign._datum1.t2_);

  ck_assert(3 == data_assign._datum2.t1_);
  ck_assert(4 == data_assign._datum2.t2_);
  ck_assert(5 == data_assign._datum2.t3_);

  ck_assert(6 == data_assign._datum3.t1_);
  ck_assert(7 == data_assign._datum3.t2_);
  ck_assert(8 == data_assign._datum3.t3_);
  ck_assert(9 == data_assign._datum3.t4_);

  ck_assert(10 == data_assign._datum4.t1_);
  ck_assert(11 == data_assign._datum4.t2_);

  //ck_assert(data == data_assign);
  //ck_assert(!(data != data_assign));
}
END_TEST

START_TEST(test_interleaved_datum_5d_assignment_operator)
{
  test_mesh_types::id5d_2X3X4X2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14));

  test_mesh_types::id5d_2X3X4X2X3i data_assign = data;

  ck_assert(1 == data_assign._datum1.t1_);
  ck_assert(2 == data_assign._datum1.t2_);

  ck_assert(3 == data_assign._datum2.t1_);
  ck_assert(4 == data_assign._datum2.t2_);
  ck_assert(5 == data_assign._datum2.t3_);

  ck_assert(6 == data_assign._datum3.t1_);
  ck_assert(7 == data_assign._datum3.t2_);
  ck_assert(8 == data_assign._datum3.t3_);
  ck_assert(9 == data_assign._datum3.t4_);

  ck_assert(10 == data_assign._datum4.t1_);
  ck_assert(11 == data_assign._datum4.t2_);

  ck_assert(12 == data_assign._datum5.t1_);
  ck_assert(13 == data_assign._datum5.t2_);
  ck_assert(14 == data_assign._datum5.t3_);

  //ck_assert(data == data_assign);
  //ck_assert(!(data != data_assign));
}
END_TEST

START_TEST(test_interleaved_datum_6d_assignment_operator)
{
  test_mesh_types::id6d_2X3X4X2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18));

  test_mesh_types::id6d_2X3X4X2X3X4i data_assign = data;

  ck_assert(1 == data_assign._datum1.t1_);
  ck_assert(2 == data_assign._datum1.t2_);

  ck_assert(3 == data_assign._datum2.t1_);
  ck_assert(4 == data_assign._datum2.t2_);
  ck_assert(5 == data_assign._datum2.t3_);

  ck_assert(6 == data_assign._datum3.t1_);
  ck_assert(7 == data_assign._datum3.t2_);
  ck_assert(8 == data_assign._datum3.t3_);
  ck_assert(9 == data_assign._datum3.t4_);

  ck_assert(10 == data_assign._datum4.t1_);
  ck_assert(11 == data_assign._datum4.t2_);

  ck_assert(12 == data_assign._datum5.t1_);
  ck_assert(13 == data_assign._datum5.t2_);
  ck_assert(14 == data_assign._datum5.t3_);

  ck_assert(15 == data_assign._datum6.t1_);
  ck_assert(16 == data_assign._datum6.t2_);
  ck_assert(17 == data_assign._datum6.t3_);
  ck_assert(18 == data_assign._datum6.t4_);

  //ck_assert(data == data_assign);
  //ck_assert(!(data != data_assign));
}
END_TEST

START_TEST(test_interleaved_datum_7d_assignment_operator)
{
  test_mesh_types::id7d_2X3X4X2X3X4X2i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18),
    internal::pod_2<int, int>(19, 20));

  test_mesh_types::id7d_2X3X4X2X3X4X2i data_assign = data;

  ck_assert(1 == data_assign._datum1.t1_);
  ck_assert(2 == data_assign._datum1.t2_);

  ck_assert(3 == data_assign._datum2.t1_);
  ck_assert(4 == data_assign._datum2.t2_);
  ck_assert(5 == data_assign._datum2.t3_);

  ck_assert(6 == data_assign._datum3.t1_);
  ck_assert(7 == data_assign._datum3.t2_);
  ck_assert(8 == data_assign._datum3.t3_);
  ck_assert(9 == data_assign._datum3.t4_);

  ck_assert(10 == data_assign._datum4.t1_);
  ck_assert(11 == data_assign._datum4.t2_);

  ck_assert(12 == data_assign._datum5.t1_);
  ck_assert(13 == data_assign._datum5.t2_);
  ck_assert(14 == data_assign._datum5.t3_);

  ck_assert(15 == data_assign._datum6.t1_);
  ck_assert(16 == data_assign._datum6.t2_);
  ck_assert(17 == data_assign._datum6.t3_);
  ck_assert(18 == data_assign._datum6.t4_);

  ck_assert(19 == data_assign._datum7.t1_);
  ck_assert(20 == data_assign._datum7.t2_);

  //ck_assert(data == data_assign);
  //ck_assert(!(data != data_assign));
}
END_TEST

START_TEST(test_interleaved_datum_8d_assignment_operator)
{
  test_mesh_types::id8d_2X3X4X2X3X4X2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18),
    internal::pod_2<int, int>(19, 20),
    internal::pod_3<int, int, int>(21, 22, 23));

  test_mesh_types::id8d_2X3X4X2X3X4X2X3i data_assign = data;

  ck_assert(1 == data_assign._datum1.t1_);
  ck_assert(2 == data_assign._datum1.t2_);

  ck_assert(3 == data_assign._datum2.t1_);
  ck_assert(4 == data_assign._datum2.t2_);
  ck_assert(5 == data_assign._datum2.t3_);

  ck_assert(6 == data_assign._datum3.t1_);
  ck_assert(7 == data_assign._datum3.t2_);
  ck_assert(8 == data_assign._datum3.t3_);
  ck_assert(9 == data_assign._datum3.t4_);

  ck_assert(10 == data_assign._datum4.t1_);
  ck_assert(11 == data_assign._datum4.t2_);

  ck_assert(12 == data_assign._datum5.t1_);
  ck_assert(13 == data_assign._datum5.t2_);
  ck_assert(14 == data_assign._datum5.t3_);

  ck_assert(15 == data_assign._datum6.t1_);
  ck_assert(16 == data_assign._datum6.t2_);
  ck_assert(17 == data_assign._datum6.t3_);
  ck_assert(18 == data_assign._datum6.t4_);

  ck_assert(19 == data_assign._datum7.t1_);
  ck_assert(20 == data_assign._datum7.t2_);

  ck_assert(21 == data_assign._datum8.t1_);
  ck_assert(22 == data_assign._datum8.t2_);
  ck_assert(23 == data_assign._datum8.t3_);

  //ck_assert(data == data_assign);
  //ck_assert(!(data != data_assign));
}
END_TEST

START_TEST(test_interleaved_datum_9d_assignment_operator)
{
  test_mesh_types::id9d_2X3X4X2X3X4X2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18),
    internal::pod_2<int, int>(19, 20),
    internal::pod_3<int, int, int>(21, 22, 23),
    internal::pod_4<int, int, int, int>(24, 25, 26, 27));

  test_mesh_types::id9d_2X3X4X2X3X4X2X3X4i data_assign = data;

  ck_assert(1 == data_assign._datum1.t1_);
  ck_assert(2 == data_assign._datum1.t2_);

  ck_assert(3 == data_assign._datum2.t1_);
  ck_assert(4 == data_assign._datum2.t2_);
  ck_assert(5 == data_assign._datum2.t3_);

  ck_assert(6 == data_assign._datum3.t1_);
  ck_assert(7 == data_assign._datum3.t2_);
  ck_assert(8 == data_assign._datum3.t3_);
  ck_assert(9 == data_assign._datum3.t4_);

  ck_assert(10 == data_assign._datum4.t1_);
  ck_assert(11 == data_assign._datum4.t2_);

  ck_assert(12 == data_assign._datum5.t1_);
  ck_assert(13 == data_assign._datum5.t2_);
  ck_assert(14 == data_assign._datum5.t3_);

  ck_assert(15 == data_assign._datum6.t1_);
  ck_assert(16 == data_assign._datum6.t2_);
  ck_assert(17 == data_assign._datum6.t3_);
  ck_assert(18 == data_assign._datum6.t4_);

  ck_assert(19 == data_assign._datum7.t1_);
  ck_assert(20 == data_assign._datum7.t2_);

  ck_assert(21 == data_assign._datum8.t1_);
  ck_assert(22 == data_assign._datum8.t2_);
  ck_assert(23 == data_assign._datum8.t3_);

  ck_assert(24 == data_assign._datum9.t1_);
  ck_assert(25 == data_assign._datum9.t2_);
  ck_assert(26 == data_assign._datum9.t3_);
  ck_assert(27 == data_assign._datum9.t4_);

  //ck_assert(data == data_assign);
  //ck_assert(!(data != data_assign));
}
END_TEST

START_TEST(test_batch_data_default_ctor)
{
  // 1 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>
  > batch1;
  ck_assert(!batch1.get_data1());

  // 2 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>
  > batch2;
  ck_assert(!batch2.get_data1());
  ck_assert(!batch2.get_data2());

  // 3 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>
  > batch3;
  ck_assert(!batch3.get_data1());
  ck_assert(!batch3.get_data2());
  ck_assert(!batch3.get_data3());

  // 4 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>
  > batch4;
  ck_assert(!batch4.get_data1());
  ck_assert(!batch4.get_data2());
  ck_assert(!batch4.get_data3());
  ck_assert(!batch4.get_data4());

  // 5 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>
  > batch5;
  ck_assert(!batch5.get_data1());
  ck_assert(!batch5.get_data2());
  ck_assert(!batch5.get_data3());
  ck_assert(!batch5.get_data4());
  ck_assert(!batch5.get_data5());

  // 6 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>
  > batch6;
  ck_assert(!batch6.get_data1());
  ck_assert(!batch6.get_data2());
  ck_assert(!batch6.get_data3());
  ck_assert(!batch6.get_data4());
  ck_assert(!batch6.get_data5());
  ck_assert(!batch6.get_data6());

  // 7 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>
  > batch7;
  ck_assert(!batch7.get_data1());
  ck_assert(!batch7.get_data2());
  ck_assert(!batch7.get_data3());
  ck_assert(!batch7.get_data4());
  ck_assert(!batch7.get_data5());
  ck_assert(!batch7.get_data6());
  ck_assert(!batch7.get_data7());

  // 8 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>
  > batch8;
  ck_assert(!batch8.get_data1());
  ck_assert(!batch8.get_data2());
  ck_assert(!batch8.get_data3());
  ck_assert(!batch8.get_data4());
  ck_assert(!batch8.get_data5());
  ck_assert(!batch8.get_data6());
  ck_assert(!batch8.get_data7());
  ck_assert(!batch8.get_data8());

  // 9 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>
  > batch9;
  ck_assert(!batch9.get_data1());
  ck_assert(!batch9.get_data2());
  ck_assert(!batch9.get_data3());
  ck_assert(!batch9.get_data4());
  ck_assert(!batch9.get_data5());
  ck_assert(!batch9.get_data6());
  ck_assert(!batch9.get_data7());
  ck_assert(!batch9.get_data8());
  ck_assert(!batch9.get_data9());
}
END_TEST

START_TEST(test_batch_data_ctor)
{
  { // 1 attribute
    opengl_graphics::batch_data<internal::pod_2<int, int> >::collection1_type
      data1(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data<internal::pod_2<int, int> > batch(data1, 10);
    ck_assert(batch.get_data1());
  }

  { // 2 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, 10);
    ck_assert(batch.get_data1());
    ck_assert(batch.get_data2());
  }

  { // 3 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3, 10);
    ck_assert(batch.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch.get_data3());
  }

  { // 4 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3, data4, 10);
    ck_assert(batch.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch.get_data4());
  }

  { // 5 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3, data4, data5, 10);
    ck_assert(batch.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch.get_data5());
  }

  { // 6 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3, data4, data5, data6, 10);
    ck_assert(batch.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch.get_data6());
  }

  { // 7 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection7_type data7(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3, data4, data5, data6, data7, 10);
    ck_assert(batch.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch.get_data7());
  }

  { // 8 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection7_type data7(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection8_type data8(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, data6,
      data7, data8, 10);
    ck_assert(batch.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch.get_data7());
    ck_assert(batch.get_data8());
  }

  { // 9 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection7_type data7(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection8_type data8(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection9_type data9(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, data6,
      data7, data8, data9,
      10);
    ck_assert(batch.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch.get_data7());
    ck_assert(batch.get_data8());
    ck_assert(batch.get_data9());
  }
}
END_TEST

START_TEST(test_batch_data_copy_ctor)
{
  { // 1 attribute
    opengl_graphics::batch_data<internal::pod_2<int, int> >::collection1_type
      data1(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data<internal::pod_2<int, int> > batch(
      data1, 10);
    opengl_graphics::batch_data<internal::pod_2<int, int> > batch_cpy(batch);
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data1() == batch_cpy.get_data1());
  }

  { // 2 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy(batch);
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
  }

  { // 3 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy(batch);
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
  }

  { // 4 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy(batch);
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
  }

  { // 5 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy(batch);
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch_cpy.get_data5());
  }

  { // 6 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, data6, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy(batch);
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch_cpy.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch_cpy.get_data6());
  }

  { // 7 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection7_type data7(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, data6,
      data7,  10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy(batch);
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch_cpy.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch_cpy.get_data6());
    ck_assert(batch.get_data7());
    ck_assert(batch_cpy.get_data7());
  }

  { // 8 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection7_type data7(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection8_type data8(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, data6,
      data7, data8, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy(batch);
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch_cpy.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch_cpy.get_data6());
    ck_assert(batch.get_data7());
    ck_assert(batch_cpy.get_data7());
    ck_assert(batch.get_data8());
    ck_assert(batch_cpy.get_data8());
  }

  { // 9 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection7_type data7(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection8_type data8(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection9_type data9(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3, data4, data5, data6,
      data7, data8, data9, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy(batch);
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch_cpy.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch_cpy.get_data6());
    ck_assert(batch.get_data7());
    ck_assert(batch_cpy.get_data7());
    ck_assert(batch.get_data8());
    ck_assert(batch_cpy.get_data8());
    ck_assert(batch.get_data9());
    ck_assert(batch_cpy.get_data9());
  }
}
END_TEST

START_TEST(test_batch_data_assignment_opperator)
{
  { // 1 attribute
    opengl_graphics::batch_data<internal::pod_2<int, int> >::collection1_type
      data1(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data<internal::pod_2<int, int> > batch(
      data1, 10);
    opengl_graphics::batch_data<internal::pod_2<int, int> > batch_cpy;
    batch_cpy = batch;
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
  }

  { // 2 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy;
    batch_cpy = batch;
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
  }

  { // 3 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy;
    batch_cpy = batch;
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
  }

  { // 4 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy;
    batch_cpy = batch;
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
  }

  { // 5 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy;
    batch_cpy = batch;
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch_cpy.get_data5());
  }

  { // 6 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, data6, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy;
    batch_cpy = batch;
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch_cpy.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch_cpy.get_data6());
  }

  { // 7 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection7_type data7(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
    data4, data5, data6,
    data7, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy;
    batch_cpy = batch;
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch_cpy.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch_cpy.get_data6());
    ck_assert(batch.get_data7());
    ck_assert(batch_cpy.get_data7());
  }

  { // 8 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection7_type data7(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection8_type data8(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, data6,
      data7, data8, 10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy;
    batch_cpy = batch;
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch_cpy.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch_cpy.get_data6());
    ck_assert(batch.get_data7());
    ck_assert(batch_cpy.get_data7());
    ck_assert(batch.get_data8());
    ck_assert(batch_cpy.get_data8());
  }

  { // 9 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection7_type data7(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection8_type data8(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection9_type data9(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, data6,
      data7, data8, data9,
      10);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_cpy;
    batch_cpy = batch;
    ck_assert(batch.get_data1());
    ck_assert(batch_cpy.get_data1());
    ck_assert(batch.get_data2());
    ck_assert(batch_cpy.get_data2());
    ck_assert(batch.get_data3());
    ck_assert(batch_cpy.get_data3());
    ck_assert(batch.get_data4());
    ck_assert(batch_cpy.get_data4());
    ck_assert(batch.get_data5());
    ck_assert(batch_cpy.get_data5());
    ck_assert(batch.get_data6());
    ck_assert(batch_cpy.get_data6());
    ck_assert(batch.get_data7());
    ck_assert(batch_cpy.get_data7());
    ck_assert(batch.get_data8());
    ck_assert(batch_cpy.get_data8());
    ck_assert(batch.get_data9());
    ck_assert(batch_cpy.get_data9());
  }
}
END_TEST

START_TEST(test_batch_data_get_byte_counts)
{
  const size_t pod2_size = sizeof(internal::pod_2<int, int>);
  const size_t pod3_size = sizeof(internal::pod_3<int, int, int>);
  const size_t pod4_size = sizeof(internal::pod_4<int, int, int, int>);
  { // 1 attribute
    opengl_graphics::batch_data<internal::pod_2<int, int> >::collection1_type
      data1(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data<internal::pod_2<int, int> > batch_empty;
    ck_assert(0 == batch_empty.get_bytecount_1());
    opengl_graphics::batch_data<internal::pod_2<int, int> > batch(
      data1, 10);
    ck_assert(10 * pod2_size == batch.get_bytecount_1());
  }

  { // 2 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
    >::collection2_type data2(new internal::pod_3<int, int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
    > batch_empty;
    ck_assert(0 == batch_empty.get_bytecount_1());
    ck_assert(0 == batch_empty.get_bytecount_2());
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
    > batch(data1, data2, 10);
    ck_assert(10 * pod2_size == batch.get_bytecount_1());
    ck_assert(10 * pod3_size == batch.get_bytecount_2());
  }

  { // 3 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>
    >::collection3_type data3(new internal::pod_4<int, int, int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_empty;
    ck_assert(0 == batch_empty.get_bytecount_1());
    ck_assert(0 == batch_empty.get_bytecount_2());
    ck_assert(0 == batch_empty.get_bytecount_3());
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>
    > batch(data1, data2, data3, 10);
    ck_assert(10 * pod2_size == batch.get_bytecount_1());
    ck_assert(10 * pod2_size == batch.get_bytecount_2());
    ck_assert(10 * pod4_size == batch.get_bytecount_3());
  }

  { // 4 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_3<int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>
    > batch_empty;
    ck_assert(0 == batch_empty.get_bytecount_1());
    ck_assert(0 == batch_empty.get_bytecount_2());
    ck_assert(0 == batch_empty.get_bytecount_3());
    ck_assert(0 == batch_empty.get_bytecount_4());
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, 10);
    ck_assert(10 * pod2_size == batch.get_bytecount_1());
    ck_assert(10 * pod4_size == batch.get_bytecount_2());
    ck_assert(10 * pod3_size == batch.get_bytecount_3());
    ck_assert(10 * pod2_size == batch.get_bytecount_4());
  }

  { // 5 attribute
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_3<int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
    > batch_empty;
    ck_assert(0 == batch_empty.get_bytecount_1());
    ck_assert(0 == batch_empty.get_bytecount_2());
    ck_assert(0 == batch_empty.get_bytecount_3());
    ck_assert(0 == batch_empty.get_bytecount_4());
    ck_assert(0 == batch_empty.get_bytecount_5());
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, 10);
    ck_assert(10 * pod4_size == batch.get_bytecount_1());
    ck_assert(10 * pod3_size == batch.get_bytecount_2());
    ck_assert(10 * pod2_size == batch.get_bytecount_3());
    ck_assert(10 * pod4_size == batch.get_bytecount_4());
    ck_assert(10 * pod2_size == batch.get_bytecount_5());
  }

  { // 6 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_3<int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_empty;
    ck_assert(0 == batch_empty.get_bytecount_1());
    ck_assert(0 == batch_empty.get_bytecount_2());
    ck_assert(0 == batch_empty.get_bytecount_3());
    ck_assert(0 == batch_empty.get_bytecount_4());
    ck_assert(0 == batch_empty.get_bytecount_5());
    ck_assert(0 == batch_empty.get_bytecount_6());
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, data6, 10);
    ck_assert(10 * pod2_size == batch.get_bytecount_1());
    ck_assert(10 * pod2_size == batch.get_bytecount_2());
    ck_assert(10 * pod2_size == batch.get_bytecount_3());
    ck_assert(10 * pod3_size == batch.get_bytecount_4());
    ck_assert(10 * pod2_size == batch.get_bytecount_5());
    ck_assert(10 * pod2_size == batch.get_bytecount_6());
  }

  { // 7 attribute
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection1_type data1(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection2_type data2(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection3_type data3(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection4_type data4(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection5_type data5(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection6_type data6(new internal::pod_2<int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    >::collection7_type data7(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch_empty;
    ck_assert(0 == batch_empty.get_bytecount_1());
    ck_assert(0 == batch_empty.get_bytecount_2());
    ck_assert(0 == batch_empty.get_bytecount_3());
    ck_assert(0 == batch_empty.get_bytecount_4());
    ck_assert(0 == batch_empty.get_bytecount_5());
    ck_assert(0 == batch_empty.get_bytecount_6());
    ck_assert(0 == batch_empty.get_bytecount_7());
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, data6,
      data7, 10);
    ck_assert(10 * pod2_size == batch.get_bytecount_1());
    ck_assert(10 * pod2_size == batch.get_bytecount_2());
    ck_assert(10 * pod2_size == batch.get_bytecount_3());
    ck_assert(10 * pod2_size == batch.get_bytecount_4());
    ck_assert(10 * pod2_size == batch.get_bytecount_5());
    ck_assert(10 * pod2_size == batch.get_bytecount_6());
    ck_assert(10 * pod2_size == batch.get_bytecount_7());
  }

  { // 8 attribute
    opengl_graphics::batch_data
    <
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>
    >::collection1_type data1(new internal::pod_3<int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>
    >::collection2_type data2(new internal::pod_3<int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>
    >::collection3_type data3(new internal::pod_3<int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>
    >::collection4_type data4(new internal::pod_3<int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>
    >::collection5_type data5(new internal::pod_3<int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>
    >::collection6_type data6(new internal::pod_3<int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>
    >::collection7_type data7(new internal::pod_3<int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>
    >::collection8_type data8(new internal::pod_3<int, int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>
    > batch_empty;
    ck_assert(0 == batch_empty.get_bytecount_1());
    ck_assert(0 == batch_empty.get_bytecount_2());
    ck_assert(0 == batch_empty.get_bytecount_3());
    ck_assert(0 == batch_empty.get_bytecount_4());
    ck_assert(0 == batch_empty.get_bytecount_5());
    ck_assert(0 == batch_empty.get_bytecount_6());
    ck_assert(0 == batch_empty.get_bytecount_7());
    ck_assert(0 == batch_empty.get_bytecount_8());
    opengl_graphics::batch_data
    <
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_3<int, int, int>
    > batch(data1, data2, data3,
      data4, data5, data6,
      data7, data8, 10);
    ck_assert(10 * pod3_size == batch.get_bytecount_1());
    ck_assert(10 * pod3_size == batch.get_bytecount_2());
    ck_assert(10 * pod3_size == batch.get_bytecount_3());
    ck_assert(10 * pod3_size == batch.get_bytecount_4());
    ck_assert(10 * pod3_size == batch.get_bytecount_5());
    ck_assert(10 * pod3_size == batch.get_bytecount_6());
    ck_assert(10 * pod3_size == batch.get_bytecount_7());
    ck_assert(10 * pod3_size == batch.get_bytecount_8());
  }

  { // 9 attribute
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    >::collection1_type data1(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    >::collection2_type data2(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    >::collection3_type data3(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    >::collection4_type data4(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    >::collection5_type data5(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    >::collection6_type data6(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    >::collection7_type data7(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    >::collection8_type data8(new internal::pod_4<int, int, int, int>[10]);
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    >::collection9_type data9(new internal::pod_4<int, int, int, int>[10]);

    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    > batch_empty;
    ck_assert(0 == batch_empty.get_bytecount_1());
    ck_assert(0 == batch_empty.get_bytecount_2());
    ck_assert(0 == batch_empty.get_bytecount_3());
    ck_assert(0 == batch_empty.get_bytecount_4());
    ck_assert(0 == batch_empty.get_bytecount_5());
    ck_assert(0 == batch_empty.get_bytecount_6());
    ck_assert(0 == batch_empty.get_bytecount_7());
    ck_assert(0 == batch_empty.get_bytecount_8());
    ck_assert(0 == batch_empty.get_bytecount_9());
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_4<int, int, int, int>
    > batch(data1, data2, data3,
      data4, data5, data6,
      data7, data8, data9, 10);
    ck_assert(10 * pod4_size == batch.get_bytecount_1());
    ck_assert(10 * pod4_size == batch.get_bytecount_2());
    ck_assert(10 * pod4_size == batch.get_bytecount_3());
    ck_assert(10 * pod4_size == batch.get_bytecount_4());
    ck_assert(10 * pod4_size == batch.get_bytecount_5());
    ck_assert(10 * pod4_size == batch.get_bytecount_6());
    ck_assert(10 * pod4_size == batch.get_bytecount_7());
    ck_assert(10 * pod4_size == batch.get_bytecount_8());
    ck_assert(10 * pod4_size == batch.get_bytecount_9());
  }
}
END_TEST

// interleaved_data unit tests
START_TEST(test_interleaved_data_default_ctor)
{
  { // 2 attributes
    typedef opengl_graphics::interleaved_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
    > interleaved2;
    interleaved2 data;
    ck_assert(!(data.get_data().get()));
    ck_assert(0 == data.get_attribute_count());
    ck_assert(0 == data.get_byte_count());
    ck_assert(8 == interleaved2::traits::type1_sizeof);
    ck_assert(12 == interleaved2::traits::type2_sizeof);
    ck_assert(20 == interleaved2::traits::stride);
    ck_assert(2 == interleaved2::traits::type1_dimension);
    ck_assert(3 == interleaved2::traits::type2_dimension);
    ck_assert(5 == interleaved2::traits::attribute_val_count);
    ck_assert(0 == interleaved2::traits::type1_byte_offset);
    ck_assert(8 == interleaved2::traits::type2_byte_offset);
  }

  { // 3 attributes
    typedef opengl_graphics::interleaved_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
    > interleaved3;
    interleaved3 data;
    ck_assert(!(data.get_data().get()));
    ck_assert(0 == data.get_attribute_count());
    ck_assert(0 == data.get_byte_count());
    ck_assert(8 == interleaved3::traits::type1_sizeof);
    ck_assert(12 == interleaved3::traits::type2_sizeof);
    ck_assert(16 == interleaved3::traits::type3_sizeof);
    ck_assert(36 == interleaved3::traits::stride);
    ck_assert(2 == interleaved3::traits::type1_dimension);
    ck_assert(3 == interleaved3::traits::type2_dimension);
    ck_assert(4 == interleaved3::traits::type3_dimension);
    ck_assert(9 == interleaved3::traits::attribute_val_count);
    ck_assert(0 == interleaved3::traits::type1_byte_offset);
    ck_assert(8 == interleaved3::traits::type2_byte_offset);
    ck_assert(20 == interleaved3::traits::type3_byte_offset);
  }

  { // 4 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>
      > interleaved4;
    interleaved4 data;
    ck_assert(!(data.get_data().get()));
    ck_assert(0 == data.get_attribute_count());
    ck_assert(0 == data.get_byte_count());
    ck_assert(8 == interleaved4::traits::type1_sizeof);
    ck_assert(12 == interleaved4::traits::type2_sizeof);
    ck_assert(16 == interleaved4::traits::type3_sizeof);
    ck_assert(12 == interleaved4::traits::type4_sizeof);
    ck_assert(48 == interleaved4::traits::stride);
    ck_assert(2 == interleaved4::traits::type1_dimension);
    ck_assert(3 == interleaved4::traits::type2_dimension);
    ck_assert(4 == interleaved4::traits::type3_dimension);
    ck_assert(3 == interleaved4::traits::type4_dimension);
    ck_assert(12 == interleaved4::traits::attribute_val_count);
    ck_assert(0 == interleaved4::traits::type1_byte_offset);
    ck_assert(8 == interleaved4::traits::type2_byte_offset);
    ck_assert(20 == interleaved4::traits::type3_byte_offset);
    ck_assert(36 == interleaved4::traits::type4_byte_offset);
  }

  { // 5 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
      > interleaved5;
    interleaved5 data;
    ck_assert(!(data.get_data().get()));
    ck_assert(0 == data.get_attribute_count());
    ck_assert(0 == data.get_byte_count());
    ck_assert(8 == interleaved5::traits::type1_sizeof);
    ck_assert(12 == interleaved5::traits::type2_sizeof);
    ck_assert(16 == interleaved5::traits::type3_sizeof);
    ck_assert(12 == interleaved5::traits::type4_sizeof);
    ck_assert(16 == interleaved5::traits::type5_sizeof);
    ck_assert(64 == interleaved5::traits::stride);
    ck_assert(2 == interleaved5::traits::type1_dimension);
    ck_assert(3 == interleaved5::traits::type2_dimension);
    ck_assert(4 == interleaved5::traits::type3_dimension);
    ck_assert(3 == interleaved5::traits::type4_dimension);
    ck_assert(4 == interleaved5::traits::type5_dimension);
    ck_assert(16 == interleaved5::traits::attribute_val_count);
    ck_assert(0 == interleaved5::traits::type1_byte_offset);
    ck_assert(8 == interleaved5::traits::type2_byte_offset);
    ck_assert(20 == interleaved5::traits::type3_byte_offset);
    ck_assert(36 == interleaved5::traits::type4_byte_offset);
    ck_assert(48 == interleaved5::traits::type5_byte_offset);
  }

  { // 6 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
      > interleaved6;
    interleaved6 data;
    ck_assert(!(data.get_data().get()));
    ck_assert(0 == data.get_attribute_count());
    ck_assert(0 == data.get_byte_count());
    ck_assert(8 == interleaved6::traits::type1_sizeof);
    ck_assert(12 == interleaved6::traits::type2_sizeof);
    ck_assert(16 == interleaved6::traits::type3_sizeof);
    ck_assert(12 == interleaved6::traits::type4_sizeof);
    ck_assert(16 == interleaved6::traits::type5_sizeof);
    ck_assert(8 == interleaved6::traits::type6_sizeof);
    ck_assert(72 == interleaved6::traits::stride);
    ck_assert(2 == interleaved6::traits::type1_dimension);
    ck_assert(3 == interleaved6::traits::type2_dimension);
    ck_assert(4 == interleaved6::traits::type3_dimension);
    ck_assert(3 == interleaved6::traits::type4_dimension);
    ck_assert(4 == interleaved6::traits::type5_dimension);
    ck_assert(2 == interleaved6::traits::type6_dimension);
    ck_assert(18 == interleaved6::traits::attribute_val_count);
    ck_assert(0 == interleaved6::traits::type1_byte_offset);
    ck_assert(8 == interleaved6::traits::type2_byte_offset);
    ck_assert(20 == interleaved6::traits::type3_byte_offset);
    ck_assert(36 == interleaved6::traits::type4_byte_offset);
    ck_assert(48 == interleaved6::traits::type5_byte_offset);
    ck_assert(64 == interleaved6::traits::type6_byte_offset);
  }

  { // 7 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
      > interleaved7;
    interleaved7 data;
    ck_assert(!(data.get_data().get()));
    ck_assert(0 == data.get_attribute_count());
    ck_assert(0 == data.get_byte_count());
    ck_assert(8 == interleaved7::traits::type1_sizeof);
    ck_assert(12 == interleaved7::traits::type2_sizeof);
    ck_assert(16 == interleaved7::traits::type3_sizeof);
    ck_assert(12 == interleaved7::traits::type4_sizeof);
    ck_assert(16 == interleaved7::traits::type5_sizeof);
    ck_assert(8 == interleaved7::traits::type6_sizeof);
    ck_assert(12 == interleaved7::traits::type7_sizeof);
    ck_assert(84 == interleaved7::traits::stride);
    ck_assert(2 == interleaved7::traits::type1_dimension);
    ck_assert(3 == interleaved7::traits::type2_dimension);
    ck_assert(4 == interleaved7::traits::type3_dimension);
    ck_assert(3 == interleaved7::traits::type4_dimension);
    ck_assert(4 == interleaved7::traits::type5_dimension);
    ck_assert(2 == interleaved7::traits::type6_dimension);
    ck_assert(3 == interleaved7::traits::type7_dimension);
    ck_assert(21 == interleaved7::traits::attribute_val_count);
    ck_assert(0 == interleaved7::traits::type1_byte_offset);
    ck_assert(8 == interleaved7::traits::type2_byte_offset);
    ck_assert(20 == interleaved7::traits::type3_byte_offset);
    ck_assert(36 == interleaved7::traits::type4_byte_offset);
    ck_assert(48 == interleaved7::traits::type5_byte_offset);
    ck_assert(64 == interleaved7::traits::type6_byte_offset);
    ck_assert(72 == interleaved7::traits::type7_byte_offset);
  }

  { // 8 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
      > interleaved8;
    interleaved8 data;
    ck_assert(!(data.get_data().get()));
    ck_assert(0 == data.get_attribute_count());
    ck_assert(0 == data.get_byte_count());
    ck_assert(8 == interleaved8::traits::type1_sizeof);
    ck_assert(12 == interleaved8::traits::type2_sizeof);
    ck_assert(16 == interleaved8::traits::type3_sizeof);
    ck_assert(12 == interleaved8::traits::type4_sizeof);
    ck_assert(16 == interleaved8::traits::type5_sizeof);
    ck_assert(8 == interleaved8::traits::type6_sizeof);
    ck_assert(12 == interleaved8::traits::type7_sizeof);
    ck_assert(16 == interleaved8::traits::type8_sizeof);
    ck_assert(100 == interleaved8::traits::stride);
    ck_assert(2 == interleaved8::traits::type1_dimension);
    ck_assert(3 == interleaved8::traits::type2_dimension);
    ck_assert(4 == interleaved8::traits::type3_dimension);
    ck_assert(3 == interleaved8::traits::type4_dimension);
    ck_assert(4 == interleaved8::traits::type5_dimension);
    ck_assert(2 == interleaved8::traits::type6_dimension);
    ck_assert(3 == interleaved8::traits::type7_dimension);
    ck_assert(4 == interleaved8::traits::type8_dimension);
    ck_assert(25 == interleaved8::traits::attribute_val_count);
    ck_assert(0 == interleaved8::traits::type1_byte_offset);
    ck_assert(8 == interleaved8::traits::type2_byte_offset);
    ck_assert(20 == interleaved8::traits::type3_byte_offset);
    ck_assert(36 == interleaved8::traits::type4_byte_offset);
    ck_assert(48 == interleaved8::traits::type5_byte_offset);
    ck_assert(64 == interleaved8::traits::type6_byte_offset);
    ck_assert(72 == interleaved8::traits::type7_byte_offset);
    ck_assert(84 == interleaved8::traits::type8_byte_offset);
  }

  { // 9 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
      > interleaved9;
    interleaved9 data;
    ck_assert(!(data.get_data().get()));
    ck_assert(0 == data.get_attribute_count());
    ck_assert(0 == data.get_byte_count());
    ck_assert(8 == interleaved9::traits::type1_sizeof);
    ck_assert(12 == interleaved9::traits::type2_sizeof);
    ck_assert(16 == interleaved9::traits::type3_sizeof);
    ck_assert(12 == interleaved9::traits::type4_sizeof);
    ck_assert(16 == interleaved9::traits::type5_sizeof);
    ck_assert(8 == interleaved9::traits::type6_sizeof);
    ck_assert(12 == interleaved9::traits::type7_sizeof);
    ck_assert(16 == interleaved9::traits::type8_sizeof);
    ck_assert(8 == interleaved9::traits::type9_sizeof);
    ck_assert(108 == interleaved9::traits::stride);
    ck_assert(2 == interleaved9::traits::type1_dimension);
    ck_assert(3 == interleaved9::traits::type2_dimension);
    ck_assert(4 == interleaved9::traits::type3_dimension);
    ck_assert(3 == interleaved9::traits::type4_dimension);
    ck_assert(4 == interleaved9::traits::type5_dimension);
    ck_assert(2 == interleaved9::traits::type6_dimension);
    ck_assert(3 == interleaved9::traits::type7_dimension);
    ck_assert(4 == interleaved9::traits::type8_dimension);
    ck_assert(2 == interleaved9::traits::type9_dimension);
    ck_assert(27 == interleaved9::traits::attribute_val_count);
    ck_assert(0 == interleaved9::traits::type1_byte_offset);
    ck_assert(8 == interleaved9::traits::type2_byte_offset);
    ck_assert(20 == interleaved9::traits::type3_byte_offset);
    ck_assert(36 == interleaved9::traits::type4_byte_offset);
    ck_assert(48 == interleaved9::traits::type5_byte_offset);
    ck_assert(64 == interleaved9::traits::type6_byte_offset);
    ck_assert(72 == interleaved9::traits::type7_byte_offset);
    ck_assert(84 == interleaved9::traits::type8_byte_offset);
    ck_assert(100 == interleaved9::traits::type9_byte_offset);
  }
}
END_TEST

START_TEST(test_interleaved_data_ctor)
{
  { // 2 attributes
    typedef opengl_graphics::interleaved_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
    > interleaved2;
    interleaved2::collection_type idata(new interleaved2::datum_type[10]);
    interleaved2 data(idata, 10);
    ck_assert((data.get_data().get()));
    ck_assert(10 == data.get_attribute_count());
    ck_assert(200 == data.get_byte_count());
  }

  { // 3 attributes
    typedef opengl_graphics::interleaved_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
    > interleaved3;
    interleaved3::collection_type idata(new interleaved3::datum_type[20]);
    interleaved3 data(idata, 20);
    ck_assert((data.get_data().get()));
    ck_assert(20 == data.get_attribute_count());
    ck_assert(720 == data.get_byte_count());
  }

  { // 4 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>
      > interleaved4;
    interleaved4::collection_type idata(new interleaved4::datum_type[15]);
    interleaved4 data(idata, 15);
    ck_assert((data.get_data().get()));
    ck_assert(15 == data.get_attribute_count());
    ck_assert(720 == data.get_byte_count());
  }

  { // 5 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
      > interleaved5;
    interleaved5::collection_type idata(new interleaved5::datum_type[2]);
    interleaved5 data(idata, 2);
    ck_assert(data.get_data().get());
    ck_assert(2 == data.get_attribute_count());
    ck_assert(128 == data.get_byte_count());
  }

  { // 6 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
      > interleaved6;
    interleaved6::collection_type idata(new interleaved6::datum_type[500]);
    interleaved6 data(idata, 500);
    ck_assert((data.get_data().get()));
    ck_assert(500 == data.get_attribute_count());
    ck_assert(36000 == data.get_byte_count());
  }

  { // 7 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
      > interleaved7;
    interleaved7::collection_type idata(new interleaved7::datum_type[33]);
    interleaved7 data(idata, 33);
    ck_assert((data.get_data().get()));
    ck_assert(33 == data.get_attribute_count());
    ck_assert(2772 == data.get_byte_count());
  }

  { // 8 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
      > interleaved8;
    interleaved8::collection_type idata(new interleaved8::datum_type[96]);
    interleaved8 data(idata, 96);
    ck_assert((data.get_data().get()));
    ck_assert(96 == data.get_attribute_count());
    ck_assert(9600 == data.get_byte_count());
  }

  { // 9 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
      > interleaved9;
    interleaved9::collection_type idata(new interleaved9::datum_type[1333]);
    interleaved9 data(idata, 1333);
    ck_assert((data.get_data().get()));
    ck_assert(1333 == data.get_attribute_count());
    ck_assert(143964 == data.get_byte_count());
  }
}
END_TEST

START_TEST(test_interleaved_data_copy_ctor)
{
  { // 2 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
      > interleaved2;
    interleaved2::collection_type idata(new interleaved2::datum_type[10]);
    interleaved2 data(idata, 10);
    interleaved2 data_copy(data);
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 3 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
      > interleaved3;
    interleaved3::collection_type idata(new interleaved3::datum_type[20]);
    interleaved3 data(idata, 20);
    interleaved3 data_copy(data);
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 4 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>
      > interleaved4;
    interleaved4::collection_type idata(new interleaved4::datum_type[15]);
    interleaved4 data(idata, 15);
    interleaved4 data_copy(data);
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 5 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
      > interleaved5;
    interleaved5::collection_type idata(new interleaved5::datum_type[2]);
    interleaved5 data(idata, 2);
    interleaved5 data_copy(data);
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 6 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
      > interleaved6;
    interleaved6::collection_type idata(new interleaved6::datum_type[500]);
    interleaved6 data(idata, 500);
    interleaved6 data_copy(data);
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 7 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
      > interleaved7;
    interleaved7::collection_type idata(new interleaved7::datum_type[33]);
    interleaved7 data(idata, 33);
    interleaved7 data_copy(data);
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 8 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
      > interleaved8;
    interleaved8::collection_type idata(new interleaved8::datum_type[96]);
    interleaved8 data(idata, 96);
    interleaved8 data_copy(data);
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 9 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
      > interleaved9;
    interleaved9::collection_type idata(new interleaved9::datum_type[1333]);
    interleaved9 data(idata, 1333);
    interleaved9 data_copy(data);
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }
}
END_TEST

START_TEST(test_interleaved_data_assignment_operator)
{
  { // 2 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
      > interleaved2;
    interleaved2::collection_type idata(new interleaved2::datum_type[10]);
    interleaved2 data(idata, 10);
    interleaved2 data_copy;
    data_copy = data;
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 3 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
      > interleaved3;
    interleaved3::collection_type idata(new interleaved3::datum_type[20]);
    interleaved3 data(idata, 20);
    interleaved3 data_copy(data);
    data_copy = data;
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 4 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>
      > interleaved4;
    interleaved4::collection_type idata(new interleaved4::datum_type[15]);
    interleaved4 data(idata, 15);
    interleaved4 data_copy(data);
    data_copy = data;
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 5 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
      > interleaved5;
    interleaved5::collection_type idata(new interleaved5::datum_type[2]);
    interleaved5 data(idata, 2);
    interleaved5 data_copy(data);
    data_copy = data;
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 6 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
      > interleaved6;
    interleaved6::collection_type idata(new interleaved6::datum_type[500]);
    interleaved6 data(idata, 500);
    interleaved6 data_copy(data);
    data_copy = data;
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 7 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
      > interleaved7;
    interleaved7::collection_type idata(new interleaved7::datum_type[33]);
    interleaved7 data(idata, 33);
    interleaved7 data_copy(data);
    data_copy = data;
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 8 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
      > interleaved8;
    interleaved8::collection_type idata(new interleaved8::datum_type[96]);
    interleaved8 data(idata, 96);
    interleaved8 data_copy(data);
    data_copy = data;
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }

  { // 9 attributes
    typedef opengl_graphics::interleaved_data
      <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
      > interleaved9;
    interleaved9::collection_type idata(new interleaved9::datum_type[1333]);
    interleaved9 data(idata, 1333);
    interleaved9 data_copy(data);
    data_copy = data;
    ck_assert(data_copy.get_data());
    ck_assert(data.get_data());
    ck_assert(
      data_copy.get_attribute_count() == data.get_attribute_count());
  }
}
END_TEST

START_TEST(test_batch_interleaved_is_interleaved_trait)
{
  bool is_interleaved = false;

  is_interleaved = opengl_graphics::interleaved_data
  <
    internal::pod_2<int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>,
    internal::pod_2<int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>,
    internal::pod_2<int, int>
  >::is_interleaved;
  ck_assert(is_interleaved);

  is_interleaved = opengl_graphics::interleaved_data
  <
    internal::pod_2<int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>,
    internal::pod_2<int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>
  >::is_interleaved;
  ck_assert(is_interleaved);

  is_interleaved = opengl_graphics::interleaved_data
  <
    internal::pod_2<int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>
  >::is_interleaved;
  ck_assert(is_interleaved);

  is_interleaved = opengl_graphics::interleaved_data
  <
    internal::pod_2<int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>
  >::is_interleaved;
  ck_assert(is_interleaved);

  is_interleaved = opengl_graphics::interleaved_data
  <
    internal::pod_2<int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>
  >::is_interleaved;
  ck_assert(is_interleaved);

  is_interleaved = opengl_graphics::interleaved_data
  <
    internal::pod_2<int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>
  >::is_interleaved;
  ck_assert(is_interleaved);

  is_interleaved = opengl_graphics::interleaved_data
  <
    internal::pod_2<int, int>,
    internal::pod_3<int, int, int>,
    internal::pod_4<int, int, int, int>
  >::is_interleaved;
  ck_assert(is_interleaved);

  is_interleaved = opengl_graphics::interleaved_data
  <
    internal::pod_2<int, int>,
    internal::pod_3<int, int, int>
  >::is_interleaved;
  ck_assert(is_interleaved);

  is_interleaved = opengl_graphics::batch_data
  <
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>
  >::is_interleaved;
  ck_assert(!is_interleaved);

  is_interleaved = opengl_graphics::batch_data
  <
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>
  >::is_interleaved;
  ck_assert(!is_interleaved);

  is_interleaved = opengl_graphics::batch_data
  <
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>
  >::is_interleaved;
  ck_assert(!is_interleaved);

  is_interleaved = opengl_graphics::batch_data
  <
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>
  >::is_interleaved;
  ck_assert(!is_interleaved);

  is_interleaved = opengl_graphics::batch_data
  <
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>
  >::is_interleaved;
  ck_assert(!is_interleaved);

  is_interleaved = opengl_graphics::batch_data
  <
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>
  >::is_interleaved;
  ck_assert(!is_interleaved);

  is_interleaved = opengl_graphics::batch_data
  <
    internal::pod_2<int, int>,
    internal::pod_2<int, int>,
    internal::pod_2<int, int>
  >::is_interleaved;
  ck_assert(!is_interleaved);

  is_interleaved = opengl_graphics::batch_data
  <
    internal::pod_2<int, int>,
    internal::pod_2<int, int>
  >::is_interleaved;
  ck_assert(!is_interleaved);

  is_interleaved = opengl_graphics::batch_data
  <
    internal::pod_2<int, int>
  >::is_interleaved;
  ck_assert(!is_interleaved);
}
END_TEST

START_TEST(test_indices)
{
  {
    opengl_graphics::indices<uint16_t> indices;
    ck_assert(!indices.get_data().get());
  }

  {
    opengl_graphics::indices<uint16_t>::collection_type data(
      new uint16_t[12]);
    opengl_graphics::indices<uint16_t> indices(data, 12);
    ck_assert(indices.get_data().get());
    ck_assert(12 == indices.get_indices_count());
    ck_assert(12 * sizeof(uint16_t) == indices.get_byte_count());
  }

  {
    opengl_graphics::indices<uint16_t>::collection_type data(
      new uint16_t[12]);
    opengl_graphics::indices<uint16_t> indices(data, 12);
    opengl_graphics::indices<uint16_t> indices_cpy(indices);
    ck_assert(indices == indices_cpy);
    ck_assert(!(indices != indices_cpy));
  }

  {
    opengl_graphics::indices<uint16_t>::collection_type data(
      new uint16_t[12]);
    opengl_graphics::indices<uint16_t> indices(data, 12);
    opengl_graphics::indices<uint16_t> indices_cpy;
    indices_cpy = indices;
    ck_assert(indices == indices_cpy);
    ck_assert(!(indices != indices_cpy));
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

  tcase_add_test(tc, test_default_interleaved_datum_2d_constructor);
  tcase_add_test(tc, test_default_interleaved_datum_3d_constructor);
  tcase_add_test(tc, test_default_interleaved_datum_4d_constructor);
  tcase_add_test(tc, test_default_interleaved_datum_5d_constructor);
  tcase_add_test(tc, test_default_interleaved_datum_6d_constructor);
  tcase_add_test(tc, test_default_interleaved_datum_7d_constructor);
  tcase_add_test(tc, test_default_interleaved_datum_8d_constructor);
  tcase_add_test(tc, test_default_interleaved_datum_9d_constructor);
  tcase_add_test(tc, test_interleaved_datum_2d_constructor);
  tcase_add_test(tc, test_interleaved_datum_3d_constructor);
  tcase_add_test(tc, test_interleaved_datum_4d_constructor);
  tcase_add_test(tc, test_interleaved_datum_5d_constructor);
  tcase_add_test(tc, test_interleaved_datum_6d_constructor);
  tcase_add_test(tc, test_interleaved_datum_7d_constructor);
  tcase_add_test(tc, test_interleaved_datum_8d_constructor);
  tcase_add_test(tc, test_interleaved_datum_9d_constructor);
  tcase_add_test(tc, test_interleaved_datum_2d_copy_constructor);
  tcase_add_test(tc, test_interleaved_datum_3d_copy_constructor);
  tcase_add_test(tc, test_interleaved_datum_4d_copy_constructor);
  tcase_add_test(tc, test_interleaved_datum_5d_copy_constructor);
  tcase_add_test(tc, test_interleaved_datum_6d_copy_constructor);
  tcase_add_test(tc, test_interleaved_datum_7d_copy_constructor);
  tcase_add_test(tc, test_interleaved_datum_8d_copy_constructor);
  tcase_add_test(tc, test_interleaved_datum_9d_copy_constructor);
  tcase_add_test(tc, test_interleaved_datum_2d_assignment_operator);
  tcase_add_test(tc, test_interleaved_datum_3d_assignment_operator);
  tcase_add_test(tc, test_interleaved_datum_4d_assignment_operator);
  tcase_add_test(tc, test_interleaved_datum_5d_assignment_operator);
  tcase_add_test(tc, test_interleaved_datum_6d_assignment_operator);
  tcase_add_test(tc, test_interleaved_datum_7d_assignment_operator);
  tcase_add_test(tc, test_interleaved_datum_8d_assignment_operator);
  tcase_add_test(tc, test_interleaved_datum_9d_assignment_operator);
  tcase_add_test(tc, test_batch_data_default_ctor);
  tcase_add_test(tc, test_batch_data_ctor);
  tcase_add_test(tc, test_batch_data_copy_ctor);
  tcase_add_test(tc, test_batch_data_assignment_opperator);
  tcase_add_test(tc, test_batch_data_get_byte_counts);
  tcase_add_test(tc, test_interleaved_data_default_ctor);
  tcase_add_test(tc, test_interleaved_data_ctor);
  tcase_add_test(tc, test_interleaved_data_copy_ctor);
  tcase_add_test(tc, test_interleaved_data_assignment_operator);
  tcase_add_test(tc, test_batch_interleaved_is_interleaved_trait);
  tcase_add_test(tc, test_indices);

  suite_add_tcase(s, tc);
  sr = suite_runner_create(s);
  result = (run_and_report(sr) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return result;
}
