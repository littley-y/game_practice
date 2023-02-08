#ifndef __STACK_H__
#define __STACK_H__

#include "vector.hpp"

namespace ft {
template <typename T, typename Container = vector<T> >
class stack {
 protected:
  Container c;

 public:
  typedef Container container_type;
  typedef typename container_type::value_type value_type;
  typedef typename container_type::reference reference;
  typedef typename container_type::const_reference const_reference;
  typedef typename container_type::size_type size_type;

  explicit stack(const container_type& container = container_type()) {
    c = container;
  }

  stack(const stack& rhs) { *this = rhs; }

  stack& operator=(const stack& rhs) {
    if (this == &rhs)
      return (*this);
    c = rhs.c;
    return (*this);
  }

  bool empty() const { return (c.empty()); }
  size_type size() const { return (c.size()); }

  void pop() { c.pop_back(); }
  void push(const value_type& val) { c.push_back(val); }

  value_type& top() { return (c.back()); }
  const value_type& top() const { return (c.back()); }

  friend bool operator==(const stack& lhs, const stack& rhs) {
    return (lhs.c == rhs.c);
  }
  friend bool operator!=(const stack& lhs, const stack& rhs) {
    return (lhs.c != rhs.c);
  }
  friend bool operator<(const stack& lhs, const stack& rhs) {
    return (lhs.c < rhs.c);
  }
  friend bool operator<=(const stack& lhs, const stack& rhs) {
    return (lhs.c <= rhs.c);
  }
  friend bool operator>(const stack& lhs, const stack& rhs) {
    return (lhs.c > rhs.c);
  }
  friend bool operator>=(const stack& lhs, const stack& rhs) {
    return (lhs.c >= rhs.c);
  }
};

}  // namespace ft

#endif  // __STACK_H__