#include "test_mesh_types.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

/*! \brief This is a test for the default ctor in the interleaved_datum_2d
 * interleaved_datum_3d ... interleaved_datum_10d classes. To ensure
 * interleaved datum calls default constructor with defined behavior.
 */
void test_default_interleaved_datum_2d_constructor()
{
  test_mesh_types::id2d_2X3i data;

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t3_);
}

void test_default_interleaved_datum_3d_constructor()
{
  test_mesh_types::id3d_2X3X4i data;

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t4_);
}

void test_default_interleaved_datum_4d_constructor()
{
  test_mesh_types::id4d_2X3X4X2i data;

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t2_);
}

void test_default_interleaved_datum_5d_constructor()
{
  test_mesh_types::id5d_2X3X4X2X3i data;

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t3_);
}

void test_default_interleaved_datum_6d_constructor()
{
  test_mesh_types::id6d_2X3X4X2X3X4i data;

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t4_);
}

void test_default_interleaved_datum_7d_constructor()
{
  test_mesh_types::id7d_2X3X4X2X3X4X2i data;

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum7.t2_);
}

void test_default_interleaved_datum_8d_constructor()
{
  test_mesh_types::id8d_2X3X4X2X3X4X2X3i data;

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum7.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum8.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum8.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum8.t3_);
}

void test_default_interleaved_datum_9d_constructor()
{
  test_mesh_types::id9d_2X3X4X2X3X4X2X3X4i data;

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum7.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum8.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum8.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum8.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum9.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum9.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum9.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(0, data._datum9.t4_);
}

/*! \brief This is a test for the ctor in the interleaved_datum_2d
 * interleaved_datum_3d ... interleaved_datum_10d classes.
 */
void test_interleaved_datum_2d_constructor()
{
  test_mesh_types::id2d_2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5));

  OPENGL_GRAPHICS_ASSERT_EQ(1, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data._datum2.t3_);
}

void test_interleaved_datum_3d_constructor()
{
  test_mesh_types::id3d_2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9));

  OPENGL_GRAPHICS_ASSERT_EQ(1, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data._datum3.t4_);
}

void test_interleaved_datum_4d_constructor()
{
  test_mesh_types::id4d_2X3X4X2i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11));

  OPENGL_GRAPHICS_ASSERT_EQ(1, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data._datum4.t2_);
}

void test_interleaved_datum_5d_constructor()
{
  test_mesh_types::id5d_2X3X4X2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14));

  OPENGL_GRAPHICS_ASSERT_EQ(1, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data._datum5.t3_);
}

void test_interleaved_datum_6d_constructor()
{
  test_mesh_types::id6d_2X3X4X2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18));

  OPENGL_GRAPHICS_ASSERT_EQ(1, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data._datum6.t4_);
}

void test_interleaved_datum_7d_constructor()
{
  test_mesh_types::id7d_2X3X4X2X3X4X2i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18),
    internal::pod_2<int, int>(19, 20));

  OPENGL_GRAPHICS_ASSERT_EQ(1, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(19, data._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(20, data._datum7.t2_);
}

void test_interleaved_datum_8d_constructor()
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

  OPENGL_GRAPHICS_ASSERT_EQ(1, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(19, data._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(20, data._datum7.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(21, data._datum8.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(22, data._datum8.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(23, data._datum8.t3_);
}

void test_interleaved_datum_9d_constructor()
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

  OPENGL_GRAPHICS_ASSERT_EQ(1, data._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(19, data._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(20, data._datum7.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(21, data._datum8.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(22, data._datum8.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(23, data._datum8.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(24, data._datum9.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(25, data._datum9.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(26, data._datum9.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(27, data._datum9.t4_);
}

/*! \brief This is a test for the copy ctor in the interleaved_datum_2d
 * interleaved_datum_3d ... interleaved_datum_10d classes.
 */
void test_interleaved_datum_2d_copy_constructor()
{
  test_mesh_types::id2d_2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5));

  test_mesh_types::id2d_2X3i data_copy(data);

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_copy._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_copy._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_copy._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_copy._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_copy._datum2.t3_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_copy);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_copy));
}

void test_interleaved_datum_3d_copy_constructor()
{
  test_mesh_types::id3d_2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9));

  test_mesh_types::id3d_2X3X4i data_copy(data);

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_copy._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_copy._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_copy._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_copy._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_copy._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_copy._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_copy._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_copy._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_copy._datum3.t4_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_copy);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_copy));
}

void test_interleaved_datum_4d_copy_constructor()
{
  test_mesh_types::id4d_2X3X4X2i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11));

  test_mesh_types::id4d_2X3X4X2i data_copy(data);

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_copy._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_copy._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_copy._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_copy._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_copy._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_copy._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_copy._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_copy._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_copy._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_copy._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_copy._datum4.t2_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_copy);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_copy));
}

