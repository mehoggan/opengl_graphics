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
#ifndef INTERLEAVED_DATA_H_INCLUDED
#define INTERLEAVED_DATA_H_INCLUDED

#include "mesh_types/datums/interleaved_datum_2d.h"
#include "mesh_types/datums/interleaved_datum_3d.h"
#include "mesh_types/datums/interleaved_datum_4d.h"
#include "mesh_types/datums/interleaved_datum_5d.h"
#include "mesh_types/datums/interleaved_datum_6d.h"
#include "mesh_types/datums/interleaved_datum_7d.h"
#include "mesh_types/datums/interleaved_datum_8d.h"
#include "mesh_types/datums/interleaved_datum_9d.h"
#include "mesh_types/interleaved_traits.h"
#include "core/platform.h"
#include "ref_count/shared_array/shared_array.h"
#include "utils/utils.h"

namespace opengl_graphics
{
  template
  <
    typename T1, typename T2 = nat, typename T3 = nat, typename T4 = nat,
    typename T5 = nat, typename T6 = nat, typename T7 = nat, typename T8 = nat,
    typename T9 = nat, typename T10 = nat
  >
  struct interleaved_data;
}

namespace opengl_graphics // 2 attributes
{
  template
  <
    typename T1, typename T2
  >
  struct interleaved_data<T1, T2, nat, nat, nat, nat, nat, nat, nat, nat>
  {
  public:
    typedef interleaved_datum_2d<T1, T2> datum_type;
    typedef shared_array<datum_type> collection_type;

    typedef msvc_typename interleaved_traits
    <
      T1, T2, nat, nat, nat, nat, nat, nat, nat
    > traits;
    static const bool is_interleaved = true;

  private:
    collection_type _data;
    size_t _attribute_count;

  public:
    interleaved_data();
    interleaved_data(const collection_type data, size_t attribute_count);

    interleaved_data(const interleaved_data &rhs);
    interleaved_data &operator=(interleaved_data rhs);

    collection_type get_data() const;

    size_t get_attribute_count() const;
    size_t get_byte_count() const;
  };
}

namespace opengl_graphics // 3 attributes
{
  template
  <
    typename T1, typename T2, typename T3
  >
  struct interleaved_data<T1, T2, T3, nat, nat, nat, nat, nat, nat, nat>
  {
  public:
    typedef interleaved_datum_3d<T1, T2, T3> datum_type;
    typedef shared_array<datum_type> collection_type;

    typedef msvc_typename interleaved_traits
    <
      T1, T2, T3, nat, nat, nat, nat, nat, nat
    > traits;
    static const bool is_interleaved = true;

  private:
    collection_type _data;
    size_t _attribute_count;

  public:
    interleaved_data();
    interleaved_data(const collection_type data, size_t attribute_count);

    interleaved_data(const interleaved_data &rhs);
    interleaved_data &operator=(interleaved_data rhs);

    collection_type get_data() const;

    size_t get_attribute_count() const;
    size_t get_byte_count() const;
  };
}

namespace opengl_graphics // 4 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4
  >
  struct interleaved_data<T1, T2, T3, T4, nat, nat, nat, nat, nat, nat>
  {
  public:
    typedef interleaved_datum_4d<T1, T2, T3, T4> datum_type;
    typedef shared_array<datum_type> collection_type;

    typedef msvc_typename interleaved_traits
    <
      T1, T2, T3, T4, nat, nat, nat, nat, nat
    > traits;
    static const bool is_interleaved = true;

  private:
    collection_type _data;
    size_t _attribute_count;

  public:
    interleaved_data();
    interleaved_data(const collection_type data, size_t attribute_count);

    interleaved_data(const interleaved_data &rhs);
    interleaved_data &operator=(interleaved_data rhs);

    collection_type get_data() const;

    size_t get_attribute_count() const;
    size_t get_byte_count() const;
  };
}

