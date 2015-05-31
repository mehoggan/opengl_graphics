#ifndef INTERLEAVED_DATUM_TESTS
#define INTERLEAVED_DATUM_TESTS

#define _USE_MATH_DEFINES

#include <cxxtest/TestSuite.h>

#include <graphics/mesh_types/datums/interleaved_datum_2d.h>
#include <graphics/mesh_types/datums/interleaved_datum_3d.h>
#include <graphics/mesh_types/datums/interleaved_datum_4d.h>
#include <graphics/mesh_types/datums/interleaved_datum_5d.h>
#include <graphics/mesh_types/datums/interleaved_datum_6d.h>
#include <graphics/mesh_types/datums/interleaved_datum_7d.h>
#include <graphics/mesh_types/datums/interleaved_datum_8d.h>
#include <graphics/mesh_types/datums/interleaved_datum_9d.h>
#include <graphics/mesh_types/interleaved_data.h>
#include <graphics/mesh_types/batch_data.h>

#include <math.h>

#include <cassert>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

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
  };
}

/*
 * Start of actual tests.
 */
class interleaved_datum_tests : public CxxTest::TestSuite
{
private:
    // 2D datums
    typedef gl_wrapper::interleaved_datum_2d <internal::pod_2<int, int>,
      internal::pod_3<int, int, int> > id2d_2X3i;

    // 3D datums
    typedef gl_wrapper::interleaved_datum_3d <internal::pod_2<int, int>,
      internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int> >
      id3d_2X3X4i;

    // 4D datums
    typedef gl_wrapper::interleaved_datum_4d <internal::pod_2<int, int>,
      internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int> > id4d_2X3X4X2i;

    // 5D datums
    typedef gl_wrapper::interleaved_datum_5d <internal::pod_2<int, int>,
      internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>, internal::pod_3<int, int, int> >
      id5d_2X3X4X2X3i;

    // 6D datums
    typedef gl_wrapper::interleaved_datum_6d <internal::pod_2<int, int>,
      internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>, internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int> > id6d_2X3X4X2X3X4i;

    // 7D datums
    typedef gl_wrapper::interleaved_datum_7d <internal::pod_2<int, int>,
      internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>, internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>, internal::pod_2<int, int> >
      id7d_2X3X4X2X3X4X2i;

    // 8D datums
    typedef gl_wrapper::interleaved_datum_8d <internal::pod_2<int, int>,
      internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>, internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>, internal::pod_2<int, int>,
      internal::pod_3<int, int, int> >
      id8d_2X3X4X2X3X4X2X3i;

    // 9D datums
    typedef gl_wrapper::interleaved_datum_9d <internal::pod_2<int, int>,
      internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>, internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>, internal::pod_2<int, int>,
      internal::pod_3<int, int, int>, internal::pod_4<int, int, int, int> >
      id9d_2X3X4X2X3X4X2X3X4i;

public:
  /*! \brief This is a test for the default ctor in the interleaved_datum_2d
   * interleaved_datum_3d ... interleaved_datum_10d classes. To ensure
   * interleaved datum calls default constructor with defined behavior.
   */
  void test_default_interleaved_datum_2d_constructor()
  {
    id2d_2X3i data;

    TS_ASSERT_EQUALS(0, data._datum1.t1_);
    TS_ASSERT_EQUALS(0, data._datum1.t2_);

    TS_ASSERT_EQUALS(0, data._datum2.t1_);
    TS_ASSERT_EQUALS(0, data._datum2.t2_);
    TS_ASSERT_EQUALS(0, data._datum2.t3_);
  }

  void test_default_interleaved_datum_3d_constructor()
  {
    id3d_2X3X4i data;

    TS_ASSERT_EQUALS(0, data._datum1.t1_);
    TS_ASSERT_EQUALS(0, data._datum1.t2_);

    TS_ASSERT_EQUALS(0, data._datum2.t1_);
    TS_ASSERT_EQUALS(0, data._datum2.t2_);
    TS_ASSERT_EQUALS(0, data._datum2.t3_);

    TS_ASSERT_EQUALS(0, data._datum3.t1_);
    TS_ASSERT_EQUALS(0, data._datum3.t2_);
    TS_ASSERT_EQUALS(0, data._datum3.t3_);
    TS_ASSERT_EQUALS(0, data._datum3.t4_);
  }

  void test_default_interleaved_datum_4d_constructor()
  {
    id4d_2X3X4X2i data;

    TS_ASSERT_EQUALS(0, data._datum1.t1_);
    TS_ASSERT_EQUALS(0, data._datum1.t2_);

    TS_ASSERT_EQUALS(0, data._datum2.t1_);
    TS_ASSERT_EQUALS(0, data._datum2.t2_);
    TS_ASSERT_EQUALS(0, data._datum2.t3_);

    TS_ASSERT_EQUALS(0, data._datum3.t1_);
    TS_ASSERT_EQUALS(0, data._datum3.t2_);
    TS_ASSERT_EQUALS(0, data._datum3.t3_);
    TS_ASSERT_EQUALS(0, data._datum3.t4_);

    TS_ASSERT_EQUALS(0, data._datum4.t1_);
    TS_ASSERT_EQUALS(0, data._datum4.t2_);
  }

  void test_default_interleaved_datum_5d_constructor()
  {
    id5d_2X3X4X2X3i data;

    TS_ASSERT_EQUALS(0, data._datum1.t1_);
    TS_ASSERT_EQUALS(0, data._datum1.t2_);

    TS_ASSERT_EQUALS(0, data._datum2.t1_);
    TS_ASSERT_EQUALS(0, data._datum2.t2_);
    TS_ASSERT_EQUALS(0, data._datum2.t3_);

    TS_ASSERT_EQUALS(0, data._datum3.t1_);
    TS_ASSERT_EQUALS(0, data._datum3.t2_);
    TS_ASSERT_EQUALS(0, data._datum3.t3_);
    TS_ASSERT_EQUALS(0, data._datum3.t4_);

    TS_ASSERT_EQUALS(0, data._datum4.t1_);
    TS_ASSERT_EQUALS(0, data._datum4.t2_);

    TS_ASSERT_EQUALS(0, data._datum5.t1_);
    TS_ASSERT_EQUALS(0, data._datum5.t2_);
    TS_ASSERT_EQUALS(0, data._datum5.t3_);
  }

  void test_default_interleaved_datum_6d_constructor()
  {
    id6d_2X3X4X2X3X4i data;

    TS_ASSERT_EQUALS(0, data._datum1.t1_);
    TS_ASSERT_EQUALS(0, data._datum1.t2_);

    TS_ASSERT_EQUALS(0, data._datum2.t1_);
    TS_ASSERT_EQUALS(0, data._datum2.t2_);
    TS_ASSERT_EQUALS(0, data._datum2.t3_);

    TS_ASSERT_EQUALS(0, data._datum3.t1_);
    TS_ASSERT_EQUALS(0, data._datum3.t2_);
    TS_ASSERT_EQUALS(0, data._datum3.t3_);
    TS_ASSERT_EQUALS(0, data._datum3.t4_);

    TS_ASSERT_EQUALS(0, data._datum4.t1_);
    TS_ASSERT_EQUALS(0, data._datum4.t2_);

    TS_ASSERT_EQUALS(0, data._datum5.t1_);
    TS_ASSERT_EQUALS(0, data._datum5.t2_);
    TS_ASSERT_EQUALS(0, data._datum5.t3_);

    TS_ASSERT_EQUALS(0, data._datum6.t1_);
    TS_ASSERT_EQUALS(0, data._datum6.t2_);
    TS_ASSERT_EQUALS(0, data._datum6.t3_);
    TS_ASSERT_EQUALS(0, data._datum6.t4_);
  }

  void test_default_interleaved_datum_7d_constructor()
  {
    id7d_2X3X4X2X3X4X2i data;

    TS_ASSERT_EQUALS(0, data._datum1.t1_);
    TS_ASSERT_EQUALS(0, data._datum1.t2_);

    TS_ASSERT_EQUALS(0, data._datum2.t1_);
    TS_ASSERT_EQUALS(0, data._datum2.t2_);
    TS_ASSERT_EQUALS(0, data._datum2.t3_);

    TS_ASSERT_EQUALS(0, data._datum3.t1_);
    TS_ASSERT_EQUALS(0, data._datum3.t2_);
    TS_ASSERT_EQUALS(0, data._datum3.t3_);
    TS_ASSERT_EQUALS(0, data._datum3.t4_);

    TS_ASSERT_EQUALS(0, data._datum4.t1_);
    TS_ASSERT_EQUALS(0, data._datum4.t2_);

    TS_ASSERT_EQUALS(0, data._datum5.t1_);
    TS_ASSERT_EQUALS(0, data._datum5.t2_);
    TS_ASSERT_EQUALS(0, data._datum5.t3_);

    TS_ASSERT_EQUALS(0, data._datum6.t1_);
    TS_ASSERT_EQUALS(0, data._datum6.t2_);
    TS_ASSERT_EQUALS(0, data._datum6.t3_);
    TS_ASSERT_EQUALS(0, data._datum6.t4_);

    TS_ASSERT_EQUALS(0, data._datum7.t1_);
    TS_ASSERT_EQUALS(0, data._datum7.t2_);
  }