void test_interleaved_datum_5d_copy_constructor()
{
  test_mesh_types::id5d_2X3X4X2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14));

  test_mesh_types::id5d_2X3X4X2X3i data_copy(data);

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_copy._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_copy._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_copy._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_copy._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_copy._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_copy._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_copy._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_copy._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_copy._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_copy._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_copy._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data_copy._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data_copy._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data_copy._datum5.t3_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_copy);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_copy));
}

void test_interleaved_datum_6d_copy_constructor()
{
  test_mesh_types::id6d_2X3X4X2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18));

  test_mesh_types::id6d_2X3X4X2X3X4i data_copy(data);

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_copy._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_copy._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_copy._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_copy._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_copy._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_copy._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_copy._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_copy._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_copy._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_copy._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_copy._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data_copy._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data_copy._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data_copy._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data_copy._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data_copy._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data_copy._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data_copy._datum6.t4_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_copy);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_copy));
}

void test_interleaved_datum_7d_copy_constructor()
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

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_copy._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_copy._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_copy._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_copy._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_copy._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_copy._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_copy._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_copy._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_copy._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_copy._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_copy._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data_copy._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data_copy._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data_copy._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data_copy._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data_copy._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data_copy._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data_copy._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(19, data_copy._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(20, data_copy._datum7.t2_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_copy);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_copy));
}

void test_interleaved_datum_8d_copy_constructor()
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

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_copy._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_copy._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_copy._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_copy._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_copy._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_copy._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_copy._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_copy._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_copy._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_copy._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_copy._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data_copy._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data_copy._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data_copy._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data_copy._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data_copy._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data_copy._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data_copy._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(19, data_copy._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(20, data_copy._datum7.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(21, data_copy._datum8.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(22, data_copy._datum8.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(23, data_copy._datum8.t3_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_copy);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_copy));
}

void test_interleaved_datum_9d_copy_constructor()
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

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_copy._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_copy._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_copy._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_copy._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_copy._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_copy._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_copy._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_copy._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_copy._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_copy._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_copy._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data_copy._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data_copy._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data_copy._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data_copy._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data_copy._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data_copy._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data_copy._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(19, data_copy._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(20, data_copy._datum7.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(21, data_copy._datum8.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(22, data_copy._datum8.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(23, data_copy._datum8.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(24, data_copy._datum9.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(25, data_copy._datum9.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(26, data_copy._datum9.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(27, data_copy._datum9.t4_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_copy);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_copy));
}

/*! \brief This is a test for the assignment operator in the
 * interleaved_datum_2d interleaved_datum_3d ... interleaved_datum_10d
 * classes.
 */
void test_interleaved_datum_2d_assignment_operator()
{
  test_mesh_types::id2d_2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5));

  test_mesh_types::id2d_2X3i data_assign = data;

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_assign._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_assign._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_assign._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_assign._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_assign._datum2.t3_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_assign);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_assign));
}

void test_interleaved_datum_3d_assignment_operator()
{
  test_mesh_types::id3d_2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9));

  test_mesh_types::id3d_2X3X4i data_assign = data;

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_assign._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_assign._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_assign._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_assign._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_assign._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_assign._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_assign._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_assign._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_assign._datum3.t4_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_assign);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_assign));
}

