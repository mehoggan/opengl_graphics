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
namespace gl_wrapper // 2 attributes
{
  template
  <
    typename T1, typename T2
  >
  interleaved_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::interleaved_data() :
    _attribute_count(0)
  {}

  template
  <
    typename T1, typename T2
  >
  interleaved_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::interleaved_data(
    const typename interleaved_data
    <
      T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
    >::collection_type data, size_t attribute_count) :
    _data(data),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2
  >
  interleaved_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::interleaved_data(
    const interleaved_data<T1, T2> &rhs) :
    _data(rhs._data),
    _attribute_count(rhs._attribute_count)
  {}

  template
  <
    typename T1, typename T2
  >
  interleaved_data<T1, T2> &
  interleaved_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::operator=(interleaved_data<T1, T2> rhs)
  {
    _data = rhs._data;
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1, typename T2
  >
  typename interleaved_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::collection_type
  interleaved_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::get_data() const
  {
    return _data;
  }

  template
  <
    typename T1, typename T2
  >
  size_t
  interleaved_data
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
  interleaved_data
  <
    T1, T2, nat, nat, nat, nat, nat, nat, nat, nat
  >::get_byte_count() const
  {
    return (sizeof(T1) + sizeof(T2)) * _attribute_count;
  }
}

namespace gl_wrapper // 3 attributes
{
  template
  <
    typename T1, typename T2, typename T3
  >
  interleaved_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::interleaved_data() :
    _attribute_count(0)
  {}

