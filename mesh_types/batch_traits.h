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
#ifndef BATCH_TRAITS_H_INCLUDED
#define BATCH_TRAITS_H_INCLUDED

#include <graphics/utils/utils.h>

namespace gl_wrapper
{
  template
  <
    typename T1, typename T2 = nat, typename T3 = nat, typename T4 = nat,
    typename T5 = nat, typename T6 = nat, typename T7 = nat, typename T8 = nat,
    typename T9 = nat
  >
  struct batch_traits
  {
    enum traits
    {
      stride = 0u
    };
  };
}

#endif