void test_interleaved_datum_4d_assignment_operator()
{
  test_mesh_types::id4d_2X3X4X2i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11));

  test_mesh_types::id4d_2X3X4X2i data_assign = data;

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_assign._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_assign._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_assign._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_assign._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_assign._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_assign._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_assign._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_assign._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_assign._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_assign._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_assign._datum4.t2_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_assign);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_assign));
}

void test_interleaved_datum_5d_assignment_operator()
{
  test_mesh_types::id5d_2X3X4X2X3i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14));

  test_mesh_types::id5d_2X3X4X2X3i data_assign = data;

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_assign._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_assign._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_assign._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_assign._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_assign._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_assign._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_assign._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_assign._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_assign._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_assign._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_assign._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data_assign._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data_assign._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data_assign._datum5.t3_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_assign);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_assign));
}

void test_interleaved_datum_6d_assignment_operator()
{
  test_mesh_types::id6d_2X3X4X2X3X4i data(
    internal::pod_2<int, int>(1, 2),
    internal::pod_3<int, int, int>(3, 4, 5),
    internal::pod_4<int, int, int, int>(6, 7, 8, 9),
    internal::pod_2<int, int>(10, 11),
    internal::pod_3<int, int, int>(12, 13, 14),
    internal::pod_4<int, int, int, int>(15, 16, 17, 18));

  test_mesh_types::id6d_2X3X4X2X3X4i data_assign = data;

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_assign._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_assign._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_assign._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_assign._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_assign._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_assign._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_assign._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_assign._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_assign._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_assign._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_assign._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data_assign._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data_assign._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data_assign._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data_assign._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data_assign._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data_assign._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data_assign._datum6.t4_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_assign);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_assign));
}

void test_interleaved_datum_7d_assignment_operator()
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

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_assign._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_assign._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_assign._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_assign._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_assign._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_assign._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_assign._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_assign._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_assign._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_assign._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_assign._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data_assign._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data_assign._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data_assign._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data_assign._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data_assign._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data_assign._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data_assign._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(19, data_assign._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(20, data_assign._datum7.t2_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_assign);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_assign));
}

