/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:51:28 by yehyun            #+#    #+#             */
/*   Updated: 2023/01/27 13:08:47 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <memory>
#include "iterator.hpp"
#include "utils.hpp"

namespace ft {

template <typename T, typename Alloc = std::allocator<T> >
class vector {
 public:
  typedef T value_type;
  typedef typename Alloc::template rebind<T>::other allocator_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  pointer _data;
  allocator_type _alloc;
  size_type _capacity;
  size_type _size;

 public:
  explicit vector(const allocator_type& alloc = allocator_type())
      : _data(pointer()),
        _alloc(alloc),
        _capacity(size_type()),
        _size(size_type()) {}

  explicit vector(size_type n,
                  const_reference val = value_type(),
                  const allocator_type& alloc = allocator_type())
      : _alloc(alloc), _capacity(n), _size(n) {
    _data = _alloc.allocate(n);
    for (size_type i = 0; i < _size; i++)
      _data[i] = val;
  }

  template <typename InputIterator>
  vector(InputIterator first,
         InputIterator last,
         const allocator_type& alloc = allocator_type(),
         typename enable_if<!is_integral<InputIterator>::value,
                            InputIterator>::value* = NULL) {
    size_type tmpSize = static_cast<size_type>(std::distance(first, last));
    _alloc = alloc;
    _capacity = tmpSize;
    _size = tmpSize;
    _data = _alloc.allocate(_capacity);
    for (size_type i = 0; i != _size; ++i)
      _data[i] = *(first++);
  }

  vector(const vector& rhs)
      : _data(pointer()),
        _alloc(rhs._alloc),
        _capacity(size_type()),
        _size(size_type()) {
    *this = rhs;
  }

  vector& operator=(const vector& rhs) {
    if (this == &rhs)
      return (*this);
    if (_data != pointer())
      _alloc.deallocate(_data, _capacity);
    _alloc = rhs._alloc;
    _size = rhs._size;
    _capacity = rhs._capacity;
    _data = _alloc.allocate(_capacity);
    for (size_type i = 0; i != _size; ++i)
      _data[i] = rhs._data[i];
    return (*this);
  }

  ~vector() {
    if (_data != NULL)
      _alloc.deallocate(_data, _capacity);
  }

  void swap(vector& x) {
    std::swap(this->_data, x._data);
    std::swap(this->_size, x._size);
    std::swap(this->_capacity, x._capacity);
    std::swap(this->_alloc, x._alloc);
  }

  bool empty() const { return (_size == 0); }
  size_type size() const { return (_size); }
  size_type capacity() const { return (_capacity); }

  template <typename InputIterator>
  void assign(InputIterator first,
              InputIterator last,
              typename enable_if<!is_integral<InputIterator>::value,
                                 InputIterator>::value* = NULL) {
    size_type tmpSize = std::distance(first, last);
    size_type i = 0;

    if (tmpSize > _capacity)
      reserve(tmpSize);
    for (InputIterator it = first; it != last; ++it) {
      _data[i] = *it;
      ++i;
    }
    _size = tmpSize;
  }

  void assign(size_type n, const_reference val) {
    if (n > _capacity)
      reserve(n);
    for (size_type i = 0; i < n; i++)
      _data[i] = val;
    _size = n;
  }

  reference at(size_type n) {
    if (n >= _size)
      throw std::out_of_range("input val out of range\n");
    return (_data[n]);
  }

  const_reference at(size_type n) const {
    if (n >= _size)
      throw std::out_of_range("input val out of range\n");
    return (_data[n]);
  }

  reference back() { return (_data[_size - 1]); }
  const_reference back() const { return (_data[_size - 1]); }
  reference front() { return (_data[0]); }
  const_reference front() const { return (_data[0]); }

  iterator begin() { return (_data); }
  const_iterator begin() const { return (_data); }
  iterator end() { return (&_data[_size]); }
  const_iterator end() const { return (&_data[_size]); }

  reverse_iterator rbegin() { return (reverse_iterator(end())); }
  const_reverse_iterator rbegin() const {
    return (const_reverse_iterator(end()));
  }
  reverse_iterator rend() { return (reverse_iterator(begin())); }
  const_reverse_iterator rend() const {
    return (const_reverse_iterator(begin()));
  }

  iterator erase(iterator position) {
    for (iterator it = position; it != end() - 1; ++it)
      *it = *(it + 1);
    --_size;
    return (position);
  }

  iterator erase(iterator first, iterator last) {
    difference_type dist = std::distance(first, last);

    for (iterator it = first; it != end() - dist; ++it) {
      *it = *(it + dist);
    }
    _size -= dist;
    return (first);
  }

  iterator insert(iterator position, const_reference val) {
    size_type posIdx = static_cast<size_type>(std::distance(begin(), position));

    if (_size + 1 > _capacity)
      reserve(_size + 1);
    ++_size;
    for (size_type i = _size - 1; i != posIdx; --i)
      _data[i] = _data[i - 1];
    _data[posIdx] = val;
    return (&_data[posIdx]);
  }

  void insert(iterator position, size_type n, const_reference val) {
    size_type posIdx = static_cast<size_type>(std::distance(begin(), position));

    if (_size + n > _capacity)
      reserve(_size + n);
    _size += n;
    for (size_type i = _size - 1; i != posIdx + n - 1; --i)
      _data[i] = _data[i - n];
    for (size_type j = posIdx + n - 1; j != posIdx - 1; --j)
      _data[j] = val;
  }

  template <typename InputIterator>
  void insert(iterator position,
              InputIterator first,
              InputIterator last,
              typename enable_if<!is_integral<InputIterator>::value,
                                 InputIterator>::value* = NULL) {
    size_type tmpSize = static_cast<size_type>(std::distance(first, last));
    size_type posIdx(0);

    while (&_data[posIdx] != position)
      posIdx++;
    if (_size + tmpSize > _capacity)
      reserve(_size + tmpSize);
    _size += tmpSize;
    for (size_type i = _size - 1; i != posIdx + tmpSize - 1; --i)
      _data[i] = _data[i - tmpSize];
    for (size_type j = posIdx; j != posIdx + tmpSize; ++j)
      _data[j] = *(first++);
  }

  void clear() {
    for (size_type i = 0; i < _size; i++)
      _data[i] = value_type();
    _size = 0;
  }

  allocator_type get_allocator() const { return (_alloc); }

  size_type max_size() const { return (_alloc.max_size()); }

  reference operator[](unsigned int index) { return (_data[index]); }
  const_reference operator[](unsigned int index) const {
    return (_data[index]);
  }

  void pop_back() {
    if (!_size)
      return;
    --_size;
  }

  void push_back(const_reference val) {
    if (_size + 1 > _capacity)
      reserve(((_capacity + 1) * 2));
    _data[_size] = val;
    ++_size;
  }

  void reserve(size_type n) {
    T* TmpVec;

    if (n > max_size())
      throw std::length_error("can't allocate more than max size");
    if (n <= _capacity)
      return;
    TmpVec = _alloc.allocate(n);
    if (_data) {
      for (size_type i = 0; i != _size; ++i)
        TmpVec[i] = _data[i];
      _alloc.deallocate(_data, _capacity);
    }
    _capacity = n;
    _data = TmpVec;
  }

  void resize(size_type n, value_type val = value_type()) {
    if (n == _size)
      return;
    else {
      if (n > _capacity)
        reserve(n);
      for (size_type i = _size; i < n; i++)
        _data[i] = val;
    }
    _size = n;
  }

  friend bool operator==(const vector& lhs, const vector& rhs) {
    if (lhs._size != rhs._size)
      return (false);
    return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
  }

  friend bool operator!=(const vector& lhs, const vector& rhs) {
    return (!(lhs == rhs));
  }

  friend bool operator<(const vector& lhs, const vector& rhs) {
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                        rhs.end()));
  }

  friend bool operator<=(const vector& lhs, const vector& rhs) {
    return (!(rhs < lhs));
  }

  friend bool operator>(const vector& lhs, const vector& rhs) {
    return (rhs < lhs);
  }

  friend bool operator>=(const vector& lhs, const vector& rhs) {
    return (!(lhs < rhs));
  }
};

template <typename T, typename Alloc>
void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
  x.swap(y);
}

}  // namespace ft

#endif  // __VECTOR_H__