  template
  <
    typename T1, typename T2, typename T3
  >
  interleaved_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::interleaved_data(
    const typename interleaved_data
    <
      T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
    >::collection_type data,
    size_t attribute_count) :
    _data(data),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3
  >
  interleaved_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::interleaved_data(
    const interleaved_data<T1, T2, T3> &rhs) :
    _data(rhs._data),
    _attribute_count(rhs._attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3
  >
  interleaved_data<T1, T2, T3> &
  interleaved_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::operator=(interleaved_data<T1, T2, T3> rhs)
  {
    _data = rhs._data;
    _attribute_count = rhs._attribute_count;

    return (*this);
  }

  template
  <
    typename T1, typename T2, typename T3
  >
  typename interleaved_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::collection_type
  interleaved_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::get_data() const
  {
    return _data;
  }

  template
  <
    typename T1, typename T2, typename T3
  >
  size_t
  interleaved_data
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
  interleaved_data
  <
    T1, T2, T3, nat, nat, nat, nat, nat, nat, nat
  >::get_byte_count() const
  {
    return (sizeof(T1) + sizeof(T2) + sizeof(T3)) * _attribute_count;
  }
}

namespace gl_wrapper // 4 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  interleaved_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::interleaved_data() :
    _attribute_count(0)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  interleaved_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::interleaved_data(
    const typename interleaved_data
    <
      T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
    >::collection_type data,
    size_t attribute_count) :
    _data(data),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  interleaved_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::interleaved_data(
    const interleaved_data<T1, T2, T3, T4> &rhs) :
    _data(rhs._data),
    _attribute_count(rhs._attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  interleaved_data<T1, T2, T3, T4> &
  interleaved_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::operator=(interleaved_data<T1, T2, T3, T4> rhs)
  {
    _data = rhs._data;
    _attribute_count = rhs._attribute_count;

    return (*this);

  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  typename interleaved_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::collection_type
  interleaved_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::get_data() const
  {
    return _data;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  size_t
  interleaved_data
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
  interleaved_data
  <
    T1, T2, T3, T4, nat, nat, nat, nat, nat, nat
  >::get_byte_count() const
  {
    return (sizeof(T1) + sizeof(T2) + sizeof(T3) + sizeof(T4)) *
      _attribute_count;
  }
}

namespace gl_wrapper // 5 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::interleaved_data() :
    _attribute_count(0)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::interleaved_data(
    const typename interleaved_data
    <
      T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
    >::collection_type data,
    size_t attribute_count) :
    _data(data),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::interleaved_data(
    const interleaved_data<T1, T2, T3, T4, T5> &rhs) :
    _data(rhs._data),
    _attribute_count(rhs._attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  interleaved_data<T1, T2, T3, T4, T5> &
  interleaved_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::operator=(interleaved_data<T1, T2, T3, T4, T5> rhs)
  {
    _data = rhs._data;
    _attribute_count = rhs._attribute_count;

    return (*this);

  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  typename interleaved_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::collection_type
  interleaved_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::get_data() const
  {
    return _data;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  size_t
  interleaved_data
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
  interleaved_data
  <
    T1, T2, T3, T4, T5, nat, nat, nat, nat, nat
  >::get_byte_count() const
  {
    return (sizeof(T1) + sizeof(T2) + sizeof(T3) + sizeof(T4) + sizeof(T5)) *
      _attribute_count;
  }
}

namespace gl_wrapper // 6 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::interleaved_data() :
    _attribute_count(0)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::interleaved_data(
    const typename interleaved_data
    <
      T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
    >::collection_type data,
    size_t attribute_count) :
    _data(data),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::interleaved_data(
    const interleaved_data<T1, T2, T3, T4, T5, T6> &rhs) :
    _data(rhs._data),
    _attribute_count(rhs._attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  interleaved_data<T1, T2, T3, T4, T5, T6> &
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::operator=(interleaved_data<T1, T2, T3, T4, T5, T6> rhs)
  {
    _data = rhs._data;
    _attribute_count = rhs._attribute_count;

    return (*this);

  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  typename interleaved_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::collection_type
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::get_data() const
  {
    return _data;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  size_t
  interleaved_data
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
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, nat, nat, nat, nat
  >::get_byte_count() const
  {
    return (sizeof(T1) + sizeof(T2) + sizeof(T3) + sizeof(T4) + sizeof(T5) +
      sizeof(T6)) * _attribute_count;
  }
}

namespace gl_wrapper // 7 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::interleaved_data() :
    _attribute_count(0)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::interleaved_data(
    const typename interleaved_data
    <
      T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
    >::collection_type data,
    size_t attribute_count) :
    _data(data),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::interleaved_data(
    const interleaved_data<T1, T2, T3, T4, T5, T6, T7> &rhs) :
    _data(rhs._data),
    _attribute_count(rhs._attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  interleaved_data<T1, T2, T3, T4, T5, T6, T7> &
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::operator=(interleaved_data<T1, T2, T3, T4, T5, T6, T7> rhs)
  {
    _data = rhs._data;
    _attribute_count = rhs._attribute_count;

    return (*this);

  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  typename interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::collection_type
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::get_data() const
  {
    return _data;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  size_t
  interleaved_data
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
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, nat, nat, nat
  >::get_byte_count() const
  {
    return (sizeof(T1) + sizeof(T2) + sizeof(T3) + sizeof(T4) + sizeof(T5) +
      sizeof(T6) + sizeof(T7)) * _attribute_count;
  }
}

namespace gl_wrapper // 8 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::interleaved_data() :
    _attribute_count(0)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::interleaved_data(
    const interleaved_data<T1, T2, T3, T4, T5, T6, T7, T8> &rhs) :
    _data(rhs._data),
    _attribute_count(rhs._attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  interleaved_data<T1, T2, T3, T4, T5, T6, T7, T8> &
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::operator=(interleaved_data<T1, T2, T3, T4, T5, T6, T7, T8> rhs)
  {
    _data = rhs._data;
    _attribute_count = rhs._attribute_count;

    return (*this);

  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::interleaved_data(
    const typename interleaved_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
    >::collection_type data, size_t attribute_count) :
    _data(data),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  typename interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::collection_type
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_data() const
  {
    return _data;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  size_t
  interleaved_data
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
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, nat, nat
  >::get_byte_count() const
  {
    return (sizeof(T1) + sizeof(T2) + sizeof(T3) + sizeof(T4) + sizeof(T5) +
      sizeof(T6) + sizeof(T7) + sizeof(T8)) * _attribute_count;
  }
}

namespace gl_wrapper // 9 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::interleaved_data() :
    _attribute_count(0)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::interleaved_data(
    const typename interleaved_data
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
    >::collection_type data, size_t attribute_count) :
    _data(data),
    _attribute_count(attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::interleaved_data(
    const interleaved_data<T1, T2, T3, T4, T5, T6, T7, T8, T9> &rhs) :
    _data(rhs._data),
    _attribute_count(rhs._attribute_count)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  interleaved_data<T1, T2, T3, T4, T5, T6, T7, T8, T9> &
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::operator=(interleaved_data<T1, T2, T3, T4, T5, T6, T7, T8, T9> rhs)
  {
    _data = rhs._data;
    _attribute_count = rhs._attribute_count;

    return (*this);

  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  typename interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::collection_type
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_data() const
  {
    return _data;
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  size_t
  interleaved_data
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
  interleaved_data
  <
    T1, T2, T3, T4, T5, T6, T7, T8, T9, nat
  >::get_byte_count() const
  {
    return (sizeof(T1) + sizeof(T2) + sizeof(T3) + sizeof(T4) + sizeof(T5) +
      sizeof(T6) + sizeof(T7) + sizeof(T8) + sizeof(T9)) * _attribute_count;
  }
}