namespace opengl_graphics // 5 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5
  >
  struct interleaved_data<T1, T2, T3, T4, T5, nat, nat, nat, nat, nat>
  {
  public:
    typedef interleaved_datum_5d<T1, T2, T3, T4, T5> datum_type;
    typedef shared_array<datum_type> collection_type;

    typedef msvc_typename interleaved_traits
    <
      T1, T2, T3, T4, T5, nat, nat, nat, nat
    > traits;
    static const bool is_interleaved = true;

  private:
    collection_type _data;
    size_t _attribute_count;

  public:
    interleaved_data();
    interleaved_data(const collection_type data, size_t attribute_count);

    interleaved_data(const interleaved_data &rhs);
    interleaved_data &operator=(interleaved_data rhs);

    collection_type get_data() const;

    size_t get_attribute_count() const;
    size_t get_byte_count() const;
  };
}

namespace opengl_graphics // 6 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6
  >
  struct interleaved_data<T1, T2, T3, T4, T5, T6, nat, nat, nat, nat>
  {
  public:
    typedef interleaved_datum_6d<T1, T2, T3, T4, T5, T6> datum_type;
    typedef shared_array<datum_type> collection_type;

    typedef msvc_typename interleaved_traits
    <
      T1, T2, T3, T4, T5, T6, nat, nat, nat
    > traits;
    static const bool is_interleaved = true;

  private:
    collection_type _data;
    size_t _attribute_count;

  public:
    interleaved_data();
    interleaved_data(const collection_type data, size_t attribute_count);

    interleaved_data(const interleaved_data &rhs);
    interleaved_data &operator=(interleaved_data rhs);

    collection_type get_data() const;

    size_t get_attribute_count() const;
    size_t get_byte_count() const;
  };
}

namespace opengl_graphics // 7 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  struct interleaved_data<T1, T2, T3, T4, T5, T6, T7, nat, nat, nat>
  {
  public:
    typedef interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7> datum_type;
    typedef shared_array<datum_type> collection_type;

    typedef msvc_typename interleaved_traits
    <
      T1, T2, T3, T4, T5, T6, T7, nat, nat
    > traits;
    static const bool is_interleaved = true;

  private:
    collection_type _data;
    size_t _attribute_count;

  public:
    interleaved_data();
    interleaved_data(const collection_type data, size_t attribute_count);

    interleaved_data(const interleaved_data &rhs);
    interleaved_data &operator=(interleaved_data rhs);

    collection_type get_data() const;

    size_t get_attribute_count() const;
    size_t get_byte_count() const;
  };
}

namespace opengl_graphics // 8 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  struct interleaved_data<T1, T2, T3, T4, T5, T6, T7, T8, nat, nat>
  {
  public:
    typedef interleaved_datum_8d<T1, T2, T3, T4, T5, T6, T7, T8> datum_type;
    typedef shared_array<datum_type> collection_type;

    typedef msvc_typename interleaved_traits
    <
      T1, T2, T3, T4, T5, T6, T7, T8, nat
    > traits;
    static const bool is_interleaved = true;

  private:
    collection_type _data;
    size_t _attribute_count;

  public:
    interleaved_data();
    interleaved_data(const collection_type data, size_t attribute_count);

    interleaved_data(const interleaved_data &rhs);
    interleaved_data &operator=(interleaved_data rhs);

    collection_type get_data() const;

    size_t get_attribute_count() const;
    size_t get_byte_count() const;
  };
}

namespace opengl_graphics // 9 attributes
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8, typename T9
  >
  struct interleaved_data<T1, T2, T3, T4, T5, T6, T7, T8, T9, nat>
  {
  public:
    typedef interleaved_datum_9d<T1, T2, T3, T4, T5, T6, T7, T8, T9> datum_type;
    typedef shared_array<datum_type> collection_type;

    typedef msvc_typename interleaved_traits
    <
      T1, T2, T3, T4, T5, T6, T7, T8, T9
    > traits;
    static const bool is_interleaved = true;

  private:
    collection_type _data;
    size_t _attribute_count;

  public:
    interleaved_data();
    interleaved_data(const collection_type data, size_t attribute_count);

    interleaved_data(const interleaved_data &rhs);
    interleaved_data &operator=(interleaved_data rhs);

    collection_type get_data() const;

    size_t get_attribute_count() const;
    size_t get_byte_count() const;
  };
}

#include "interleaved_data.inl"
#endif
