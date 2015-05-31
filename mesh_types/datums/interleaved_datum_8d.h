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
#ifndef INTERLEAVED_DATUM_8D_H_INCLUDED
#define INTERLEAVED_DATUM_8D_H_INCLUDED

namespace gl_wrapper
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7, typename T8
  >
  struct interleaved_datum_8d
  {
  public:
    /*! \brief determine type of the first interleaved type
     */
    typedef T1 internal_type1;

    /*! \brief determine type of the second interleaved type
     */
    typedef T2 internal_type2;

    /*! \brief determine type of the third interleaved type
     */
    typedef T3 internal_type3;

    /*! \brief determine type of the fourth interleaved type
     */
    typedef T4 internal_type4;

    /*! \brief determine type of the fifth interleaved type
     */
    typedef T5 internal_type5;

    /*! \brief determine type of the sixth interleaved type
     */
    typedef T6 internal_type6;

    /*! \brief determine type of the seventh interleaved type
     */
    typedef T7 internal_type7;

    /*! \brief determine type of the eighth interleaved type
     */
    typedef T8 internal_type8;

    /*! \brief first component in interleaved data
     */
    T1 _datum1;

    /*! \brief second component in interleaved data
     */
    T2 _datum2;

    /*! \brief third component in interleaved data
     */
    T3 _datum3;

    /*! \brief fourth component in interleaved data
     */
    T4 _datum4;

    /*! \brief fifth component in interleaved data
     */
    T5 _datum5;

    /*! \brief sixth component in interleaved data
     */
    T6 _datum6;

    /*! \brief seventh component in interleaved data
     */
    T7 _datum7;

    /*! \brief eighth component in interleaved data
     */
    T8 _datum8;

    /*! \brief default constructor
     */
    interleaved_datum_8d();

    /*! \brief constructor
     */
    interleaved_datum_8d(const T1 &datum_1, const T2 &datum_2,
      const T3 &datum_3, const T4 &datum_4, const T5 &datum_5,
      const T6 &datum_6, const T7 &datum_7, const T8 &datum_8);

    /*! \brief copy constructor
     */
    interleaved_datum_8d(const interleaved_datum_8d &rhs);

    /*! \brief assignment uses copy-swap idiom
     */
    interleaved_datum_8d &operator=(interleaved_datum_8d rhs);
  };
}

#include "interleaved_datum_8d.inl"
#endif
