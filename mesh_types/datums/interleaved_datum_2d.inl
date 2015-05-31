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
namespace gl_wrapper
{
  template <typename T1, typename T2>
  interleaved_datum_2d<T1, T2>::interleaved_datum_2d()
  {}

  template <typename T1, typename T2>
  interleaved_datum_2d<T1, T2>::interleaved_datum_2d(const T1 &datum_1,
    const T2 &datum_2) :
    _datum1(datum_1),
    _datum2(datum_2)
  {}

  template <typename T1, typename T2>
  interleaved_datum_2d<T1, T2>::interleaved_datum_2d(
    const interleaved_datum_2d<T1, T2> &rhs) :
    _datum1(rhs._datum1),
    _datum2(rhs._datum2)
  {}

  template <typename T1, typename T2>
  interleaved_datum_2d<T1, T2> &interleaved_datum_2d<T1, T2>::operator=(
    interleaved_datum_2d<T1, T2> rhs)
  {
    swap((*this), rhs);

    return (*this);
  }

  /// Copy and swap idiom
  template <typename T1, typename T2>
  void swap(interleaved_datum_2d<T1, T2> &lhs,
    interleaved_datum_2d<T1, T2> &rhs)
  {
    std::swap(lhs._datum1, rhs._datum1);
    std::swap(lhs._datum2, rhs._datum2);
  }

  template <typename T1, typename T2>
  bool operator==(const interleaved_datum_2d<T1, T2> &lhs,
    const interleaved_datum_2d<T1, T2> &rhs)
  {
    return (lhs._datum1 == rhs._datum1 && lhs._datum2 == rhs._datum2);
  }

  template <typename T1, typename T2>
  bool operator!=(const interleaved_datum_2d<T1, T2> &lhs,
    const interleaved_datum_2d<T1, T2> &rhs)
  {
    return (lhs._datum1 != rhs._datum1 || lhs._datum2 != rhs._datum2);
  }
}
