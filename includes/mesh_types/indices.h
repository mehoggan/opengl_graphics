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
#ifndef INDICES_H_INCLUDED
#define INDICES_H_INCLUDED

#include "core/platform.h"
#include "ref_count/shared_array/shared_array.h"
#include "utils/utils.h"

#include <type_traits>

namespace opengl_graphics // 2 attributes
{
  template<typename T>
  struct indices
  {
  public:
    typedef T index_type;
    static_assert(std::is_integral<index_type>::value,
      "Integer type required");
    typedef shared_array<index_type> collection_type;

  private:
    collection_type _data;
    size_t _index_count;

  public:
    indices();
    indices(const collection_type data, size_t index_count);

    indices(const indices &rhs);
    indices &operator=(indices rhs);

    collection_type get_data() const;

    size_t get_byte_count() const;
    size_t get_indices_count() const;
  };
}
#include "indices.inl"
#endif
