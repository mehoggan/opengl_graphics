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
#ifndef INTERLEAVED_DATUM_2D_H_INCLUDED
#define INTERLEAVED_DATUM_2D_H_INCLUDED

namespace gl_wrapper
{
  template <typename T1, typename T2>
  struct interleaved_datum_2d
  {
  public:
    /*! \brief determine type of the first interleaved type
     */
    typedef T1 internal_type1;

    /*! \brief determine type of the first interleaved type
     */
    typedef T2 internal_type2;

    /*! \brief first component in interleaved data
     */
    T1 _datum1;

    /*! \brief second component in interleaved data
     */
    T2 _datum2;

    /*! \brief default constructor
     */
    interleaved_datum_2d();

    /*! \brief constructor
     */
    interleaved_datum_2d(const T1 &datum_1, const T2 &datum_2);

    /*! \brief copy constructor
     */
    interleaved_datum_2d(const interleaved_datum_2d &rhs);

    /*! \brief assignment uses copy-swap idiom
     */
    interleaved_datum_2d &operator=(interleaved_datum_2d rhs);
  };
}

#include "interleaved_datum_2d.inl"
#endif
