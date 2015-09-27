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
#ifndef SIZEOF_TYPE_TRAITS_H_INCLUDED
#define SIZEOF_TYPE_TRAITS_H_INCLUDED

#include "utils/utils.h"

namespace opengl_graphics
{
  namespace type_traits
  {
    namespace size
    {
      template<typename T>
      struct size_of
      {
        static const size_t value = sizeof(T);
      };

      template<>
      struct size_of<nat>
      {
        static const size_t value = 0;
      };
    }
  }
}
#endif

