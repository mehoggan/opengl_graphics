/* Copyright (C)
 *
 * Copyright 2013 Matthew Everett Hoggan
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writting, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef BATCH_DATA_H_INCLUDED
#define BATCH_DATA_H_INCLUDED

#include "ref_count/shared_array/shared_array.h"
#include "mesh_types/batch_traits.h"
#include "core/platform.h"
#include "utils/utils.h"

namespace opengl_graphics
{
  template
  <
    typename T1, typename T2 = nat, typename T3 = nat, typename T4 = nat,
    typename T5 = nat, typename T6 = nat, typename T7 = nat, typename T8 = nat,
    typename T9 = nat, typename T10 = nat
  >
  struct batch_data;
}

namespace opengl_graphics
{
  template
  <
    typename T1
  >
  struct batch_data<T1, nat, nat, nat, nat, nat, nat, nat, nat, nat>
  {
  public:
    typedef T1 type1;
    typedef shared_array<type1> collection1_type;

    typedef msvc_typename batch_traits
    <
      T1, nat, nat, nat, nat, nat, nat, nat, nat
    > batch_traits_t;
    static batch_traits_t traits;

  private:
    collection1_type _data1;
    size_t _attribute_count;

  public:
    batch_data();
    batch_data(
      const collection1_type data1,
      size_t attribute_count);

    batch_data(const batch_data &rhs);
    batch_data &operator=(batch_data rhs);

    collection1_type get_data1() const;

    size_t get_attribute_count() const;
    size_t get_bytecount_1() const;
  };
}

namespace opengl_graphics
{
  template
  <
    typename T1, typename T2
  >
  struct batch_data<T1, T2, nat, nat, nat, nat, nat, nat, nat, nat>
  {
  public:
    typedef T1 type1;
    typedef shared_array<type1> collection1_type;
    typedef T2 type2;
    typedef shared_array<type2> collection2_type;

    typedef batch_traits<T1, T2, nat, nat, nat, nat, nat, nat, nat>
      batch_traits_t;
    static batch_traits_t traits;

  private:
    collection1_type _data1;
    collection2_type _data2;
    size_t _attribute_count;

  public:
    batch_data();
    batch_data(
      const collection1_type data1,
      const collection2_type data2,
      size_t attribute_count);

    batch_data(const batch_data &rhs);
    batch_data &operator=(batch_data rhs);

    collection1_type get_data1() const;
    collection2_type get_data2() const;

    size_t get_attribute_count() const;
    size_t get_bytecount_1() const;
    size_t get_bytecount_2() const;
  };
}

namespace opengl_graphics
{
  template
  <
    typename T1, typename T2, typename T3
  >
  struct batch_data<T1, T2, T3, nat, nat, nat, nat, nat, nat, nat>
  {
  public:
    typedef T1 type1;
    typedef shared_array<type1> collection1_type;
    typedef T2 type2;
    typedef shared_array<type2> collection2_type;
    typedef T3 type3;
    typedef shared_array<type3> collection3_type;

    typedef batch_traits<T1, T2, T3, nat, nat, nat, nat, nat, nat>
      batch_traits_t;
    static batch_traits_t traits;

  private:
    collection1_type _data1;
    collection2_type _data2;
    collection3_type _data3;
    size_t _attribute_count;

  public:
    batch_data();
    batch_data(
      const collection1_type data1,
      const collection2_type data2,
      const collection3_type data3,
      size_t attribute_count);

    batch_data(const batch_data &rhs);
    batch_data &operator=(batch_data rhs);

    collection1_type get_data1() const;
    collection2_type get_data2() const;
    collection3_type get_data3() const;

    size_t get_attribute_count() const;
    size_t get_bytecount_1() const;
    size_t get_bytecount_2() const;
    size_t get_bytecount_3() const;
  };
}

namespace opengl_graphics
{
  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  struct batch_data<T1, T2, T3, T4, nat, nat, nat, nat, nat, nat>
  {
  public:
    typedef T1 type1;
    typedef shared_array<type1> collection1_type;
    typedef T2 type2;
    typedef shared_array<type2> collection2_type;
    typedef T3 type3;
    typedef shared_array<type3> collection3_type;
    typedef T4 type4;
    typedef shared_array<type4> collection4_type;

    typedef batch_traits<T1, T2, T3, T4, nat, nat, nat, nat, nat>
      batch_traits_t;
    static batch_traits_t traits;

  private:
    collection1_type _data1;
    collection2_type _data2;
    collection3_type _data3;
    collection4_type _data4;
    size_t _attribute_count;

  public:
    batch_data();
    batch_data(
      const collection1_type data1,
      const collection2_type data2,
      const collection3_type data3,
      const collection4_type data4,
      size_t attribute_count);

    batch_data(const batch_data &rhs);
    batch_data &operator=(batch_data rhs);

    collection1_type get_data1() const;
    collection2_type get_data2() const;
    collection3_type get_data3() const;
    collection4_type get_data4() const;

    size_t get_attribute_count() const;
    size_t get_bytecount_1() const;
    size_t get_bytecount_2() const;
    size_t get_bytecount_3() const;
    size_t get_bytecount_4() const;
  };
}

namespace opengl_graphics
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  struct batch_data<T1, T2, T3, T4, T5, nat, nat, nat, nat, nat>
  {
  public:
    typedef T1 type1;
    typedef shared_array<type1> collection1_type;
    typedef T2 type2;
    typedef shared_array<type2> collection2_type;
    typedef T3 type3;
    typedef shared_array<type3> collection3_type;
    typedef T4 type4;
    typedef shared_array<type4> collection4_type;
    typedef T5 type5;
    typedef shared_array<type5> collection5_type;

    typedef batch_traits<T1, T2, T3, T4, T5, nat, nat, nat, nat>
      batch_traits_t;
    static batch_traits_t traits;

  private:
    collection1_type _data1;
    collection2_type _data2;
    collection3_type _data3;
    collection4_type _data4;
    collection5_type _data5;
    size_t _attribute_count;

  public:
    batch_data();
    batch_data(
      const collection1_type data1,
      const collection2_type data2,
      const collection3_type data3,
      const collection4_type data4,
      const collection5_type data5,
      size_t attribute_count);

    batch_data(const batch_data &rhs);
    batch_data &operator=(batch_data rhs);

    collection1_type get_data1() const;
    collection2_type get_data2() const;
    collection3_type get_data3() const;
    collection4_type get_data4() const;
    collection5_type get_data5() const;

    size_t get_attribute_count() const;
    size_t get_bytecount_1() const;
    size_t get_bytecount_2() const;
    size_t get_bytecount_3() const;
    size_t get_bytecount_4() const;
    size_t get_bytecount_5() const;
  };
}

namespace opengl_graphics
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  struct batch_data<T1, T2, T3, T4, T5, T6, nat, nat, nat, nat>
  {
  public:
    typedef T1 type1;
    typedef shared_array<type1> collection1_type;
    typedef T2 type2;
    typedef shared_array<type2> collection2_type;
    typedef T3 type3;
    typedef shared_array<type3> collection3_type;
    typedef T4 type4;
    typedef shared_array<type4> collection4_type;
    typedef T5 type5;
    typedef shared_array<type5> collection5_type;
    typedef T6 type6;
    typedef shared_array<type6> collection6_type;

    typedef batch_traits<T1, T2, T3, T4, T5, T6, nat, nat, nat>
      batch_traits_t;
    static batch_traits_t traits;

  private:
    collection1_type _data1;
    collection2_type _data2;
    collection3_type _data3;
    collection4_type _data4;
    collection5_type _data5;
    collection6_type _data6;
    size_t _attribute_count;

  public:
    batch_data();
    batch_data(
      const collection1_type data1,
      const collection2_type data2,
      const collection3_type data3,
      const collection4_type data4,
      const collection5_type data5,
      const collection6_type data6,
      size_t attribute_count);

    batch_data(const batch_data &rhs);
    batch_data &operator=(batch_data rhs);

    collection1_type get_data1() const;
    collection2_type get_data2() const;
    collection3_type get_data3() const;
    collection4_type get_data4() const;
    collection5_type get_data5() const;
    collection6_type get_data6() const;

    size_t get_attribute_count() const;
    size_t get_bytecount_1() const;
    size_t get_bytecount_2() const;
    size_t get_bytecount_3() const;
    size_t get_bytecount_4() const;
    size_t get_bytecount_5() const;
    size_t get_bytecount_6() const;
  };
}

namespace opengl_graphics
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  struct batch_data<T1, T2, T3, T4, T5, T6, T7, nat, nat, nat>
  {
  public:
    typedef T1 type1;
    typedef shared_array<type1> collection1_type;
    typedef T2 type2;
    typedef shared_array<type2> collection2_type;
    typedef T3 type3;
    typedef shared_array<type3> collection3_type;
    typedef T4 type4;
    typedef shared_array<type4> collection4_type;
    typedef T5 type5;
    typedef shared_array<type5> collection5_type;
    typedef T6 type6;
    typedef shared_array<type6> collection6_type;
    typedef T7 type7;
    typedef shared_array<type7> collection7_type;

    typedef batch_traits<T1, T2, T3, T4, T5, T6, T7, nat, nat>
      batch_traits_t;
    static batch_traits_t traits;

  private:
    collection1_type _data1;
    collection2_type _data2;
    collection3_type _data3;
    collection4_type _data4;
    collection5_type _data5;
    collection6_type _data6;
    collection7_type _data7;
    size_t _attribute_count;

  public:
    batch_data();
    batch_data(
      const collection1_type data1,
      const collection2_type data2,
      const collection3_type data3,
      const collection4_type data4,
      const collection5_type data5,
      const collection6_type data6,
      const collection7_type data7,
      size_t attribute_count);

    batch_data(const batch_data &rhs);
    batch_data &operator=(batch_data rhs);

    collection1_type get_data1() const;
    collection2_type get_data2() const;
    collection3_type get_data3() const;
    collection4_type get_data4() const;
    collection5_type get_data5() const;
    collection6_type get_data6() const;
    collection7_type get_data7() const;

    size_t get_attribute_count() const;
    size_t get_bytecount_1() const;
    size_t get_bytecount_2() const;
    size_t get_bytecount_3() const;
    size_t get_bytecount_4() const;
    size_t get_bytecount_5() const;
    size_t get_bytecount_6() const;
    size_t get_bytecount_7() const;
  };
}

namespace opengl_graphics
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  struct batch_data<T1, T2, T3, T4, T5, T6, T7, T8, nat, nat>
  {
  public:
    typedef T1 type1;
    typedef shared_array<type1> collection1_type;
    typedef T2 type2;
    typedef shared_array<type2> collection2_type;
    typedef T3 type3;
    typedef shared_array<type3> collection3_type;
    typedef T4 type4;
    typedef shared_array<type4> collection4_type;
    typedef T5 type5;
    typedef shared_array<type5> collection5_type;
    typedef T6 type6;
    typedef shared_array<type6> collection6_type;
    typedef T7 type7;
    typedef shared_array<type7> collection7_type;
    typedef T8 type8;
    typedef shared_array<type8> collection8_type;

    typedef batch_traits<T1, T2, T3, T4, T5, T6, T7, T8, nat>
      batch_traits_t;
    static batch_traits_t traits;

  private:
    collection1_type _data1;
    collection2_type _data2;
    collection3_type _data3;
    collection4_type _data4;
    collection5_type _data5;
    collection6_type _data6;
    collection7_type _data7;
    collection8_type _data8;
    size_t _attribute_count;

  public:
    batch_data();
    batch_data(
      const collection1_type data1,
      const collection2_type data2,
      const collection3_type data3,
      const collection4_type data4,
      const collection5_type data5,
      const collection6_type data6,
      const collection7_type data7,
      const collection8_type data8,
      size_t attribute_count);

    batch_data(const batch_data &rhs);
    batch_data &operator=(batch_data rhs);

    collection1_type get_data1() const;
    collection2_type get_data2() const;
    collection3_type get_data3() const;
    collection4_type get_data4() const;
    collection5_type get_data5() const;
    collection6_type get_data6() const;
    collection7_type get_data7() const;
    collection8_type get_data8() const;

    size_t get_attribute_count() const;
    size_t get_bytecount_1() const;
    size_t get_bytecount_2() const;
    size_t get_bytecount_3() const;
    size_t get_bytecount_4() const;
    size_t get_bytecount_5() const;
    size_t get_bytecount_6() const;
    size_t get_bytecount_7() const;
    size_t get_bytecount_8() const;
  };
}

namespace opengl_graphics
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  struct batch_data<T1, T2, T3, T4, T5, T6, T7, T8, T9, nat>
  {
  public:
    typedef T1 type1;
    typedef shared_array<type1> collection1_type;
    typedef T2 type2;
    typedef shared_array<type2> collection2_type;
    typedef T3 type3;
    typedef shared_array<type3> collection3_type;
    typedef T4 type4;
    typedef shared_array<type4> collection4_type;
    typedef T5 type5;
    typedef shared_array<type5> collection5_type;
    typedef T6 type6;
    typedef shared_array<type6> collection6_type;
    typedef T7 type7;
    typedef shared_array<type7> collection7_type;
    typedef T8 type8;
    typedef shared_array<type8> collection8_type;
    typedef T9 type9;
    typedef shared_array<type9> collection9_type;

    typedef batch_traits<T1, T2, T3, T4, T5, T6, T7, T8, T9>
      batch_traits_t;
    static batch_traits_t traits;

  private:
    collection1_type _data1;
    collection2_type _data2;
    collection3_type _data3;
    collection4_type _data4;
    collection5_type _data5;
    collection6_type _data6;
    collection7_type _data7;
    collection8_type _data8;
    collection9_type _data9;
    size_t _attribute_count;

  public:
    batch_data();
    batch_data(
      const collection1_type data1,
      const collection2_type data2,
      const collection3_type data3,
      const collection4_type data4,
      const collection5_type data5,
      const collection6_type data6,
      const collection7_type data7,
      const collection8_type data8,
      const collection9_type data9,
      size_t attribute_count);

    batch_data(const batch_data &rhs);
    batch_data &operator=(batch_data rhs);

    collection1_type get_data1() const;
    collection2_type get_data2() const;
    collection3_type get_data3() const;
    collection4_type get_data4() const;
    collection5_type get_data5() const;
    collection6_type get_data6() const;
    collection7_type get_data7() const;
    collection8_type get_data8() const;
    collection9_type get_data9() const;

    size_t get_attribute_count() const;
    size_t get_bytecount_1() const;
    size_t get_bytecount_2() const;
    size_t get_bytecount_3() const;
    size_t get_bytecount_4() const;
    size_t get_bytecount_5() const;
    size_t get_bytecount_6() const;
    size_t get_bytecount_7() const;
    size_t get_bytecount_8() const;
    size_t get_bytecount_9() const;
  };
}

#include "batch_data.inl"
#endif
