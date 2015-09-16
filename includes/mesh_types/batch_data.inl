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
namespace opengl_graphics // 1 attribute
{
  template
  <
    typename T1
  >
  batch_data
  <
    T1, nat, nat, nat, nat, nat, nat, nat, nat, nat
  >::batch_data() :
    _attribute_count(0u)
  {}

  template
  <
    typename T1
  >
  batch_data
  <
    T1, nat, nat, nat, nat, nat, nat, nat, nat, nat
  >::batch_data(
    const typename batch_data
    <
      T1, nat, nat, nat, nat, nat, nat, nat, nat, nat
    >::collection1_type data1, size_t attribute_count) :
    _data1(std::move(*data1)),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1
  >
  batch_data
  <
    T1, nat, nat, nat, nat, nat, nat, nat, nat, nat
  >::batch_data(const batch_data<T1> &rhs) :
    _data1(std::move(rhs._data1)),
    _attribute_count(rhs._attribute_count)
  { }

  template
  <
    typename T1
  >
  batch_data<T1> &
  batch_data
  <
    T1, nat, nat, nat, nat, nat, nat, nat, nat, nat
  >::operator=(batch_data<T1> rhs)
  {
    _data1 = std::move(rhs._data1);
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1
  >
  const typename batch_data
  <
    T1, nat, nat, nat, nat, nat, nat, nat, nat, nat
  >::collection1_type &
  batch_data
  <
    T1, nat, nat, nat, nat, nat, nat, nat, nat, nat
  >::get_data1() const
  {
    return _data1;
  }

  template
  <
    typename T1
  >
  size_t
  batch_data
  <
    T1, nat, nat, nat, nat, nat, nat, nat, nat, nat
  >::get_attribute_count() const
  {
    return _attribute_count;
  }

  template
  <
    typename T1
  >
  size_t
  batch_data
  <
    T1, nat, nat, nat, nat, nat, nat, nat, nat, nat
  >:: get_bytecount_1() const
  {
    return sizeof(T1) * _attribute_count;
  }
}

namespace opengl_graphics // 2 attributes
{
  template
  <
    typename T1, typename T2
  >
  batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::batch_data() :
    _attribute_count(0u)
  {}

  template
  <
    typename T1, typename T2
  >
  batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::batch_data(
    const typename batch_data
    <
      T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
    >::collection1_type data1,
    const typename batch_data
    <
      T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
    >::collection2_type data2,
    size_t attribute_count) :
    _data1(std::move(data1)),
    _data2(std::move(data2)),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2
  >
  batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::batch_data(const batch_data<T1, T2> &rhs) :
    _data1(std::move(rhs._data1)),
    _data2(std::move(rhs._data2)),
    _attribute_count(rhs._attribute_count)
  {
  }

  template
  <
    typename T1, typename T2
  >
  batch_data<T1, T2> &
  batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::operator=(batch_data<T1, T2> rhs)
  {
    _data1 = std::move(rhs._data1);
    _data2 = std::move(rhs._data2);
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1, typename T2
  >
  const typename batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::collection1_type &
  batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::get_data1() const
  {
    return _data1;
  }

  template
  <
    typename T1, typename T2
  >
  const typename batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::collection2_type &
  batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::get_data2() const
  {
    return _data2;
  }

  template
  <
    typename T1, typename T2
  >
  size_t
  batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::get_attribute_count() const
  {
    return _attribute_count;
  }

  template
  <
    typename T1, typename T2
  >
  size_t
  batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >:: get_bytecount_1() const
  {
    return sizeof(T1) * _attribute_count;
  }

  template
  <
    typename T1, typename T2
  >
  size_t
  batch_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >:: get_bytecount_2() const
  {
    return sizeof(T2) * _attribute_count;
  }
}

namespace opengl_graphics // 3 attributes
{
  template
  <
    typename T1, typename T2, typename T3
  >
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::batch_data() :
    _attribute_count(0u)
  {}

