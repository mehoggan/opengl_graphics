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
#ifndef INTERLEAVED_TRAITS_H_INCLUDED
#define INTERLEAVED_TRAITS_H_INCLUDED

#include "core/platform.h"
#include "type_traits/sizeof.h"
#include "utils/utils.h"

namespace opengl_graphics
{
  template<typename T>
  struct attribute_dimension
  {
    static const size_t value = msvc_typename T::dimension;
  };

  template<>
  struct attribute_dimension<nat>
  {
    static const size_t value = 0;
  };

  template
  <
    typename T1, typename T2 = nat, typename T3 = nat, typename T4 = nat,
    typename T5 = nat, typename T6 = nat, typename T7 = nat, typename T8 = nat,
    typename T9 = nat
  >
  struct interleaved_traits
  {
    enum traits
    {
      type1_sizeof = type_traits::size::size_of<T1>::value,
      type2_sizeof = type_traits::size::size_of<T2>::value,
      type3_sizeof = type_traits::size::size_of<T3>::value,
      type4_sizeof = type_traits::size::size_of<T4>::value,
      type5_sizeof = type_traits::size::size_of<T5>::value,
      type6_sizeof = type_traits::size::size_of<T6>::value,
      type7_sizeof = type_traits::size::size_of<T7>::value,
      type8_sizeof = type_traits::size::size_of<T8>::value,
      type9_sizeof = type_traits::size::size_of<T9>::value,

      stride = type1_sizeof + type2_sizeof + type3_sizeof + type4_sizeof +
        type5_sizeof + type6_sizeof + type7_sizeof + type8_sizeof +
        type9_sizeof,

      type1_dimension = attribute_dimension<T1>::value,
      type2_dimension = attribute_dimension<T2>::value,
      type3_dimension = attribute_dimension<T3>::value,
      type4_dimension = attribute_dimension<T4>::value,
      type5_dimension = attribute_dimension<T5>::value,
      type6_dimension = attribute_dimension<T6>::value,
      type7_dimension = attribute_dimension<T7>::value,
      type8_dimension = attribute_dimension<T8>::value,
      type9_dimension = attribute_dimension<T9>::value,

      attribute_val_count = type1_dimension + type2_dimension +
        type3_dimension + type4_dimension + type5_dimension +
        type6_dimension + type7_dimension + type8_dimension +
        type9_dimension,

      type1_byte_offset = 0,
      type2_byte_offset = type1_sizeof,
      type3_byte_offset = type2_byte_offset + type2_sizeof,
      type4_byte_offset = type3_byte_offset + type3_sizeof,
      type5_byte_offset = type4_byte_offset + type4_sizeof,
      type6_byte_offset = type5_byte_offset + type5_sizeof,
      type7_byte_offset = type6_byte_offset + type6_sizeof,
      type8_byte_offset = type7_byte_offset + type7_sizeof,
      type9_byte_offset = type8_byte_offset + type8_sizeof,
    };
  };
}

#endif