void test_interleaved_datum_8d_assignment_operator()
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

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_assign._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_assign._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_assign._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_assign._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_assign._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_assign._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_assign._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_assign._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_assign._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_assign._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_assign._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data_assign._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data_assign._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data_assign._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data_assign._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data_assign._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data_assign._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data_assign._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(19, data_assign._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(20, data_assign._datum7.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(21, data_assign._datum8.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(22, data_assign._datum8.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(23, data_assign._datum8.t3_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_assign);
  //OPENGL_GRAPHICS_ASSERT_EQ(!(data != data_assign));
}

void test_interleaved_datum_9d_assignment_operator()
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

  OPENGL_GRAPHICS_ASSERT_EQ(1, data_assign._datum1.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(2, data_assign._datum1.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(3, data_assign._datum2.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(4, data_assign._datum2.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(5, data_assign._datum2.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(6, data_assign._datum3.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(7, data_assign._datum3.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(8, data_assign._datum3.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(9, data_assign._datum3.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(10, data_assign._datum4.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(11, data_assign._datum4.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(12, data_assign._datum5.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(13, data_assign._datum5.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(14, data_assign._datum5.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(15, data_assign._datum6.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(16, data_assign._datum6.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(17, data_assign._datum6.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(18, data_assign._datum6.t4_);

  OPENGL_GRAPHICS_ASSERT_EQ(19, data_assign._datum7.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(20, data_assign._datum7.t2_);

  OPENGL_GRAPHICS_ASSERT_EQ(21, data_assign._datum8.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(22, data_assign._datum8.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(23, data_assign._datum8.t3_);

  OPENGL_GRAPHICS_ASSERT_EQ(24, data_assign._datum9.t1_);
  OPENGL_GRAPHICS_ASSERT_EQ(25, data_assign._datum9.t2_);
  OPENGL_GRAPHICS_ASSERT_EQ(26, data_assign._datum9.t3_);
  OPENGL_GRAPHICS_ASSERT_EQ(27, data_assign._datum9.t4_);

  //OPENGL_GRAPHICS_ASSERT_EQ(data, data_assign);
  //OPENGL_GRAPHICS_ASSERT(!(data != data_assign));
}

void test_batch_data_default_ctor()
{
  // 1 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>
  > batch1;
  OPENGL_GRAPHICS_ASSERT(!batch1.get_data1());

  // 2 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>
  > batch2;
  OPENGL_GRAPHICS_ASSERT(!batch2.get_data1());
  OPENGL_GRAPHICS_ASSERT(!batch2.get_data2());

  // 3 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>
  > batch3;
  OPENGL_GRAPHICS_ASSERT(!batch3.get_data1());
  OPENGL_GRAPHICS_ASSERT(!batch3.get_data2());
  OPENGL_GRAPHICS_ASSERT(!batch3.get_data3());

  // 4 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>
  > batch4;
  OPENGL_GRAPHICS_ASSERT(!batch4.get_data1());
  OPENGL_GRAPHICS_ASSERT(!batch4.get_data2());
  OPENGL_GRAPHICS_ASSERT(!batch4.get_data3());
  OPENGL_GRAPHICS_ASSERT(!batch4.get_data4());

  // 5 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>
  > batch5;
  OPENGL_GRAPHICS_ASSERT(!batch5.get_data1());
  OPENGL_GRAPHICS_ASSERT(!batch5.get_data2());
  OPENGL_GRAPHICS_ASSERT(!batch5.get_data3());
  OPENGL_GRAPHICS_ASSERT(!batch5.get_data4());
  OPENGL_GRAPHICS_ASSERT(!batch5.get_data5());

  // 6 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>
  > batch6;
  OPENGL_GRAPHICS_ASSERT(!batch6.get_data1());
  OPENGL_GRAPHICS_ASSERT(!batch6.get_data2());
  OPENGL_GRAPHICS_ASSERT(!batch6.get_data3());
  OPENGL_GRAPHICS_ASSERT(!batch6.get_data4());
  OPENGL_GRAPHICS_ASSERT(!batch6.get_data5());
  OPENGL_GRAPHICS_ASSERT(!batch6.get_data6());

  // 7 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>
  > batch7;
  OPENGL_GRAPHICS_ASSERT(!batch7.get_data1());
  OPENGL_GRAPHICS_ASSERT(!batch7.get_data2());
  OPENGL_GRAPHICS_ASSERT(!batch7.get_data3());
  OPENGL_GRAPHICS_ASSERT(!batch7.get_data4());
  OPENGL_GRAPHICS_ASSERT(!batch7.get_data5());
  OPENGL_GRAPHICS_ASSERT(!batch7.get_data6());
  OPENGL_GRAPHICS_ASSERT(!batch7.get_data7());

  // 8 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>
  > batch8;
  OPENGL_GRAPHICS_ASSERT(!batch8.get_data1());
  OPENGL_GRAPHICS_ASSERT(!batch8.get_data2());
  OPENGL_GRAPHICS_ASSERT(!batch8.get_data3());
  OPENGL_GRAPHICS_ASSERT(!batch8.get_data4());
  OPENGL_GRAPHICS_ASSERT(!batch8.get_data5());
  OPENGL_GRAPHICS_ASSERT(!batch8.get_data6());
  OPENGL_GRAPHICS_ASSERT(!batch8.get_data7());
  OPENGL_GRAPHICS_ASSERT(!batch8.get_data8());

  // 9 attribute
  opengl_graphics::batch_data
  <
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>, internal::pod_2<int, int>,
    internal::pod_2<int, int>
  > batch9;
  OPENGL_GRAPHICS_ASSERT(!batch9.get_data1());
  OPENGL_GRAPHICS_ASSERT(!batch9.get_data2());
  OPENGL_GRAPHICS_ASSERT(!batch9.get_data3());
  OPENGL_GRAPHICS_ASSERT(!batch9.get_data4());
  OPENGL_GRAPHICS_ASSERT(!batch9.get_data5());
  OPENGL_GRAPHICS_ASSERT(!batch9.get_data6());
  OPENGL_GRAPHICS_ASSERT(!batch9.get_data7());
  OPENGL_GRAPHICS_ASSERT(!batch9.get_data8());
  OPENGL_GRAPHICS_ASSERT(!batch9.get_data9());
}

void test_batch_data_ctor()
{
  { // 1 attribute
    opengl_graphics::batch_data<internal::pod_2<int, int> >::collection1_type
      data1(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data<internal::pod_2<int, int> > batch(data1, 10);
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch.get_data7());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch.get_data8());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch.get_data8());
    OPENGL_GRAPHICS_ASSERT(batch.get_data9());
  }
}

void test_batch_data_copy_ctor()
{
  { // 1 attribute
    opengl_graphics::batch_data<internal::pod_2<int, int> >::collection1_type
      data1(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data<internal::pod_2<int, int> > batch(
      data1, 10);
    opengl_graphics::batch_data<internal::pod_2<int, int> > batch_cpy(batch);
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT_EQ(batch.get_data1(), batch_cpy.get_data1());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data5());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data6());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data7());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch.get_data8());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data8());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch.get_data8());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data8());
    OPENGL_GRAPHICS_ASSERT(batch.get_data9());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data9());
  }
}

void test_batch_data_assignment_opperator()
{
  { // 1 attribute
    opengl_graphics::batch_data<internal::pod_2<int, int> >::collection1_type
      data1(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data<internal::pod_2<int, int> > batch(
      data1, 10);
    opengl_graphics::batch_data<internal::pod_2<int, int> > batch_cpy;
    batch_cpy = batch;
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data5());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data6());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data7());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch.get_data8());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data8());
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
    OPENGL_GRAPHICS_ASSERT(batch.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data1());
    OPENGL_GRAPHICS_ASSERT(batch.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data2());
    OPENGL_GRAPHICS_ASSERT(batch.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data3());
    OPENGL_GRAPHICS_ASSERT(batch.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data4());
    OPENGL_GRAPHICS_ASSERT(batch.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data5());
    OPENGL_GRAPHICS_ASSERT(batch.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data6());
    OPENGL_GRAPHICS_ASSERT(batch.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data7());
    OPENGL_GRAPHICS_ASSERT(batch.get_data8());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data8());
    OPENGL_GRAPHICS_ASSERT(batch.get_data9());
    OPENGL_GRAPHICS_ASSERT(batch_cpy.get_data9());
  }
}

void test_batch_data_get_byte_counts()
{
  const size_t pod2_size = sizeof(internal::pod_2<int, int>);
  const size_t pod3_size = sizeof(internal::pod_3<int, int, int>);
  const size_t pod4_size = sizeof(internal::pod_4<int, int, int, int>);
  { // 1 attribute
    opengl_graphics::batch_data<internal::pod_2<int, int> >::collection1_type
      data1(new internal::pod_2<int, int>[10]);

    opengl_graphics::batch_data<internal::pod_2<int, int> > batch_empty;
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_1());
    opengl_graphics::batch_data<internal::pod_2<int, int> > batch(
      data1, 10);
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_1());
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
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_2());
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
    > batch(data1, data2, 10);
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_2());
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
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_3());
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>
    > batch(data1, data2, data3, 10);
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_3());
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
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_4());
    opengl_graphics::batch_data
    <
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, 10);
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_4());
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
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_4());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_5());
    opengl_graphics::batch_data
    <
      internal::pod_4<int, int, int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_2<int, int>,
      internal::pod_4<int, int, int, int>,
      internal::pod_2<int, int>
    > batch(data1, data2, data3,
      data4, data5, 10);
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_4());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_5());
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
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_4());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_5());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_6());
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
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_4());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_5());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_6());
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
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_4());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_5());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_6());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_7());
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
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_4());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_5());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_6());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod2_size, batch.get_bytecount_7());
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
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_4());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_5());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_6());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_7());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_8());
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
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_4());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_5());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_6());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_7());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod3_size, batch.get_bytecount_8());
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
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_4());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_5());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_6());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_7());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_8());
    OPENGL_GRAPHICS_ASSERT_EQ(0, batch_empty.get_bytecount_9());
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
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_1());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_2());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_3());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_4());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_5());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_6());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_7());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_8());
    OPENGL_GRAPHICS_ASSERT_EQ(10 * pod4_size, batch.get_bytecount_9());
  }
}