  template
  <
    typename T1, typename T2, typename T3
  >
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::batch_data(
    const typename batch_data
    <
      T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
    >::collection1_type data1,
    const typename batch_data
    <
      T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
    >::collection2_type data2,
    const typename batch_data
    <
      T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
    >::collection3_type data3,
    size_t attribute_count) :
    _data1(std::move(data1)),
    _data2(std::move(data2)),
    _data3(std::move(data3)),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3
  >
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::batch_data(const batch_data<T1, T2, T3> &rhs) :
    _data1(std::move(rhs._data1)),
    _data2(std::move(rhs._data2)),
    _data3(std::move(rhs._data3)),
    _attribute_count(rhs._attribute_count)
  {
  }

  template
  <
    typename T1, typename T2, typename T3
  >
  batch_data<T1, T2, T3> &
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::operator=(batch_data<T1, T2, T3> rhs)
  {
    _data1 = std::move(rhs._data1);
    _data2 = std::move(rhs._data2);
    _data3 = std::move(rhs._data3);
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1, typename T2, typename T3
  >
  const typename batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::collection1_type &
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::get_data1() const
  {
    return _data1;
  }

  template
  <
    typename T1, typename T2, typename T3
  >
  const typename batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::collection2_type &
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::get_data2() const
  {
    return _data2;
  }

  template
  <
    typename T1, typename T2, typename T3
  >
  const typename batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::collection3_type &
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::get_data3() const
  {
    return _data3;
  }

  template
  <
    typename T1, typename T2, typename T3
  >
  size_t
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::get_attribute_count() const
  {
    return _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3
  >
  size_t
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >:: get_bytecount_1() const
  {
    return sizeof(T1) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3
  >
  size_t
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >:: get_bytecount_2() const
  {
    return sizeof(T2) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3
  >
  size_t
  batch_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >:: get_bytecount_3() const
  {
    return sizeof(T3) * _attribute_count;
  }
}

namespace opengl_graphics // 4 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::batch_data() :
    _attribute_count(0u)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::batch_data(
    const typename batch_data
    <
      T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
    >::collection1_type data1,
    const typename batch_data
    <
      T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
    >::collection2_type data2,
    const typename batch_data
    <
      T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
    >::collection3_type data3,
    const typename batch_data
    <
      T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
    >::collection4_type data4,
    size_t attribute_count) :
    _data1(std::move(data1)),
    _data2(std::move(data2)),
    _data3(std::move(data3)),
    _data4(std::move(data4)),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::batch_data(const batch_data<T1, T2, T3, T4> &rhs) :
    _data1(std::move(rhs._data1)),
    _data2(std::move(rhs._data2)),
    _data3(std::move(rhs._data3)),
    _data4(std::move(rhs._data4)),
    _attribute_count(rhs._attribute_count)
  {
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  batch_data<T1, T2, T3, T4> &
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::operator=(batch_data<T1, T2, T3, T4> rhs)
  {
    _data1 = std::move(rhs._data1);
    _data2 = std::move(rhs._data2);
    _data3 = std::move(rhs._data3);
    _data4 = std::move(rhs._data4);
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  const typename batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::collection1_type &
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::get_data1() const
  {
    return _data1;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  const typename batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::collection2_type &
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::get_data2() const
  {
    return _data2;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  const typename batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::collection3_type &
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::get_data3() const
  {
    return _data3;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  const typename batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::collection4_type &
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::get_data4() const
  {
    return _data4;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::get_attribute_count() const
  {
    return _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >:: get_bytecount_1() const
  {
    return sizeof(T1) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >:: get_bytecount_2() const
  {
    return sizeof(T2) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >:: get_bytecount_3() const
  {
    return sizeof(T3) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >:: get_bytecount_4() const
  {
    return sizeof(T4) * _attribute_count;
  }
}

namespace opengl_graphics // 5 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::batch_data() :
    _attribute_count(0u)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::batch_data(
    const typename batch_data
    <
      T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
    >::collection1_type data1,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
    >::collection2_type data2,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
    >::collection3_type data3,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
    >::collection4_type data4,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
    >::collection5_type data5,
    size_t attribute_count) :
    _data1(std::move(data1)),
    _data2(std::move(data2)),
    _data3(std::move(data3)),
    _data4(std::move(data4)),
    _data5(std::move(data5)),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::batch_data(const batch_data<T1, T2, T3, T4, T5> &rhs) :
    _data1(std::move(rhs._data1)),
    _data2(std::move(rhs._data2)),
    _data3(std::move(rhs._data3)),
    _data4(std::move(rhs._data4)),
    _data5(std::move(rhs._data5)),
    _attribute_count(rhs._attribute_count)
  {
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  batch_data<T1, T2, T3, T4, T5> &
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::operator=(batch_data<T1, T2, T3, T4, T5> rhs)
  {
    _data1 = std::move(rhs._data1);
    _data2 = std::move(rhs._data2);
    _data3 = std::move(rhs._data3);
    _data4 = std::move(rhs._data4);
    _data5 = std::move(rhs._data5);
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::collection1_type &
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::get_data1() const
  {
    return _data1;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::collection2_type &
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::get_data2() const
  {
    return _data2;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::collection3_type &
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::get_data3() const
  {
    return _data3;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::collection4_type &
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::get_data4() const
  {
    return _data4;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::collection5_type &
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::get_data5() const
  {
    return _data5;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::get_attribute_count() const
  {
    return _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >:: get_bytecount_1() const
  {
    return sizeof(T1) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >:: get_bytecount_2() const
  {
    return sizeof(T2) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >:: get_bytecount_3() const
  {
    return sizeof(T3) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >:: get_bytecount_4() const
  {
    return sizeof(T4) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >:: get_bytecount_5() const
  {
    return sizeof(T5) * _attribute_count;
  }
}

namespace opengl_graphics // 6 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::batch_data() :
    _attribute_count(0u)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::batch_data(
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
    >::collection1_type data1,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
    >::collection2_type data2,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
    >::collection3_type data3,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
    >::collection4_type data4,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
    >::collection5_type data5,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
    >::collection6_type data6,
    size_t attribute_count) :
    _data1(std::move(data1)),
    _data2(std::move(data2)),
    _data3(std::move(data3)),
    _data4(std::move(data4)),
    _data5(std::move(data5)),
    _data6(std::move(data6)),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::batch_data(const batch_data<T1, T2, T3, T4, T5, T6> &rhs) :
    _data1(std::move(rhs._data1)),
    _data2(std::move(rhs._data2)),
    _data3(std::move(rhs._data3)),
    _data4(std::move(rhs._data4)),
    _data5(std::move(rhs._data5)),
    _data6(std::move(rhs._data6)),
    _attribute_count(rhs._attribute_count)
  {
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  batch_data<T1, T2, T3, T4, T5, T6> &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::operator=(batch_data<T1, T2, T3, T4, T5, T6> rhs)
  {
    _data1 = std::move(rhs._data1);
    _data2 = std::move(rhs._data2);
    _data3 = std::move(rhs._data3);
    _data4 = std::move(rhs._data4);
    _data5 = std::move(rhs._data5);
    _data6 = std::move(rhs._data6);
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::collection1_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::get_data1() const
  {
    return _data1;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::collection2_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::get_data2() const
  {
    return _data2;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::collection3_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::get_data3() const
  {
    return _data3;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::collection4_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::get_data4() const
  {
    return _data4;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::collection5_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::get_data5() const
  {
    return _data5;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::collection6_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::get_data6() const
  {
    return _data6;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::get_attribute_count() const
  {
    return _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >:: get_bytecount_1() const
  {
    return sizeof(T1) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >:: get_bytecount_2() const
  {
    return sizeof(T2) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >:: get_bytecount_3() const
  {
    return sizeof(T3) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >:: get_bytecount_4() const
  {
    return sizeof(T4) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >:: get_bytecount_5() const
  {
    return sizeof(T5) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >:: get_bytecount_6() const
  {
    return sizeof(T6) * _attribute_count;
  }
}

namespace opengl_graphics // 7 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::batch_data() :
    _attribute_count(0u)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::batch_data(
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
    >::collection1_type data1,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
    >::collection2_type data2,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
    >::collection3_type data3,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
    >::collection4_type data4,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
    >::collection5_type data5,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
    >::collection6_type data6,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
    >::collection7_type data7,
    size_t attribute_count) :
    _data1(std::move(data1)),
    _data2(std::move(data2)),
    _data3(std::move(data3)),
    _data4(std::move(data4)),
    _data5(std::move(data5)),
    _data6(std::move(data6)),
    _data7(std::move(data7)),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::batch_data(const batch_data<T1, T2, T3, T4, T5, T6, T7> &rhs) :
    _data1(std::move(rhs._data1)),
    _data2(std::move(rhs._data2)),
    _data3(std::move(rhs._data3)),
    _data4(std::move(rhs._data4)),
    _data5(std::move(rhs._data5)),
    _data6(std::move(rhs._data6)),
    _data7(std::move(rhs._data7)),
    _attribute_count(rhs._attribute_count)
  {
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  batch_data<T1, T2, T3, T4, T5, T6, T7> &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::operator=(batch_data<T1, T2, T3, T4, T5, T6, T7> rhs)
  {
    _data1 = std::move(rhs._data1);
    _data2 = std::move(rhs._data2);
    _data3 = std::move(rhs._data3);
    _data4 = std::move(rhs._data4);
    _data5 = std::move(rhs._data5);
    _data6 = std::move(rhs._data6);
    _data7 = std::move(rhs._data7);
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::collection1_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::get_data1() const
  {
    return _data1;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::collection2_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::get_data2() const
  {
    return _data2;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::collection3_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::get_data3() const
  {
    return _data3;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::collection4_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::get_data4() const
  {
    return _data4;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::collection5_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::get_data5() const
  {
    return _data5;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::collection6_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::get_data6() const
  {
    return _data6;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::collection7_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::get_data7() const
  {
    return _data7;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::get_attribute_count() const
  {
    return _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >:: get_bytecount_1() const
  {
    return sizeof(T1) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >:: get_bytecount_2() const
  {
    return sizeof(T2) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >:: get_bytecount_3() const
  {
    return sizeof(T3) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >:: get_bytecount_4() const
  {
    return sizeof(T4) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >:: get_bytecount_5() const
  {
    return sizeof(T5) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >:: get_bytecount_6() const
  {
    return sizeof(T6) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >:: get_bytecount_7() const
  {
    return sizeof(T7) * _attribute_count;
  }
}

namespace opengl_graphics // 8 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::batch_data() :
    _attribute_count(0u)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::batch_data(
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
    >::collection1_type data1,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
    >::collection2_type data2,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
    >::collection3_type data3,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
    >::collection4_type data4,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
    >::collection5_type data5,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
    >::collection6_type data6,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
    >::collection7_type data7,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
    >::collection8_type data8,
    size_t attribute_count) :
    _data1(std::move(data1)),
    _data2(std::move(data2)),
    _data3(std::move(data3)),
    _data4(std::move(data4)),
    _data5(std::move(data5)),
    _data6(std::move(data6)),
    _data7(std::move(data7)),
    _data8(std::move(data8)),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::batch_data(const batch_data<T1, T2, T3, T4, T5, T6, T7, T8> &rhs) :
    _data1(std::move(rhs._data1)),
    _data2(std::move(rhs._data2)),
    _data3(std::move(rhs._data3)),
    _data4(std::move(rhs._data4)),
    _data5(std::move(rhs._data5)),
    _data6(std::move(rhs._data6)),
    _data7(std::move(rhs._data7)),
    _data8(std::move(rhs._data8)),
    _attribute_count(rhs._attribute_count)
  {
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  batch_data<T1, T2, T3, T4, T5, T6, T7, T8> &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::operator=(batch_data<T1, T2, T3, T4, T5, T6, T7, T8> rhs)
  {
    _data1 = std::move(rhs._data1);
    _data2 = std::move(rhs._data2);
    _data3 = std::move(rhs._data3);
    _data4 = std::move(rhs._data4);
    _data5 = std::move(rhs._data5);
    _data6 = std::move(rhs._data6);
    _data7 = std::move(rhs._data7);
    _data8 = std::move(rhs._data8);
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::collection1_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_data1() const
  {
    return _data1;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::collection2_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_data2() const
  {
    return _data2;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::collection3_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_data3() const
  {
    return _data3;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::collection4_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_data4() const
  {
    return _data4;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::collection5_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_data5() const
  {
    return _data5;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::collection6_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_data6() const
  {
    return _data6;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::collection7_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_data7() const
  {
    return _data7;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::collection8_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_data8() const
  {
    return _data8;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_attribute_count() const
  {
    return _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >:: get_bytecount_1() const
  {
    return sizeof(T1) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >:: get_bytecount_2() const
  {
    return sizeof(T2) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >:: get_bytecount_3() const
  {
    return sizeof(T3) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >:: get_bytecount_4() const
  {
    return sizeof(T4) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >:: get_bytecount_5() const
  {
    return sizeof(T5) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >:: get_bytecount_6() const
  {
    return sizeof(T6) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >:: get_bytecount_7() const
  {
    return sizeof(T7) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >:: get_bytecount_8() const
  {
    return sizeof(T8) * _attribute_count;
  }
}

namespace opengl_graphics // 9 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  batch_data
    <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::batch_data() :
    _attribute_count(0u)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::batch_data(
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::collection1_type data1,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::collection2_type data2,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::collection3_type data3,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::collection4_type data4,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::collection5_type data5,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::collection6_type data6,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::collection7_type data7,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::collection8_type data8,
    const typename batch_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::collection9_type data9,
    size_t attribute_count) :
    _data1(std::move(data1)),
    _data2(std::move(data2)),
    _data3(std::move(data3)),
    _data4(std::move(data4)),
    _data5(std::move(data5)),
    _data6(std::move(data6)),
    _data7(std::move(data7)),
    _data8(std::move(data8)),
    _data9(std::move(data9)),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::batch_data(const batch_data<T1, T2, T3, T4, T5, T6, T7, T8, T9> &rhs) :
    _data1(std::move(rhs._data1)),
    _data2(std::move(rhs._data2)),
    _data3(std::move(rhs._data3)),
    _data4(std::move(rhs._data4)),
    _data5(std::move(rhs._data5)),
    _data6(std::move(rhs._data6)),
    _data7(std::move(rhs._data7)),
    _data8(std::move(rhs._data8)),
    _data9(std::move(rhs._data9)),
    _attribute_count(rhs._attribute_count)
  {
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  batch_data<T1, T2, T3, T4, T5, T6, T7, T8, T9> &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::operator=(batch_data<T1, T2, T3, T4, T5, T6, T7, T8, T9> rhs)
  {
    _data1 = std::move(rhs._data1);
    _data2 = std::move(rhs._data2);
    _data3 = std::move(rhs._data3);
    _data4 = std::move(rhs._data4);
    _data5 = std::move(rhs._data5);
    _data6 = std::move(rhs._data6);
    _data7 = std::move(rhs._data7);
    _data8 = std::move(rhs._data8);
    _data9 = std::move(rhs._data9);
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::collection1_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_data1() const
  {
    return _data1;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::collection2_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_data2() const
  {
    return _data2;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::collection3_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_data3() const
  {
    return _data3;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::collection4_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_data4() const
  {
    return _data4;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::collection5_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_data5() const
  {
    return _data5;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::collection6_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_data6() const
  {
    return _data6;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::collection7_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_data7() const
  {
    return _data7;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::collection8_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_data8() const
  {
    return _data8;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  const typename batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::collection9_type &
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_data9() const
  {
    return _data9;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_attribute_count() const
  {
    return _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >:: get_bytecount_1() const
  {
    return sizeof(T1) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >:: get_bytecount_2() const
  {
    return sizeof(T2) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >:: get_bytecount_3() const
  {
    return sizeof(T3) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >:: get_bytecount_4() const
  {
    return sizeof(T4) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >:: get_bytecount_5() const
  {
    return sizeof(T5) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >:: get_bytecount_6() const
  {
    return sizeof(T6) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >:: get_bytecount_7() const
  {
    return sizeof(T7) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >:: get_bytecount_8() const
  {
    return sizeof(T8) * _attribute_count;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  batch_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >:: get_bytecount_9() const
  {
    return sizeof(T9) * _attribute_count;
  }
}