  void test_default_interleaved_datum_8d_constructor()
  {
    id8d_2X3X4X2X3X4X2X3i data;

    TS_ASSERT_EQUALS(0, data._datum1.t1_);
    TS_ASSERT_EQUALS(0, data._datum1.t2_);

    TS_ASSERT_EQUALS(0, data._datum2.t1_);
    TS_ASSERT_EQUALS(0, data._datum2.t2_);
    TS_ASSERT_EQUALS(0, data._datum2.t3_);

    TS_ASSERT_EQUALS(0, data._datum3.t1_);
    TS_ASSERT_EQUALS(0, data._datum3.t2_);
    TS_ASSERT_EQUALS(0, data._datum3.t3_);
    TS_ASSERT_EQUALS(0, data._datum3.t4_);

    TS_ASSERT_EQUALS(0, data._datum4.t1_);
    TS_ASSERT_EQUALS(0, data._datum4.t2_);

    TS_ASSERT_EQUALS(0, data._datum5.t1_);
    TS_ASSERT_EQUALS(0, data._datum5.t2_);
    TS_ASSERT_EQUALS(0, data._datum5.t3_);

    TS_ASSERT_EQUALS(0, data._datum6.t1_);
    TS_ASSERT_EQUALS(0, data._datum6.t2_);
    TS_ASSERT_EQUALS(0, data._datum6.t3_);
    TS_ASSERT_EQUALS(0, data._datum6.t4_);

    TS_ASSERT_EQUALS(0, data._datum7.t1_);
    TS_ASSERT_EQUALS(0, data._datum7.t2_);

    TS_ASSERT_EQUALS(0, data._datum8.t1_);
    TS_ASSERT_EQUALS(0, data._datum8.t2_);
    TS_ASSERT_EQUALS(0, data._datum8.t3_);
  }

  void test_default_interleaved_datum_9d_constructor()
  {
    id9d_2X3X4X2X3X4X2X3X4i data;

    TS_ASSERT_EQUALS(0, data._datum1.t1_);
    TS_ASSERT_EQUALS(0, data._datum1.t2_);

    TS_ASSERT_EQUALS(0, data._datum2.t1_);
    TS_ASSERT_EQUALS(0, data._datum2.t2_);
    TS_ASSERT_EQUALS(0, data._datum2.t3_);

    TS_ASSERT_EQUALS(0, data._datum3.t1_);
    TS_ASSERT_EQUALS(0, data._datum3.t2_);
    TS_ASSERT_EQUALS(0, data._datum3.t3_);
    TS_ASSERT_EQUALS(0, data._datum3.t4_);

    TS_ASSERT_EQUALS(0, data._datum4.t1_);
    TS_ASSERT_EQUALS(0, data._datum4.t2_);

    TS_ASSERT_EQUALS(0, data._datum5.t1_);
    TS_ASSERT_EQUALS(0, data._datum5.t2_);
    TS_ASSERT_EQUALS(0, data._datum5.t3_);

    TS_ASSERT_EQUALS(0, data._datum6.t1_);
    TS_ASSERT_EQUALS(0, data._datum6.t2_);
    TS_ASSERT_EQUALS(0, data._datum6.t3_);
    TS_ASSERT_EQUALS(0, data._datum6.t4_);

    TS_ASSERT_EQUALS(0, data._datum7.t1_);
    TS_ASSERT_EQUALS(0, data._datum7.t2_);

    TS_ASSERT_EQUALS(0, data._datum8.t1_);
    TS_ASSERT_EQUALS(0, data._datum8.t2_);
    TS_ASSERT_EQUALS(0, data._datum8.t3_);

    TS_ASSERT_EQUALS(0, data._datum9.t1_);
    TS_ASSERT_EQUALS(0, data._datum9.t2_);
    TS_ASSERT_EQUALS(0, data._datum9.t3_);
    TS_ASSERT_EQUALS(0, data._datum9.t4_);
  }