// interleaved_data unit tests
void test_interleaved_data_default_ctor()
{
  { // 2 attributes
    typedef opengl_graphics::interleaved_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
    > interleaved2;
    interleaved2 data;
    OPENGL_GRAPHICS_ASSERT(!(data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_byte_count());
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved2::traits::type1_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved2::traits::type2_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(20, interleaved2::traits::stride);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved2::traits::type1_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved2::traits::type2_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(5, interleaved2::traits::attribute_val_count);
    OPENGL_GRAPHICS_ASSERT_EQ(0, interleaved2::traits::type1_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved2::traits::type2_byte_offset);
  }

  { // 3 attributes
    typedef opengl_graphics::interleaved_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>,
      internal::pod_4<int, int, int, int>
    > interleaved3;
    interleaved3 data;
    OPENGL_GRAPHICS_ASSERT(!(data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_byte_count());
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved3::traits::type1_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved3::traits::type2_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved3::traits::type3_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(36, interleaved3::traits::stride);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved3::traits::type1_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved3::traits::type2_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved3::traits::type3_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(9, interleaved3::traits::attribute_val_count);
    OPENGL_GRAPHICS_ASSERT_EQ(0, interleaved3::traits::type1_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved3::traits::type2_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(20, interleaved3::traits::type3_byte_offset);
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
    OPENGL_GRAPHICS_ASSERT(!(data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_byte_count());
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved4::traits::type1_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved4::traits::type2_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved4::traits::type3_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved4::traits::type4_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(48, interleaved4::traits::stride);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved4::traits::type1_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved4::traits::type2_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved4::traits::type3_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved4::traits::type4_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved4::traits::attribute_val_count);
    OPENGL_GRAPHICS_ASSERT_EQ(0, interleaved4::traits::type1_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved4::traits::type2_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(20, interleaved4::traits::type3_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(36, interleaved4::traits::type4_byte_offset);
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
    OPENGL_GRAPHICS_ASSERT(!(data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_byte_count());
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved5::traits::type1_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved5::traits::type2_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved5::traits::type3_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved5::traits::type4_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved5::traits::type5_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(64, interleaved5::traits::stride);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved5::traits::type1_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved5::traits::type2_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved5::traits::type3_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved5::traits::type4_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved5::traits::type5_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved5::traits::attribute_val_count);
    OPENGL_GRAPHICS_ASSERT_EQ(0, interleaved5::traits::type1_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved5::traits::type2_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(20, interleaved5::traits::type3_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(36, interleaved5::traits::type4_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(48, interleaved5::traits::type5_byte_offset);
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
    OPENGL_GRAPHICS_ASSERT(!(data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_byte_count());
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved6::traits::type1_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved6::traits::type2_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved6::traits::type3_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved6::traits::type4_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved6::traits::type5_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved6::traits::type6_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(72, interleaved6::traits::stride);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved6::traits::type1_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved6::traits::type2_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved6::traits::type3_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved6::traits::type4_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved6::traits::type5_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved6::traits::type6_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(18, interleaved6::traits::attribute_val_count);
    OPENGL_GRAPHICS_ASSERT_EQ(0, interleaved6::traits::type1_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved6::traits::type2_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(20, interleaved6::traits::type3_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(36, interleaved6::traits::type4_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(48, interleaved6::traits::type5_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(64, interleaved6::traits::type6_byte_offset);
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
    OPENGL_GRAPHICS_ASSERT(!(data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_byte_count());
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved7::traits::type1_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved7::traits::type2_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved7::traits::type3_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved7::traits::type4_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved7::traits::type5_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved7::traits::type6_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved7::traits::type7_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(84, interleaved7::traits::stride);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved7::traits::type1_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved7::traits::type2_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved7::traits::type3_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved7::traits::type4_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved7::traits::type5_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved7::traits::type6_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved7::traits::type7_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(21, interleaved7::traits::attribute_val_count);
    OPENGL_GRAPHICS_ASSERT_EQ(0, interleaved7::traits::type1_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved7::traits::type2_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(20, interleaved7::traits::type3_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(36, interleaved7::traits::type4_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(48, interleaved7::traits::type5_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(64, interleaved7::traits::type6_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(72, interleaved7::traits::type7_byte_offset);
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
    OPENGL_GRAPHICS_ASSERT(!(data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_byte_count());
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved8::traits::type1_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved8::traits::type2_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved8::traits::type3_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved8::traits::type4_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved8::traits::type5_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved8::traits::type6_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved8::traits::type7_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved8::traits::type8_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(100, interleaved8::traits::stride);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved8::traits::type1_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved8::traits::type2_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved8::traits::type3_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved8::traits::type4_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved8::traits::type5_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved8::traits::type6_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved8::traits::type7_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved8::traits::type8_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(25, interleaved8::traits::attribute_val_count);
    OPENGL_GRAPHICS_ASSERT_EQ(0, interleaved8::traits::type1_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved8::traits::type2_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(20, interleaved8::traits::type3_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(36, interleaved8::traits::type4_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(48, interleaved8::traits::type5_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(64, interleaved8::traits::type6_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(72, interleaved8::traits::type7_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(84, interleaved8::traits::type8_byte_offset);
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
    OPENGL_GRAPHICS_ASSERT(!(data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(0, data.get_byte_count());
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved9::traits::type1_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved9::traits::type2_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved9::traits::type3_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved9::traits::type4_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved9::traits::type5_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved9::traits::type6_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(12, interleaved9::traits::type7_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(16, interleaved9::traits::type8_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved9::traits::type9_sizeof);
    OPENGL_GRAPHICS_ASSERT_EQ(108, interleaved9::traits::stride);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved9::traits::type1_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved9::traits::type2_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved9::traits::type3_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved9::traits::type4_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved9::traits::type5_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved9::traits::type6_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(3, interleaved9::traits::type7_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(4, interleaved9::traits::type8_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(2, interleaved9::traits::type9_dimension);
    OPENGL_GRAPHICS_ASSERT_EQ(27, interleaved9::traits::attribute_val_count);
    OPENGL_GRAPHICS_ASSERT_EQ(0, interleaved9::traits::type1_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(8, interleaved9::traits::type2_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(20, interleaved9::traits::type3_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(36, interleaved9::traits::type4_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(48, interleaved9::traits::type5_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(64, interleaved9::traits::type6_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(72, interleaved9::traits::type7_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(84, interleaved9::traits::type8_byte_offset);
    OPENGL_GRAPHICS_ASSERT_EQ(100, interleaved9::traits::type9_byte_offset);
  }
}

void test_interleaved_data_ctor()
{
  { // 2 attributes
    typedef opengl_graphics::interleaved_data
    <
      internal::pod_2<int, int>,
      internal::pod_3<int, int, int>
    > interleaved2;
    interleaved2::collection_type idata(new interleaved2::datum_type[10]);
    interleaved2 data(idata, 10);
    OPENGL_GRAPHICS_ASSERT((data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(10, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(200, data.get_byte_count());
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
    OPENGL_GRAPHICS_ASSERT((data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(20, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(720, data.get_byte_count());
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
    OPENGL_GRAPHICS_ASSERT((data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(15, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(720, data.get_byte_count());
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
    OPENGL_GRAPHICS_ASSERT(data.get_data().get());
    OPENGL_GRAPHICS_ASSERT_EQ(2, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(128, data.get_byte_count());
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
    OPENGL_GRAPHICS_ASSERT((data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(500, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(36000, data.get_byte_count());
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
    OPENGL_GRAPHICS_ASSERT((data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(33, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(2772, data.get_byte_count());
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
    OPENGL_GRAPHICS_ASSERT((data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(96, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(9600, data.get_byte_count());
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
    OPENGL_GRAPHICS_ASSERT((data.get_data().get()));
    OPENGL_GRAPHICS_ASSERT_EQ(1333, data.get_attribute_count());
    OPENGL_GRAPHICS_ASSERT_EQ(143964, data.get_byte_count());
  }
}

void test_interleaved_data_copy_ctor()
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
  }
}

void test_interleaved_data_assignment_operator()
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
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
    OPENGL_GRAPHICS_ASSERT(data_copy.get_data());
    OPENGL_GRAPHICS_ASSERT(data.get_data());
    OPENGL_GRAPHICS_ASSERT_EQ(
      data_copy.get_attribute_count(), data.get_attribute_count());
  }
}

bool test_mesh_types::run()
{
  test_default_interleaved_datum_2d_constructor();
  test_default_interleaved_datum_3d_constructor();
  test_default_interleaved_datum_4d_constructor();
  test_default_interleaved_datum_5d_constructor();
  test_default_interleaved_datum_6d_constructor();
  test_default_interleaved_datum_7d_constructor();
  test_default_interleaved_datum_8d_constructor();
  test_default_interleaved_datum_9d_constructor();
  test_interleaved_datum_2d_constructor();
  test_interleaved_datum_3d_constructor();
  test_interleaved_datum_4d_constructor();
  test_interleaved_datum_5d_constructor();
  test_interleaved_datum_6d_constructor();
  test_interleaved_datum_7d_constructor();
  test_interleaved_datum_8d_constructor();
  test_interleaved_datum_9d_constructor();
  test_interleaved_datum_2d_copy_constructor();
  test_interleaved_datum_3d_copy_constructor();
  test_interleaved_datum_4d_copy_constructor();
  test_interleaved_datum_5d_copy_constructor();
  test_interleaved_datum_6d_copy_constructor();
  test_interleaved_datum_7d_copy_constructor();
  test_interleaved_datum_8d_copy_constructor();
  test_interleaved_datum_9d_copy_constructor();
  test_interleaved_datum_2d_assignment_operator();
  test_interleaved_datum_3d_assignment_operator();
  test_interleaved_datum_4d_assignment_operator();
  test_interleaved_datum_5d_assignment_operator();
  test_interleaved_datum_6d_assignment_operator();
  test_interleaved_datum_7d_assignment_operator();
  test_interleaved_datum_8d_assignment_operator();
  test_interleaved_datum_9d_assignment_operator();
  test_batch_data_default_ctor();
  test_batch_data_ctor();
  test_batch_data_copy_ctor();
  test_batch_data_assignment_opperator();
  test_batch_data_get_byte_counts();
  test_interleaved_data_default_ctor();
  test_interleaved_data_ctor();
  test_interleaved_data_copy_ctor();
  test_interleaved_data_assignment_operator();
  return true;
}
