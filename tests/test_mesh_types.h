#ifndef INTERLEAVED_DATUM_TESTS
#define INTERLEAVED_DATUM_TESTS

#define _USE_MATH_DEFINES

#include "test_base.h"

#include "mesh_types/datums/interleaved_datum_2d.h"
#include "mesh_types/datums/interleaved_datum_3d.h"
#include "mesh_types/datums/interleaved_datum_4d.h"
#include "mesh_types/datums/interleaved_datum_5d.h"
#include "mesh_types/datums/interleaved_datum_6d.h"
#include "mesh_types/datums/interleaved_datum_7d.h"
#include "mesh_types/datums/interleaved_datum_8d.h"
#include "mesh_types/datums/interleaved_datum_9d.h"
#include "mesh_types/interleaved_data.h"
#include "mesh_types/batch_data.h"

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
      t3_(other.t4_)
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

class test_mesh_types : public test_base
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
#endif