  /*! \brief This is a test for the ctor in the interleaved_datum_2d
   * interleaved_datum_3d ... interleaved_datum_10d classes.
   */
  void test_interleaved_datum_2d_constructor()
  {
    id2d_2X3i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5));

    TS_ASSERT_EQUALS(1, data._datum1.t1_);
    TS_ASSERT_EQUALS(2, data._datum1.t2_);

    TS_ASSERT_EQUALS(3, data._datum2.t1_);
    TS_ASSERT_EQUALS(4, data._datum2.t2_);
    TS_ASSERT_EQUALS(5, data._datum2.t3_);
  }

  void test_interleaved_datum_3d_constructor()
  {
    id3d_2X3X4i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9));

    TS_ASSERT_EQUALS(1, data._datum1.t1_);
    TS_ASSERT_EQUALS(2, data._datum1.t2_);

    TS_ASSERT_EQUALS(3, data._datum2.t1_);
    TS_ASSERT_EQUALS(4, data._datum2.t2_);
    TS_ASSERT_EQUALS(5, data._datum2.t3_);

    TS_ASSERT_EQUALS(6, data._datum3.t1_);
    TS_ASSERT_EQUALS(7, data._datum3.t2_);
    TS_ASSERT_EQUALS(8, data._datum3.t3_);
    TS_ASSERT_EQUALS(9, data._datum3.t4_);
  }

  void test_interleaved_datum_4d_constructor()
  {
    id4d_2X3X4X2i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11));

    TS_ASSERT_EQUALS(1, data._datum1.t1_);
    TS_ASSERT_EQUALS(2, data._datum1.t2_);

    TS_ASSERT_EQUALS(3, data._datum2.t1_);
    TS_ASSERT_EQUALS(4, data._datum2.t2_);
    TS_ASSERT_EQUALS(5, data._datum2.t3_);

    TS_ASSERT_EQUALS(6, data._datum3.t1_);
    TS_ASSERT_EQUALS(7, data._datum3.t2_);
    TS_ASSERT_EQUALS(8, data._datum3.t3_);
    TS_ASSERT_EQUALS(9, data._datum3.t4_);

    TS_ASSERT_EQUALS(10, data._datum4.t1_);
    TS_ASSERT_EQUALS(11, data._datum4.t2_);
  }

  void test_interleaved_datum_5d_constructor()
  {
    id5d_2X3X4X2X3i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14));

    TS_ASSERT_EQUALS(1, data._datum1.t1_);
    TS_ASSERT_EQUALS(2, data._datum1.t2_);

    TS_ASSERT_EQUALS(3, data._datum2.t1_);
    TS_ASSERT_EQUALS(4, data._datum2.t2_);
    TS_ASSERT_EQUALS(5, data._datum2.t3_);

    TS_ASSERT_EQUALS(6, data._datum3.t1_);
    TS_ASSERT_EQUALS(7, data._datum3.t2_);
    TS_ASSERT_EQUALS(8, data._datum3.t3_);
    TS_ASSERT_EQUALS(9, data._datum3.t4_);

    TS_ASSERT_EQUALS(10, data._datum4.t1_);
    TS_ASSERT_EQUALS(11, data._datum4.t2_);

    TS_ASSERT_EQUALS(12, data._datum5.t1_);
    TS_ASSERT_EQUALS(13, data._datum5.t2_);
    TS_ASSERT_EQUALS(14, data._datum5.t3_);
  }

  void test_interleaved_datum_6d_constructor()
  {
    id6d_2X3X4X2X3X4i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18));

    TS_ASSERT_EQUALS(1, data._datum1.t1_);
    TS_ASSERT_EQUALS(2, data._datum1.t2_);

    TS_ASSERT_EQUALS(3, data._datum2.t1_);
    TS_ASSERT_EQUALS(4, data._datum2.t2_);
    TS_ASSERT_EQUALS(5, data._datum2.t3_);

    TS_ASSERT_EQUALS(6, data._datum3.t1_);
    TS_ASSERT_EQUALS(7, data._datum3.t2_);
    TS_ASSERT_EQUALS(8, data._datum3.t3_);
    TS_ASSERT_EQUALS(9, data._datum3.t4_);

    TS_ASSERT_EQUALS(10, data._datum4.t1_);
    TS_ASSERT_EQUALS(11, data._datum4.t2_);

    TS_ASSERT_EQUALS(12, data._datum5.t1_);
    TS_ASSERT_EQUALS(13, data._datum5.t2_);
    TS_ASSERT_EQUALS(14, data._datum5.t3_);

    TS_ASSERT_EQUALS(15, data._datum6.t1_);
    TS_ASSERT_EQUALS(16, data._datum6.t2_);
    TS_ASSERT_EQUALS(17, data._datum6.t3_);
    TS_ASSERT_EQUALS(18, data._datum6.t4_);
  }

  void test_interleaved_datum_7d_constructor()
  {
    id7d_2X3X4X2X3X4X2i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18),
      internal::pod_2<int, int>(19, 20));

    TS_ASSERT_EQUALS(1, data._datum1.t1_);
    TS_ASSERT_EQUALS(2, data._datum1.t2_);

    TS_ASSERT_EQUALS(3, data._datum2.t1_);
    TS_ASSERT_EQUALS(4, data._datum2.t2_);
    TS_ASSERT_EQUALS(5, data._datum2.t3_);

    TS_ASSERT_EQUALS(6, data._datum3.t1_);
    TS_ASSERT_EQUALS(7, data._datum3.t2_);
    TS_ASSERT_EQUALS(8, data._datum3.t3_);
    TS_ASSERT_EQUALS(9, data._datum3.t4_);

    TS_ASSERT_EQUALS(10, data._datum4.t1_);
    TS_ASSERT_EQUALS(11, data._datum4.t2_);

    TS_ASSERT_EQUALS(12, data._datum5.t1_);
    TS_ASSERT_EQUALS(13, data._datum5.t2_);
    TS_ASSERT_EQUALS(14, data._datum5.t3_);

    TS_ASSERT_EQUALS(15, data._datum6.t1_);
    TS_ASSERT_EQUALS(16, data._datum6.t2_);
    TS_ASSERT_EQUALS(17, data._datum6.t3_);
    TS_ASSERT_EQUALS(18, data._datum6.t4_);

    TS_ASSERT_EQUALS(19, data._datum7.t1_);
    TS_ASSERT_EQUALS(20, data._datum7.t2_);
  }

  void test_interleaved_datum_8d_constructor()
  {
    id8d_2X3X4X2X3X4X2X3i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18),
      internal::pod_2<int, int>(19, 20),
      internal::pod_3<int, int, int>(21, 22, 23));

    TS_ASSERT_EQUALS(1, data._datum1.t1_);
    TS_ASSERT_EQUALS(2, data._datum1.t2_);

    TS_ASSERT_EQUALS(3, data._datum2.t1_);
    TS_ASSERT_EQUALS(4, data._datum2.t2_);
    TS_ASSERT_EQUALS(5, data._datum2.t3_);

    TS_ASSERT_EQUALS(6, data._datum3.t1_);
    TS_ASSERT_EQUALS(7, data._datum3.t2_);
    TS_ASSERT_EQUALS(8, data._datum3.t3_);
    TS_ASSERT_EQUALS(9, data._datum3.t4_);

    TS_ASSERT_EQUALS(10, data._datum4.t1_);
    TS_ASSERT_EQUALS(11, data._datum4.t2_);

    TS_ASSERT_EQUALS(12, data._datum5.t1_);
    TS_ASSERT_EQUALS(13, data._datum5.t2_);
    TS_ASSERT_EQUALS(14, data._datum5.t3_);

    TS_ASSERT_EQUALS(15, data._datum6.t1_);
    TS_ASSERT_EQUALS(16, data._datum6.t2_);
    TS_ASSERT_EQUALS(17, data._datum6.t3_);
    TS_ASSERT_EQUALS(18, data._datum6.t4_);

    TS_ASSERT_EQUALS(19, data._datum7.t1_);
    TS_ASSERT_EQUALS(20, data._datum7.t2_);

    TS_ASSERT_EQUALS(21, data._datum8.t1_);
    TS_ASSERT_EQUALS(22, data._datum8.t2_);
    TS_ASSERT_EQUALS(23, data._datum8.t3_);
  }

  void test_interleaved_datum_9d_constructor()
  {
    id9d_2X3X4X2X3X4X2X3X4i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18),
      internal::pod_2<int, int>(19, 20),
      internal::pod_3<int, int, int>(21, 22, 23),
      internal::pod_4<int, int, int, int>(24, 25, 26, 27));

    TS_ASSERT_EQUALS(1, data._datum1.t1_);
    TS_ASSERT_EQUALS(2, data._datum1.t2_);

    TS_ASSERT_EQUALS(3, data._datum2.t1_);
    TS_ASSERT_EQUALS(4, data._datum2.t2_);
    TS_ASSERT_EQUALS(5, data._datum2.t3_);

    TS_ASSERT_EQUALS(6, data._datum3.t1_);
    TS_ASSERT_EQUALS(7, data._datum3.t2_);
    TS_ASSERT_EQUALS(8, data._datum3.t3_);
    TS_ASSERT_EQUALS(9, data._datum3.t4_);

    TS_ASSERT_EQUALS(10, data._datum4.t1_);
    TS_ASSERT_EQUALS(11, data._datum4.t2_);

    TS_ASSERT_EQUALS(12, data._datum5.t1_);
    TS_ASSERT_EQUALS(13, data._datum5.t2_);
    TS_ASSERT_EQUALS(14, data._datum5.t3_);

    TS_ASSERT_EQUALS(15, data._datum6.t1_);
    TS_ASSERT_EQUALS(16, data._datum6.t2_);
    TS_ASSERT_EQUALS(17, data._datum6.t3_);
    TS_ASSERT_EQUALS(18, data._datum6.t4_);

    TS_ASSERT_EQUALS(19, data._datum7.t1_);
    TS_ASSERT_EQUALS(20, data._datum7.t2_);

    TS_ASSERT_EQUALS(21, data._datum8.t1_);
    TS_ASSERT_EQUALS(22, data._datum8.t2_);
    TS_ASSERT_EQUALS(23, data._datum8.t3_);

    TS_ASSERT_EQUALS(24, data._datum9.t1_);
    TS_ASSERT_EQUALS(25, data._datum9.t2_);
    TS_ASSERT_EQUALS(26, data._datum9.t3_);
    TS_ASSERT_EQUALS(27, data._datum9.t4_);
  }

  /*! \brief This is a test for the copy ctor in the interleaved_datum_2d
   * interleaved_datum_3d ... interleaved_datum_10d classes.
   */
  void test_interleaved_datum_2d_copy_constructor()
  {
    id2d_2X3i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5));

    id2d_2X3i data_copy(data);

    TS_ASSERT_EQUALS(1, data_copy._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_copy._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_copy._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_copy._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_copy._datum2.t3_);

    ////TS_ASSERT(data == data_copy);
    ////TS_ASSERT(!(data != data_copy));
  }

  void test_interleaved_datum_3d_copy_constructor()
  {
    id3d_2X3X4i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9));

    id3d_2X3X4i data_copy(data);

    TS_ASSERT_EQUALS(1, data_copy._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_copy._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_copy._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_copy._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_copy._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_copy._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_copy._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_copy._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_copy._datum3.t4_);

    //TS_ASSERT(data == data_copy);
    //TS_ASSERT(!(data != data_copy));
  }

  void test_interleaved_datum_4d_copy_constructor()
  {
    id4d_2X3X4X2i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11));

    id4d_2X3X4X2i data_copy(data);

    TS_ASSERT_EQUALS(1, data_copy._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_copy._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_copy._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_copy._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_copy._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_copy._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_copy._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_copy._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_copy._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_copy._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_copy._datum4.t2_);

    //TS_ASSERT(data == data_copy);
    //TS_ASSERT(!(data != data_copy));
  }

  void test_interleaved_datum_5d_copy_constructor()
  {
    id5d_2X3X4X2X3i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14));

    id5d_2X3X4X2X3i data_copy(data);

    TS_ASSERT_EQUALS(1, data_copy._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_copy._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_copy._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_copy._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_copy._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_copy._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_copy._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_copy._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_copy._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_copy._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_copy._datum4.t2_);

    TS_ASSERT_EQUALS(12, data_copy._datum5.t1_);
    TS_ASSERT_EQUALS(13, data_copy._datum5.t2_);
    TS_ASSERT_EQUALS(14, data_copy._datum5.t3_);

    //TS_ASSERT(data == data_copy);
    //TS_ASSERT(!(data != data_copy));
  }

  void test_interleaved_datum_6d_copy_constructor()
  {
    id6d_2X3X4X2X3X4i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18));

    id6d_2X3X4X2X3X4i data_copy(data);

    TS_ASSERT_EQUALS(1, data_copy._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_copy._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_copy._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_copy._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_copy._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_copy._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_copy._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_copy._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_copy._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_copy._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_copy._datum4.t2_);

    TS_ASSERT_EQUALS(12, data_copy._datum5.t1_);
    TS_ASSERT_EQUALS(13, data_copy._datum5.t2_);
    TS_ASSERT_EQUALS(14, data_copy._datum5.t3_);

    TS_ASSERT_EQUALS(15, data_copy._datum6.t1_);
    TS_ASSERT_EQUALS(16, data_copy._datum6.t2_);
    TS_ASSERT_EQUALS(17, data_copy._datum6.t3_);
    TS_ASSERT_EQUALS(18, data_copy._datum6.t4_);

    //TS_ASSERT(data == data_copy);
    //TS_ASSERT(!(data != data_copy));
  }

  void test_interleaved_datum_7d_copy_constructor()
  {
    id7d_2X3X4X2X3X4X2i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18),
      internal::pod_2<int, int>(19, 20));

    id7d_2X3X4X2X3X4X2i data_copy(data);

    TS_ASSERT_EQUALS(1, data_copy._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_copy._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_copy._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_copy._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_copy._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_copy._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_copy._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_copy._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_copy._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_copy._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_copy._datum4.t2_);

    TS_ASSERT_EQUALS(12, data_copy._datum5.t1_);
    TS_ASSERT_EQUALS(13, data_copy._datum5.t2_);
    TS_ASSERT_EQUALS(14, data_copy._datum5.t3_);

    TS_ASSERT_EQUALS(15, data_copy._datum6.t1_);
    TS_ASSERT_EQUALS(16, data_copy._datum6.t2_);
    TS_ASSERT_EQUALS(17, data_copy._datum6.t3_);
    TS_ASSERT_EQUALS(18, data_copy._datum6.t4_);

    TS_ASSERT_EQUALS(19, data_copy._datum7.t1_);
    TS_ASSERT_EQUALS(20, data_copy._datum7.t2_);

    //TS_ASSERT(data == data_copy);
    //TS_ASSERT(!(data != data_copy));
  }

  void test_interleaved_datum_8d_copy_constructor()
  {
    id8d_2X3X4X2X3X4X2X3i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18),
      internal::pod_2<int, int>(19, 20),
      internal::pod_3<int, int, int>(21, 22, 23));

    id8d_2X3X4X2X3X4X2X3i data_copy(data);

    TS_ASSERT_EQUALS(1, data_copy._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_copy._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_copy._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_copy._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_copy._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_copy._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_copy._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_copy._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_copy._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_copy._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_copy._datum4.t2_);

    TS_ASSERT_EQUALS(12, data_copy._datum5.t1_);
    TS_ASSERT_EQUALS(13, data_copy._datum5.t2_);
    TS_ASSERT_EQUALS(14, data_copy._datum5.t3_);

    TS_ASSERT_EQUALS(15, data_copy._datum6.t1_);
    TS_ASSERT_EQUALS(16, data_copy._datum6.t2_);
    TS_ASSERT_EQUALS(17, data_copy._datum6.t3_);
    TS_ASSERT_EQUALS(18, data_copy._datum6.t4_);

    TS_ASSERT_EQUALS(19, data_copy._datum7.t1_);
    TS_ASSERT_EQUALS(20, data_copy._datum7.t2_);

    TS_ASSERT_EQUALS(21, data_copy._datum8.t1_);
    TS_ASSERT_EQUALS(22, data_copy._datum8.t2_);
    TS_ASSERT_EQUALS(23, data_copy._datum8.t3_);

    //TS_ASSERT(data == data_copy);
    //TS_ASSERT(!(data != data_copy));
  }

  void test_interleaved_datum_9d_copy_constructor()
  {
    id9d_2X3X4X2X3X4X2X3X4i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18),
      internal::pod_2<int, int>(19, 20),
      internal::pod_3<int, int, int>(21, 22, 23),
      internal::pod_4<int, int, int, int>(24, 25, 26, 27));

    id9d_2X3X4X2X3X4X2X3X4i data_copy(data);

    TS_ASSERT_EQUALS(1, data_copy._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_copy._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_copy._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_copy._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_copy._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_copy._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_copy._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_copy._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_copy._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_copy._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_copy._datum4.t2_);

    TS_ASSERT_EQUALS(12, data_copy._datum5.t1_);
    TS_ASSERT_EQUALS(13, data_copy._datum5.t2_);
    TS_ASSERT_EQUALS(14, data_copy._datum5.t3_);

    TS_ASSERT_EQUALS(15, data_copy._datum6.t1_);
    TS_ASSERT_EQUALS(16, data_copy._datum6.t2_);
    TS_ASSERT_EQUALS(17, data_copy._datum6.t3_);
    TS_ASSERT_EQUALS(18, data_copy._datum6.t4_);

    TS_ASSERT_EQUALS(19, data_copy._datum7.t1_);
    TS_ASSERT_EQUALS(20, data_copy._datum7.t2_);

    TS_ASSERT_EQUALS(21, data_copy._datum8.t1_);
    TS_ASSERT_EQUALS(22, data_copy._datum8.t2_);
    TS_ASSERT_EQUALS(23, data_copy._datum8.t3_);

    TS_ASSERT_EQUALS(24, data_copy._datum9.t1_);
    TS_ASSERT_EQUALS(25, data_copy._datum9.t2_);
    TS_ASSERT_EQUALS(26, data_copy._datum9.t3_);
    TS_ASSERT_EQUALS(27, data_copy._datum9.t4_);

    //TS_ASSERT(data == data_copy);
    //TS_ASSERT(!(data != data_copy));
  }

  /*! \brief This is a test for the assignment operator in the
   * interleaved_datum_2d interleaved_datum_3d ... interleaved_datum_10d
   * classes.
   */
  void test_interleaved_datum_2d_assignment_operator()
  {
    id2d_2X3i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5));

    id2d_2X3i data_assign = data;

    TS_ASSERT_EQUALS(1, data_assign._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_assign._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_assign._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_assign._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_assign._datum2.t3_);

    //TS_ASSERT(data == data_assign);
    //TS_ASSERT(!(data != data_assign));
  }

  void test_interleaved_datum_3d_assignment_operator()
  {
    id3d_2X3X4i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9));

    id3d_2X3X4i data_assign = data;

    TS_ASSERT_EQUALS(1, data_assign._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_assign._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_assign._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_assign._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_assign._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_assign._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_assign._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_assign._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_assign._datum3.t4_);

    //TS_ASSERT(data == data_assign);
    //TS_ASSERT(!(data != data_assign));
  }

  void test_interleaved_datum_4d_assignment_operator()
  {
    id4d_2X3X4X2i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11));

    id4d_2X3X4X2i data_assign = data;

    TS_ASSERT_EQUALS(1, data_assign._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_assign._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_assign._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_assign._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_assign._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_assign._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_assign._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_assign._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_assign._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_assign._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_assign._datum4.t2_);

    //TS_ASSERT(data == data_assign);
    //TS_ASSERT(!(data != data_assign));
  }

  void test_interleaved_datum_5d_assignment_operator()
  {
    id5d_2X3X4X2X3i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14));

    id5d_2X3X4X2X3i data_assign = data;

    TS_ASSERT_EQUALS(1, data_assign._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_assign._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_assign._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_assign._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_assign._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_assign._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_assign._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_assign._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_assign._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_assign._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_assign._datum4.t2_);

    TS_ASSERT_EQUALS(12, data_assign._datum5.t1_);
    TS_ASSERT_EQUALS(13, data_assign._datum5.t2_);
    TS_ASSERT_EQUALS(14, data_assign._datum5.t3_);

    //TS_ASSERT(data == data_assign);
    //TS_ASSERT(!(data != data_assign));
  }

  void test_interleaved_datum_6d_assignment_operator()
  {
    id6d_2X3X4X2X3X4i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18));

    id6d_2X3X4X2X3X4i data_assign = data;

    TS_ASSERT_EQUALS(1, data_assign._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_assign._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_assign._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_assign._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_assign._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_assign._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_assign._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_assign._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_assign._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_assign._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_assign._datum4.t2_);

    TS_ASSERT_EQUALS(12, data_assign._datum5.t1_);
    TS_ASSERT_EQUALS(13, data_assign._datum5.t2_);
    TS_ASSERT_EQUALS(14, data_assign._datum5.t3_);

    TS_ASSERT_EQUALS(15, data_assign._datum6.t1_);
    TS_ASSERT_EQUALS(16, data_assign._datum6.t2_);
    TS_ASSERT_EQUALS(17, data_assign._datum6.t3_);
    TS_ASSERT_EQUALS(18, data_assign._datum6.t4_);

    //TS_ASSERT(data == data_assign);
    //TS_ASSERT(!(data != data_assign));
  }

  void test_interleaved_datum_7d_assignment_operator()
  {
    id7d_2X3X4X2X3X4X2i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18),
      internal::pod_2<int, int>(19, 20));

    id7d_2X3X4X2X3X4X2i data_assign = data;

    TS_ASSERT_EQUALS(1, data_assign._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_assign._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_assign._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_assign._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_assign._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_assign._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_assign._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_assign._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_assign._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_assign._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_assign._datum4.t2_);

    TS_ASSERT_EQUALS(12, data_assign._datum5.t1_);
    TS_ASSERT_EQUALS(13, data_assign._datum5.t2_);
    TS_ASSERT_EQUALS(14, data_assign._datum5.t3_);

    TS_ASSERT_EQUALS(15, data_assign._datum6.t1_);
    TS_ASSERT_EQUALS(16, data_assign._datum6.t2_);
    TS_ASSERT_EQUALS(17, data_assign._datum6.t3_);
    TS_ASSERT_EQUALS(18, data_assign._datum6.t4_);

    TS_ASSERT_EQUALS(19, data_assign._datum7.t1_);
    TS_ASSERT_EQUALS(20, data_assign._datum7.t2_);

    //TS_ASSERT(data == data_assign);
    //TS_ASSERT(!(data != data_assign));
  }

  void test_interleaved_datum_8d_assignment_operator()
  {
    id8d_2X3X4X2X3X4X2X3i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18),
      internal::pod_2<int, int>(19, 20),
      internal::pod_3<int, int, int>(21, 22, 23));

    id8d_2X3X4X2X3X4X2X3i data_assign = data;

    TS_ASSERT_EQUALS(1, data_assign._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_assign._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_assign._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_assign._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_assign._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_assign._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_assign._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_assign._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_assign._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_assign._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_assign._datum4.t2_);

    TS_ASSERT_EQUALS(12, data_assign._datum5.t1_);
    TS_ASSERT_EQUALS(13, data_assign._datum5.t2_);
    TS_ASSERT_EQUALS(14, data_assign._datum5.t3_);

    TS_ASSERT_EQUALS(15, data_assign._datum6.t1_);
    TS_ASSERT_EQUALS(16, data_assign._datum6.t2_);
    TS_ASSERT_EQUALS(17, data_assign._datum6.t3_);
    TS_ASSERT_EQUALS(18, data_assign._datum6.t4_);

    TS_ASSERT_EQUALS(19, data_assign._datum7.t1_);
    TS_ASSERT_EQUALS(20, data_assign._datum7.t2_);

    TS_ASSERT_EQUALS(21, data_assign._datum8.t1_);
    TS_ASSERT_EQUALS(22, data_assign._datum8.t2_);
    TS_ASSERT_EQUALS(23, data_assign._datum8.t3_);

    //TS_ASSERT(data == data_assign);
    //TS_ASSERT(!(data != data_assign));
  }

  void test_interleaved_datum_9d_assignment_operator()
  {
    id9d_2X3X4X2X3X4X2X3X4i data(
      internal::pod_2<int, int>(1, 2),
      internal::pod_3<int, int, int>(3, 4, 5),
      internal::pod_4<int, int, int, int>(6, 7, 8, 9),
      internal::pod_2<int, int>(10, 11),
      internal::pod_3<int, int, int>(12, 13, 14),
      internal::pod_4<int, int, int, int>(15, 16, 17, 18),
      internal::pod_2<int, int>(19, 20),
      internal::pod_3<int, int, int>(21, 22, 23),
      internal::pod_4<int, int, int, int>(24, 25, 26, 27));

    id9d_2X3X4X2X3X4X2X3X4i data_assign = data;

    TS_ASSERT_EQUALS(1, data_assign._datum1.t1_);
    TS_ASSERT_EQUALS(2, data_assign._datum1.t2_);

    TS_ASSERT_EQUALS(3, data_assign._datum2.t1_);
    TS_ASSERT_EQUALS(4, data_assign._datum2.t2_);
    TS_ASSERT_EQUALS(5, data_assign._datum2.t3_);

    TS_ASSERT_EQUALS(6, data_assign._datum3.t1_);
    TS_ASSERT_EQUALS(7, data_assign._datum3.t2_);
    TS_ASSERT_EQUALS(8, data_assign._datum3.t3_);
    TS_ASSERT_EQUALS(9, data_assign._datum3.t4_);

    TS_ASSERT_EQUALS(10, data_assign._datum4.t1_);
    TS_ASSERT_EQUALS(11, data_assign._datum4.t2_);

    TS_ASSERT_EQUALS(12, data_assign._datum5.t1_);
    TS_ASSERT_EQUALS(13, data_assign._datum5.t2_);
    TS_ASSERT_EQUALS(14, data_assign._datum5.t3_);

    TS_ASSERT_EQUALS(15, data_assign._datum6.t1_);
    TS_ASSERT_EQUALS(16, data_assign._datum6.t2_);
    TS_ASSERT_EQUALS(17, data_assign._datum6.t3_);
    TS_ASSERT_EQUALS(18, data_assign._datum6.t4_);

    TS_ASSERT_EQUALS(19, data_assign._datum7.t1_);
    TS_ASSERT_EQUALS(20, data_assign._datum7.t2_);

    TS_ASSERT_EQUALS(21, data_assign._datum8.t1_);
    TS_ASSERT_EQUALS(22, data_assign._datum8.t2_);
    TS_ASSERT_EQUALS(23, data_assign._datum8.t3_);

    TS_ASSERT_EQUALS(24, data_assign._datum9.t1_);
    TS_ASSERT_EQUALS(25, data_assign._datum9.t2_);
    TS_ASSERT_EQUALS(26, data_assign._datum9.t3_);
    TS_ASSERT_EQUALS(27, data_assign._datum9.t4_);

    //TS_ASSERT(data == data_assign);
    //TS_ASSERT(!(data != data_assign));
  }

  void test_batch_data_default_ctor()
  {
    // 1 attribute
    gl_wrapper::batch_data
    <
      internal::pod_2<int, int>
    > batch1;
    TS_ASSERT(!batch1.get_data1());

    // 2 attribute
    gl_wrapper::batch_data
    <
      internal::pod_2<int, int>, internal::pod_2<int, int>
    > batch2;
    TS_ASSERT(!batch2.get_data1());
    TS_ASSERT(!batch2.get_data2());

    // 3 attribute
    gl_wrapper::batch_data
    <
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch3;
    TS_ASSERT(!batch3.get_data1());
    TS_ASSERT(!batch3.get_data2());
    TS_ASSERT(!batch3.get_data3());

    // 4 attribute
    gl_wrapper::batch_data
    <
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>
    > batch4;
    TS_ASSERT(!batch4.get_data1());
    TS_ASSERT(!batch4.get_data2());
    TS_ASSERT(!batch4.get_data3());
    TS_ASSERT(!batch4.get_data4());

    // 5 attribute
    gl_wrapper::batch_data
    <
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch5;
    TS_ASSERT(!batch5.get_data1());
    TS_ASSERT(!batch5.get_data2());
    TS_ASSERT(!batch5.get_data3());
    TS_ASSERT(!batch5.get_data4());
    TS_ASSERT(!batch5.get_data5());

    // 6 attribute
    gl_wrapper::batch_data
    <
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>
    > batch6;
    TS_ASSERT(!batch6.get_data1());
    TS_ASSERT(!batch6.get_data2());
    TS_ASSERT(!batch6.get_data3());
    TS_ASSERT(!batch6.get_data4());
    TS_ASSERT(!batch6.get_data5());
    TS_ASSERT(!batch6.get_data6());

    // 7 attribute
    gl_wrapper::batch_data
    <
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch7;
    TS_ASSERT(!batch7.get_data1());
    TS_ASSERT(!batch7.get_data2());
    TS_ASSERT(!batch7.get_data3());
    TS_ASSERT(!batch7.get_data4());
    TS_ASSERT(!batch7.get_data5());
    TS_ASSERT(!batch7.get_data6());
    TS_ASSERT(!batch7.get_data7());

    // 8 attribute
    gl_wrapper::batch_data
    <
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>
    > batch8;
    TS_ASSERT(!batch8.get_data1());
    TS_ASSERT(!batch8.get_data2());
    TS_ASSERT(!batch8.get_data3());
    TS_ASSERT(!batch8.get_data4());
    TS_ASSERT(!batch8.get_data5());
    TS_ASSERT(!batch8.get_data6());
    TS_ASSERT(!batch8.get_data7());
    TS_ASSERT(!batch8.get_data8());

    // 9 attribute
    gl_wrapper::batch_data
    <
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>, internal::pod_2<int, int>,
      internal::pod_2<int, int>
    > batch9;
    TS_ASSERT(!batch9.get_data1());
    TS_ASSERT(!batch9.get_data2());
    TS_ASSERT(!batch9.get_data3());
    TS_ASSERT(!batch9.get_data4());
    TS_ASSERT(!batch9.get_data5());
    TS_ASSERT(!batch9.get_data6());
    TS_ASSERT(!batch9.get_data7());
    TS_ASSERT(!batch9.get_data8());
    TS_ASSERT(!batch9.get_data9());
  }

  void test_batch_data_ctor()
  {
    { // 1 attribute
      gl_wrapper::batch_data<internal::pod_2<int, int> >::collection1_type
        data1(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data<internal::pod_2<int, int> > batch(data1, 10);
      TS_ASSERT(batch.get_data1());
    }

    { // 2 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, 10);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
    }

    { // 3 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, 10);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
    }

    { // 4 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, 10);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
    }

    { // 5 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, 10);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
    }

    { // 6 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection6_type data6(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, 10);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
    }

    { // 7 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection6_type data6(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection7_type data7(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, data7, 10);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch.get_data7());
    }

    { // 8 attribute
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, data7, data8, 10);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch.get_data7());
      TS_ASSERT(batch.get_data8());
    }

    { // 9 attribute
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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

      gl_wrapper::batch_data
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
      > batch(data1, data2, data3, data4, data5, data6, data7, data8, data9,
        10);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch.get_data7());
      TS_ASSERT(batch.get_data8());
      TS_ASSERT(batch.get_data9());
    }
  }

  void test_batch_data_copy_ctor()
  {
    { // 1 attribute
      gl_wrapper::batch_data<internal::pod_2<int, int> >::collection1_type
        data1(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data<internal::pod_2<int, int> > batch(data1, 10);
      gl_wrapper::batch_data<internal::pod_2<int, int> > batch_cpy(batch);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 2 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy(batch);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 3 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy(batch);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 4 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy(batch);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 5 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy(batch);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 6 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection6_type data6(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy(batch);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 7 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection6_type data6(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection7_type data7(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, data7, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy(batch);
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch.get_data7());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 8 attribute
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, data7, data8, 10);
      gl_wrapper::batch_data
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
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch.get_data7());
      TS_ASSERT(batch.get_data8());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 9 attribute
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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

      gl_wrapper::batch_data
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
      > batch(data1, data2, data3, data4, data5, data6, data7, data8, data9,
        10);
      gl_wrapper::batch_data
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
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch.get_data7());
      TS_ASSERT(batch.get_data8());
      TS_ASSERT(batch.get_data9());
      TS_ASSERT(batch == batch_cpy);
    }
  }

  void test_batch_data_assignment_opperator()
  {
    { // 1 attribute
      gl_wrapper::batch_data<internal::pod_2<int, int> >::collection1_type
        data1(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data<internal::pod_2<int, int> > batch(data1, 10);
      gl_wrapper::batch_data<internal::pod_2<int, int> > batch_cpy;
      batch_cpy = batch;
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 2 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy;
      batch_cpy = batch;
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 3 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy;
      batch_cpy = batch;
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 4 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy;
      batch_cpy = batch;
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 5 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy;
      batch_cpy = batch;
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 6 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection6_type data6(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, 10);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_cpy;
      batch_cpy = batch;
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 7 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection6_type data6(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection7_type data7(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, data7, 10);
      gl_wrapper::batch_data
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
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch.get_data7());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 8 attribute
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, data7, data8, 10);
      gl_wrapper::batch_data
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
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch.get_data7());
      TS_ASSERT(batch.get_data8());
      TS_ASSERT(batch == batch_cpy);
    }

    { // 9 attribute
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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

      gl_wrapper::batch_data
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
      > batch(data1, data2, data3, data4, data5, data6, data7, data8, data9,
        10);
      gl_wrapper::batch_data
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
      TS_ASSERT(batch.get_data1());
      TS_ASSERT(batch.get_data2());
      TS_ASSERT(batch.get_data3());
      TS_ASSERT(batch.get_data4());
      TS_ASSERT(batch.get_data5());
      TS_ASSERT(batch.get_data6());
      TS_ASSERT(batch.get_data7());
      TS_ASSERT(batch.get_data8());
      TS_ASSERT(batch.get_data9());
      TS_ASSERT(batch == batch_cpy);
    }
  }

  void test_batch_data_get_byte_counts()
  {
    const size_t pod2_size = sizeof(internal::pod_2<int, int>);
    const size_t pod3_size = sizeof(internal::pod_3<int, int, int>);
    const size_t pod4_size = sizeof(internal::pod_4<int, int, int, int>);
    { // 1 attribute
      gl_wrapper::batch_data<internal::pod_2<int, int> >::collection1_type
        data1(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data<internal::pod_2<int, int> > batch_empty;
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_1());
      gl_wrapper::batch_data<internal::pod_2<int, int> > batch(data1, 10);
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_1());
    }

    { // 2 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>
      >::collection2_type data2(new internal::pod_3<int, int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>
      > batch_empty;
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_1());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_2());
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>
      > batch(data1, data2, 10);
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_1());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_2());
    }

    { // 3 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>
      >::collection3_type data3(new internal::pod_4<int, int, int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_empty;
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_1());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_2());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_3());
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>
      > batch(data1, data2, data3, 10);
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_1());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_2());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_3());
    }

    { // 4 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_4<int, int, int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_3<int, int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>
      > batch_empty;
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_1());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_2());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_3());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_4());
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, 10);
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_1());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_2());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_3());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_4());
    }

    { // 5 attribute
      gl_wrapper::batch_data
      <
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_4<int, int, int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_3<int, int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_4<int, int, int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_2<int, int>
      > batch_empty;
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_1());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_2());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_3());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_4());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_5());
      gl_wrapper::batch_data
      <
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, 10);
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_1());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_2());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_3());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_4());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_5());
    }

    { // 6 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_3<int, int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection6_type data6(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_empty;
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_1());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_2());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_3());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_4());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_5());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_6());
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, 10);
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_1());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_2());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_3());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_4());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_5());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_6());
    }

    { // 7 attribute
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection1_type data1(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection2_type data2(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection3_type data3(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection4_type data4(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection5_type data5(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection6_type data6(new internal::pod_2<int, int>[10]);
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      >::collection7_type data7(new internal::pod_2<int, int>[10]);

      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch_empty;
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_1());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_2());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_3());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_4());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_5());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_6());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_7());
      gl_wrapper::batch_data
      <
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>,
        internal::pod_2<int, int>
      > batch(data1, data2, data3, data4, data5, data6, data7, 10);
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_1());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_2());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_3());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_4());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_5());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_6());
      TS_ASSERT_EQUALS(10 * pod2_size, batch.get_bytecount_7());
    }

    { // 8 attribute
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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

      gl_wrapper::batch_data
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
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_1());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_2());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_3());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_4());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_5());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_6());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_7());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_8());
      gl_wrapper::batch_data
      <
        internal::pod_3<int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_3<int, int, int>
      > batch(data1, data2, data3, data4, data5, data6, data7, data8, 10);
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_1());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_2());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_3());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_4());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_5());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_6());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_7());
      TS_ASSERT_EQUALS(10 * pod3_size, batch.get_bytecount_8());
    }

    { // 9 attribute
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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
      gl_wrapper::batch_data
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

      gl_wrapper::batch_data
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
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_1());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_2());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_3());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_4());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_5());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_6());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_7());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_8());
      TS_ASSERT_EQUALS(0, batch_empty.get_bytecount_9());
      gl_wrapper::batch_data
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
      > batch(data1, data2, data3, data4, data5, data6, data7, data8, data9,
        10);
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_1());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_2());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_3());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_4());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_5());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_6());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_7());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_8());
      TS_ASSERT_EQUALS(10 * pod4_size, batch.get_bytecount_9());
    }
  }

  // interleaved_data unit tests
  void test_interleaved_data_default_ctor()
  {
    { // 2 attributes
      typedef gl_wrapper::interleaved_data
      <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>
      > interleaved2;
      interleaved2 data;
      TS_ASSERT(!(data.get_data().get()));
      TS_ASSERT_EQUALS(0, data.get_attribute_count());
      TS_ASSERT_EQUALS(0, data.get_byte_count());
      TS_ASSERT_EQUALS(8, interleaved2::traits::type1_sizeof);
      TS_ASSERT_EQUALS(12, interleaved2::traits::type2_sizeof);
      TS_ASSERT_EQUALS(20, interleaved2::traits::stride);
      TS_ASSERT_EQUALS(2, interleaved2::traits::type1_dimension);
      TS_ASSERT_EQUALS(3, interleaved2::traits::type2_dimension);
      TS_ASSERT_EQUALS(5, interleaved2::traits::attribute_val_count);
      TS_ASSERT_EQUALS(0, interleaved2::traits::type1_byte_offset);
      TS_ASSERT_EQUALS(8, interleaved2::traits::type2_byte_offset);
    }

    { // 3 attributes
      typedef gl_wrapper::interleaved_data
      <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>
      > interleaved3;
      interleaved3 data;
      TS_ASSERT(!(data.get_data().get()));
      TS_ASSERT_EQUALS(0, data.get_attribute_count());
      TS_ASSERT_EQUALS(0, data.get_byte_count());
      TS_ASSERT_EQUALS(8, interleaved3::traits::type1_sizeof);
      TS_ASSERT_EQUALS(12, interleaved3::traits::type2_sizeof);
      TS_ASSERT_EQUALS(16, interleaved3::traits::type3_sizeof);
      TS_ASSERT_EQUALS(36, interleaved3::traits::stride);
      TS_ASSERT_EQUALS(2, interleaved3::traits::type1_dimension);
      TS_ASSERT_EQUALS(3, interleaved3::traits::type2_dimension);
      TS_ASSERT_EQUALS(4, interleaved3::traits::type3_dimension);
      TS_ASSERT_EQUALS(9, interleaved3::traits::attribute_val_count);
      TS_ASSERT_EQUALS(0, interleaved3::traits::type1_byte_offset);
      TS_ASSERT_EQUALS(8, interleaved3::traits::type2_byte_offset);
      TS_ASSERT_EQUALS(20, interleaved3::traits::type3_byte_offset);
    }

    { // 4 attributes
      typedef gl_wrapper::interleaved_data
        <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>
        > interleaved4;
      interleaved4 data;
      TS_ASSERT(!(data.get_data().get()));
      TS_ASSERT_EQUALS(0, data.get_attribute_count());
      TS_ASSERT_EQUALS(0, data.get_byte_count());
      TS_ASSERT_EQUALS(8, interleaved4::traits::type1_sizeof);
      TS_ASSERT_EQUALS(12, interleaved4::traits::type2_sizeof);
      TS_ASSERT_EQUALS(16, interleaved4::traits::type3_sizeof);
      TS_ASSERT_EQUALS(12, interleaved4::traits::type4_sizeof);
      TS_ASSERT_EQUALS(48, interleaved4::traits::stride);
      TS_ASSERT_EQUALS(2, interleaved4::traits::type1_dimension);
      TS_ASSERT_EQUALS(3, interleaved4::traits::type2_dimension);
      TS_ASSERT_EQUALS(4, interleaved4::traits::type3_dimension);
      TS_ASSERT_EQUALS(3, interleaved4::traits::type4_dimension);
      TS_ASSERT_EQUALS(12, interleaved4::traits::attribute_val_count);
      TS_ASSERT_EQUALS(0, interleaved4::traits::type1_byte_offset);
      TS_ASSERT_EQUALS(8, interleaved4::traits::type2_byte_offset);
      TS_ASSERT_EQUALS(20, interleaved4::traits::type3_byte_offset);
      TS_ASSERT_EQUALS(36, interleaved4::traits::type4_byte_offset);
    }

    { // 5 attributes
      typedef gl_wrapper::interleaved_data
        <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>
        > interleaved5;
      interleaved5 data;
      TS_ASSERT(!(data.get_data().get()));
      TS_ASSERT_EQUALS(0, data.get_attribute_count());
      TS_ASSERT_EQUALS(0, data.get_byte_count());
      TS_ASSERT_EQUALS(8, interleaved5::traits::type1_sizeof);
      TS_ASSERT_EQUALS(12, interleaved5::traits::type2_sizeof);
      TS_ASSERT_EQUALS(16, interleaved5::traits::type3_sizeof);
      TS_ASSERT_EQUALS(12, interleaved5::traits::type4_sizeof);
      TS_ASSERT_EQUALS(16, interleaved5::traits::type5_sizeof);
      TS_ASSERT_EQUALS(64, interleaved5::traits::stride);
      TS_ASSERT_EQUALS(2, interleaved5::traits::type1_dimension);
      TS_ASSERT_EQUALS(3, interleaved5::traits::type2_dimension);
      TS_ASSERT_EQUALS(4, interleaved5::traits::type3_dimension);
      TS_ASSERT_EQUALS(3, interleaved5::traits::type4_dimension);
      TS_ASSERT_EQUALS(4, interleaved5::traits::type5_dimension);
      TS_ASSERT_EQUALS(16, interleaved5::traits::attribute_val_count);
      TS_ASSERT_EQUALS(0, interleaved5::traits::type1_byte_offset);
      TS_ASSERT_EQUALS(8, interleaved5::traits::type2_byte_offset);
      TS_ASSERT_EQUALS(20, interleaved5::traits::type3_byte_offset);
      TS_ASSERT_EQUALS(36, interleaved5::traits::type4_byte_offset);
      TS_ASSERT_EQUALS(48, interleaved5::traits::type5_byte_offset);
    }

    { // 6 attributes
      typedef gl_wrapper::interleaved_data
        <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_2<int, int>
        > interleaved6;
      interleaved6 data;
      TS_ASSERT(!(data.get_data().get()));
      TS_ASSERT_EQUALS(0, data.get_attribute_count());
      TS_ASSERT_EQUALS(0, data.get_byte_count());
      TS_ASSERT_EQUALS(8, interleaved6::traits::type1_sizeof);
      TS_ASSERT_EQUALS(12, interleaved6::traits::type2_sizeof);
      TS_ASSERT_EQUALS(16, interleaved6::traits::type3_sizeof);
      TS_ASSERT_EQUALS(12, interleaved6::traits::type4_sizeof);
      TS_ASSERT_EQUALS(16, interleaved6::traits::type5_sizeof);
      TS_ASSERT_EQUALS(8, interleaved6::traits::type6_sizeof);
      TS_ASSERT_EQUALS(72, interleaved6::traits::stride);
      TS_ASSERT_EQUALS(2, interleaved6::traits::type1_dimension);
      TS_ASSERT_EQUALS(3, interleaved6::traits::type2_dimension);
      TS_ASSERT_EQUALS(4, interleaved6::traits::type3_dimension);
      TS_ASSERT_EQUALS(3, interleaved6::traits::type4_dimension);
      TS_ASSERT_EQUALS(4, interleaved6::traits::type5_dimension);
      TS_ASSERT_EQUALS(2, interleaved6::traits::type6_dimension);
      TS_ASSERT_EQUALS(18, interleaved6::traits::attribute_val_count);
      TS_ASSERT_EQUALS(0, interleaved6::traits::type1_byte_offset);
      TS_ASSERT_EQUALS(8, interleaved6::traits::type2_byte_offset);
      TS_ASSERT_EQUALS(20, interleaved6::traits::type3_byte_offset);
      TS_ASSERT_EQUALS(36, interleaved6::traits::type4_byte_offset);
      TS_ASSERT_EQUALS(48, interleaved6::traits::type5_byte_offset);
      TS_ASSERT_EQUALS(64, interleaved6::traits::type6_byte_offset);
    }

    { // 7 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(!(data.get_data().get()));
      TS_ASSERT_EQUALS(0, data.get_attribute_count());
      TS_ASSERT_EQUALS(0, data.get_byte_count());
      TS_ASSERT_EQUALS(8, interleaved7::traits::type1_sizeof);
      TS_ASSERT_EQUALS(12, interleaved7::traits::type2_sizeof);
      TS_ASSERT_EQUALS(16, interleaved7::traits::type3_sizeof);
      TS_ASSERT_EQUALS(12, interleaved7::traits::type4_sizeof);
      TS_ASSERT_EQUALS(16, interleaved7::traits::type5_sizeof);
      TS_ASSERT_EQUALS(8, interleaved7::traits::type6_sizeof);
      TS_ASSERT_EQUALS(12, interleaved7::traits::type7_sizeof);
      TS_ASSERT_EQUALS(84, interleaved7::traits::stride);
      TS_ASSERT_EQUALS(2, interleaved7::traits::type1_dimension);
      TS_ASSERT_EQUALS(3, interleaved7::traits::type2_dimension);
      TS_ASSERT_EQUALS(4, interleaved7::traits::type3_dimension);
      TS_ASSERT_EQUALS(3, interleaved7::traits::type4_dimension);
      TS_ASSERT_EQUALS(4, interleaved7::traits::type5_dimension);
      TS_ASSERT_EQUALS(2, interleaved7::traits::type6_dimension);
      TS_ASSERT_EQUALS(3, interleaved7::traits::type7_dimension);
      TS_ASSERT_EQUALS(21, interleaved7::traits::attribute_val_count);
      TS_ASSERT_EQUALS(0, interleaved7::traits::type1_byte_offset);
      TS_ASSERT_EQUALS(8, interleaved7::traits::type2_byte_offset);
      TS_ASSERT_EQUALS(20, interleaved7::traits::type3_byte_offset);
      TS_ASSERT_EQUALS(36, interleaved7::traits::type4_byte_offset);
      TS_ASSERT_EQUALS(48, interleaved7::traits::type5_byte_offset);
      TS_ASSERT_EQUALS(64, interleaved7::traits::type6_byte_offset);
      TS_ASSERT_EQUALS(72, interleaved7::traits::type7_byte_offset);
    }

    { // 8 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(!(data.get_data().get()));
      TS_ASSERT_EQUALS(0, data.get_attribute_count());
      TS_ASSERT_EQUALS(0, data.get_byte_count());
      TS_ASSERT_EQUALS(8, interleaved8::traits::type1_sizeof);
      TS_ASSERT_EQUALS(12, interleaved8::traits::type2_sizeof);
      TS_ASSERT_EQUALS(16, interleaved8::traits::type3_sizeof);
      TS_ASSERT_EQUALS(12, interleaved8::traits::type4_sizeof);
      TS_ASSERT_EQUALS(16, interleaved8::traits::type5_sizeof);
      TS_ASSERT_EQUALS(8, interleaved8::traits::type6_sizeof);
      TS_ASSERT_EQUALS(12, interleaved8::traits::type7_sizeof);
      TS_ASSERT_EQUALS(16, interleaved8::traits::type8_sizeof);
      TS_ASSERT_EQUALS(100, interleaved8::traits::stride);
      TS_ASSERT_EQUALS(2, interleaved8::traits::type1_dimension);
      TS_ASSERT_EQUALS(3, interleaved8::traits::type2_dimension);
      TS_ASSERT_EQUALS(4, interleaved8::traits::type3_dimension);
      TS_ASSERT_EQUALS(3, interleaved8::traits::type4_dimension);
      TS_ASSERT_EQUALS(4, interleaved8::traits::type5_dimension);
      TS_ASSERT_EQUALS(2, interleaved8::traits::type6_dimension);
      TS_ASSERT_EQUALS(3, interleaved8::traits::type7_dimension);
      TS_ASSERT_EQUALS(4, interleaved8::traits::type8_dimension);
      TS_ASSERT_EQUALS(25, interleaved8::traits::attribute_val_count);
      TS_ASSERT_EQUALS(0, interleaved8::traits::type1_byte_offset);
      TS_ASSERT_EQUALS(8, interleaved8::traits::type2_byte_offset);
      TS_ASSERT_EQUALS(20, interleaved8::traits::type3_byte_offset);
      TS_ASSERT_EQUALS(36, interleaved8::traits::type4_byte_offset);
      TS_ASSERT_EQUALS(48, interleaved8::traits::type5_byte_offset);
      TS_ASSERT_EQUALS(64, interleaved8::traits::type6_byte_offset);
      TS_ASSERT_EQUALS(72, interleaved8::traits::type7_byte_offset);
      TS_ASSERT_EQUALS(84, interleaved8::traits::type8_byte_offset);
    }

    { // 9 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(!(data.get_data().get()));
      TS_ASSERT_EQUALS(0, data.get_attribute_count());
      TS_ASSERT_EQUALS(0, data.get_byte_count());
      TS_ASSERT_EQUALS(8, interleaved9::traits::type1_sizeof);
      TS_ASSERT_EQUALS(12, interleaved9::traits::type2_sizeof);
      TS_ASSERT_EQUALS(16, interleaved9::traits::type3_sizeof);
      TS_ASSERT_EQUALS(12, interleaved9::traits::type4_sizeof);
      TS_ASSERT_EQUALS(16, interleaved9::traits::type5_sizeof);
      TS_ASSERT_EQUALS(8, interleaved9::traits::type6_sizeof);
      TS_ASSERT_EQUALS(12, interleaved9::traits::type7_sizeof);
      TS_ASSERT_EQUALS(16, interleaved9::traits::type8_sizeof);
      TS_ASSERT_EQUALS(8, interleaved9::traits::type9_sizeof);
      TS_ASSERT_EQUALS(108, interleaved9::traits::stride);
      TS_ASSERT_EQUALS(2, interleaved9::traits::type1_dimension);
      TS_ASSERT_EQUALS(3, interleaved9::traits::type2_dimension);
      TS_ASSERT_EQUALS(4, interleaved9::traits::type3_dimension);
      TS_ASSERT_EQUALS(3, interleaved9::traits::type4_dimension);
      TS_ASSERT_EQUALS(4, interleaved9::traits::type5_dimension);
      TS_ASSERT_EQUALS(2, interleaved9::traits::type6_dimension);
      TS_ASSERT_EQUALS(3, interleaved9::traits::type7_dimension);
      TS_ASSERT_EQUALS(4, interleaved9::traits::type8_dimension);
      TS_ASSERT_EQUALS(2, interleaved9::traits::type9_dimension);
      TS_ASSERT_EQUALS(27, interleaved9::traits::attribute_val_count);
      TS_ASSERT_EQUALS(0, interleaved9::traits::type1_byte_offset);
      TS_ASSERT_EQUALS(8, interleaved9::traits::type2_byte_offset);
      TS_ASSERT_EQUALS(20, interleaved9::traits::type3_byte_offset);
      TS_ASSERT_EQUALS(36, interleaved9::traits::type4_byte_offset);
      TS_ASSERT_EQUALS(48, interleaved9::traits::type5_byte_offset);
      TS_ASSERT_EQUALS(64, interleaved9::traits::type6_byte_offset);
      TS_ASSERT_EQUALS(72, interleaved9::traits::type7_byte_offset);
      TS_ASSERT_EQUALS(84, interleaved9::traits::type8_byte_offset);
      TS_ASSERT_EQUALS(100, interleaved9::traits::type9_byte_offset);
    }
  }

  void test_interleaved_data_ctor()
  {
    { // 2 attributes
      typedef gl_wrapper::interleaved_data
      <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>
      > interleaved2;
      interleaved2::collection_type idata(new interleaved2::datum_type[10]);
      interleaved2 data(idata, 10);
      TS_ASSERT((data.get_data().get()));
      TS_ASSERT_EQUALS(10, data.get_attribute_count());
      TS_ASSERT_EQUALS(200, data.get_byte_count());
    }

    { // 3 attributes
      typedef gl_wrapper::interleaved_data
      <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>
      > interleaved3;
      interleaved3::collection_type idata(new interleaved3::datum_type[20]);
      interleaved3 data(idata, 20);
      TS_ASSERT((data.get_data().get()));
      TS_ASSERT_EQUALS(20, data.get_attribute_count());
      TS_ASSERT_EQUALS(720, data.get_byte_count());
    }

    { // 4 attributes
      typedef gl_wrapper::interleaved_data
        <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>
        > interleaved4;
      interleaved4::collection_type idata(new interleaved4::datum_type[15]);
      interleaved4 data(idata, 15);
      TS_ASSERT((data.get_data().get()));
      TS_ASSERT_EQUALS(15, data.get_attribute_count());
      TS_ASSERT_EQUALS(720, data.get_byte_count());
    }

    { // 5 attributes
      typedef gl_wrapper::interleaved_data
        <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>
        > interleaved5;
      interleaved5::collection_type idata(new interleaved5::datum_type[2]);
      interleaved5 data(idata, 2);
      TS_ASSERT((data.get_data().get()));
      TS_ASSERT_EQUALS(2, data.get_attribute_count());
      TS_ASSERT_EQUALS(128, data.get_byte_count());
    }

    { // 6 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT((data.get_data().get()));
      TS_ASSERT_EQUALS(500, data.get_attribute_count());
      TS_ASSERT_EQUALS(36000, data.get_byte_count());
    }

    { // 7 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT((data.get_data().get()));
      TS_ASSERT_EQUALS(33, data.get_attribute_count());
      TS_ASSERT_EQUALS(2772, data.get_byte_count());
    }

    { // 8 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT((data.get_data().get()));
      TS_ASSERT_EQUALS(96, data.get_attribute_count());
      TS_ASSERT_EQUALS(9600, data.get_byte_count());
    }

    { // 9 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT((data.get_data().get()));
      TS_ASSERT_EQUALS(1333, data.get_attribute_count());
      TS_ASSERT_EQUALS(143964, data.get_byte_count());
    }
  }

  void test_interleaved_data_copy_ctor()
  {
    { // 2 attributes
      typedef gl_wrapper::interleaved_data
        <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>
        > interleaved2;
      interleaved2::collection_type idata(new interleaved2::datum_type[10]);
      interleaved2 data(idata, 10);
      interleaved2 data_copy(data);
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 3 attributes
      typedef gl_wrapper::interleaved_data
        <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>
        > interleaved3;
      interleaved3::collection_type idata(new interleaved3::datum_type[20]);
      interleaved3 data(idata, 20);
      interleaved3 data_copy(data);
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 4 attributes
      typedef gl_wrapper::interleaved_data
        <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>,
        internal::pod_3<int, int, int>
        > interleaved4;
      interleaved4::collection_type idata(new interleaved4::datum_type[15]);
      interleaved4 data(idata, 15);
      interleaved4 data_copy(data);
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 5 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 6 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 7 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 8 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 9 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }
  }

  void test_interleaved_data_assignment_operator()
  {
    { // 2 attributes
      typedef gl_wrapper::interleaved_data
        <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>
        > interleaved2;
      interleaved2::collection_type idata(new interleaved2::datum_type[10]);
      interleaved2 data(idata, 10);
      interleaved2 data_copy;
      data_copy = data;
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 3 attributes
      typedef gl_wrapper::interleaved_data
        <
        internal::pod_2<int, int>,
        internal::pod_3<int, int, int>,
        internal::pod_4<int, int, int, int>
        > interleaved3;
      interleaved3::collection_type idata(new interleaved3::datum_type[20]);
      interleaved3 data(idata, 20);
      interleaved3 data_copy(data);
      data_copy = data;
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 4 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 5 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 6 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 7 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 8 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }

    { // 9 attributes
      typedef gl_wrapper::interleaved_data
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
      TS_ASSERT(data_copy == data);
      TS_ASSERT(data_copy.get_attribute_count() == data.get_attribute_count());
    }
  }
};

#endif
