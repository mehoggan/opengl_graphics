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
namespace opengl_graphics
{
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7>::interleaved_datum_7d()
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7>::interleaved_datum_7d(
    const T1 &datum_1, const T2 &datum_2, const T3 &datum_3, const T4 &datum_4,
    const T5 &datum_5, const T6 &datum_6, const T7 &datum_7) :
    _datum1(datum_1),
    _datum2(datum_2),
    _datum3(datum_3),
    _datum4(datum_4),
    _datum5(datum_5),
    _datum6(datum_6),
    _datum7(datum_7)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7>::interleaved_datum_7d(
    const interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7> &rhs) :
    _datum1(rhs._datum1),
    _datum2(rhs._datum2),
    _datum3(rhs._datum3),
    _datum4(rhs._datum4),
    _datum5(rhs._datum5),
    _datum6(rhs._datum6),
    _datum7(rhs._datum7)
  {}

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7> &
    interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7>::operator=(
    interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7> rhs)
  {
    swap((*this), rhs);

    return (*this);
  }

  /// Copy and swap idiom
  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  void swap(interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7> &lhs,
    interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7> &rhs)
  {
    std::swap(lhs._datum1, rhs._datum1);
    std::swap(lhs._datum2, rhs._datum2);
    std::swap(lhs._datum3, rhs._datum3);
    std::swap(lhs._datum4, rhs._datum4);
    std::swap(lhs._datum5, rhs._datum5);
    std::swap(lhs._datum6, rhs._datum6);
    std::swap(lhs._datum7, rhs._datum7);
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  bool operator==(const interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7> &lhs,
    const interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7> &rhs)
  {
    return (lhs._datum1 == rhs._datum1 && lhs._datum2 == rhs._datum2 &&
      lhs._datum3 == rhs._datum3 && lhs._datum4 == rhs._datum4 &&
      lhs._datum5 == rhs._datum5 && lhs._datum6 == rhs._datum6 &&
      lhs._datum7 == rhs._datum7);
  }

  template
  <
    typename T1, typename T2, typename T3, typename T4, typename T5,
    typename T6, typename T7
  >
  bool operator!=(const interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7> &lhs,
    const interleaved_datum_7d<T1, T2, T3, T4, T5, T6, T7> &rhs)
  {
    return (lhs._datum1 != rhs._datum1 || lhs._datum2 != rhs._datum2 ||
      lhs._datum3 != rhs._datum3 || lhs._datum4 != rhs._datum4 ||
      lhs._datum5 != rhs._datum5 || lhs._datum6 != rhs._datum6 ||
      lhs._datum7 != rhs._datum7);
  }
}
