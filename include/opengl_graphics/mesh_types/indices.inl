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
namespace opengl_graphics // 2 attributes
{
  template<typename T>
  indices<T>::indices() :
    _index_count(0)
  {}

  template<typename T>
  indices<T>::indices(const typename indices<T>::collection_type data,
    size_t index_count) :
    _data(data),
    _index_count(index_count)
  {}

  template<typename T>
  indices<T>::indices(const indices<T> &rhs) :
    _data(rhs._data),
    _index_count(rhs._index_count)
  {}

  template<typename T>
  indices<T> &indices<T>::operator=(indices<T> rhs)
  {
    _data = rhs._data;
    _index_count = rhs._index_count;

    return (*this);
  }

  template<typename T>
  typename indices<T>::collection_type indices<T>::get_data() const
  {
    return _data;
  }

  template<typename T>
  size_t indices<T>::get_byte_count() const
  {
    return sizeof(T) * _index_count;
  }

  template <typename T>
  size_t indices<T>::get_indices_count() const
  {
    return _index_count;
  }

  template <typename T>
  bool operator==(const indices<T> &lhs, const indices<T> &rhs)
  {
    return (lhs.get_data() == rhs.get_data());
  }

  template <typename T>
  bool operator!=(const indices<T> &lhs, const indices<T> &rhs)
  {
    return !(lhs == rhs);
  }
}
