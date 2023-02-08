#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <cstddef>
#include <iostream>

namespace ft {

template <typename Iterator>
struct iterator_traits {
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::iterator_category iterator_category;
};

template <typename T>
struct iterator_traits<T*> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef std::random_access_iterator_tag iterator_category;
};

template <typename T>
struct iterator_traits<const T*> {
  typedef ptrdiff_t difference_type;
  typedef T value_type;
  typedef const T* pointer;
  typedef const T& reference;
  typedef std::random_access_iterator_tag iterator_category;
};

template <typename Category,
          typename T,
          typename Distance = ptrdiff_t,
          typename Pointer = T*,
          typename Reference = T&>
struct iterator {
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;
};

template <typename Iter>
class reverse_iterator
    : public iterator<typename iterator_traits<Iter>::iterator_category,
                      typename iterator_traits<Iter>::value_type,
                      typename iterator_traits<Iter>::difference_type,
                      typename iterator_traits<Iter>::pointer,
                      typename iterator_traits<Iter>::reference> {
 private:
  Iter current;

 public:
  typedef Iter iterator_type;
  typedef typename iterator_traits<iterator_type>::iterator_category
      iterator_category;
  typedef typename iterator_traits<iterator_type>::value_type value_type;
  typedef
      typename iterator_traits<iterator_type>::difference_type difference_type;
  typedef typename iterator_traits<iterator_type>::reference reference;
  typedef typename iterator_traits<iterator_type>::pointer pointer;

  reverse_iterator() : current() {}
  explicit reverse_iterator(iterator_type it) : current(it) {}

  template <typename Iterator>
  reverse_iterator(const reverse_iterator<Iterator>& rev_it)
      : current(rev_it.base()) {}

  template <typename Iterator>
  reverse_iterator& operator=(const reverse_iterator<Iterator>& rev_it) {
    current = rev_it.base();
    return (*this);
  }

  iterator_type base() const { return (current); }

  reference operator*() const {
    Iter tmp = current;

    return (*--tmp);
  }

  pointer operator->() const { return &(operator*()); }

  reference operator[](difference_type n) const { return (*(*this + n)); }

  reverse_iterator operator+(difference_type n) const {
    return (reverse_iterator(current - n));
  }

  reverse_iterator& operator++() {
    --current;
    return (*this);
  }

  const reverse_iterator operator++(int) {
    const reverse_iterator tmp = *this;

    --current;
    return (tmp);
  }

  reverse_iterator& operator+=(difference_type n) {
    current -= n;
    return (*this);
  }

  reverse_iterator operator-(difference_type n) const {
    return (reverse_iterator(current + n));
  }

  reverse_iterator& operator--() {
    ++current;
    return (*this);
  }

  const reverse_iterator operator--(int) {
    const reverse_iterator tmp = *this;

    ++current;
    return (tmp);
  }

  reverse_iterator& operator-=(difference_type n) {
    current += n;
    return (*this);
  }

  template <typename Iterator1, typename Iterator2>
  friend typename reverse_iterator<Iterator1>::difference_type operator-(
      const reverse_iterator<Iterator1>& lhs,
      const reverse_iterator<Iterator2>& rhs) {
    return (rhs.base() - lhs.base());
  }

  template <typename Iterator>
  friend reverse_iterator<Iterator> operator+(
      typename reverse_iterator<Iterator>::difference_type n,
      const reverse_iterator<Iterator>& rev_it) {
    return (reverse_iterator<Iterator>(rev_it.base() - n));
  }

  template <typename Iterator>
  friend reverse_iterator<Iterator> operator-(
      typename reverse_iterator<Iterator>::difference_type n,
      const reverse_iterator<Iterator>& rev_it) {
    return (reverse_iterator<Iterator>(rev_it.base() + n));
  }

  template <typename Iter1, typename Iter2>
  friend bool operator==(const reverse_iterator<Iter1>& lhs,
                         const reverse_iterator<Iter2>& rhs) {
    return (lhs.base() == rhs.base());
  }

  template <typename Iter1, typename Iter2>
  friend bool operator!=(const reverse_iterator<Iter1>& lhs,
                         const reverse_iterator<Iter2>& rhs) {
    return (lhs.base() != rhs.base());
  }

  template <typename Iter1, typename Iter2>
  friend bool operator<(const reverse_iterator<Iter1>& lhs,
                        const reverse_iterator<Iter2>& rhs) {
    return (lhs.base() > rhs.base());
  }
  template <typename Iter1, typename Iter2>
  friend bool operator<=(const reverse_iterator<Iter1>& lhs,
                         const reverse_iterator<Iter2>& rhs) {
    return (lhs.base() >= rhs.base());
  }

  template <typename Iter1, typename Iter2>
  friend bool operator>(const reverse_iterator<Iter1>& lhs,
                        const reverse_iterator<Iter2>& rhs) {
    return (lhs.base() < rhs.base());
  }

  template <typename Iter1, typename Iter2>
  friend bool operator>=(const reverse_iterator<Iter1>& lhs,
                         const reverse_iterator<Iter2>& rhs) {
    return (lhs.base() <= rhs.base());
  }
};

}  // namespace ft

#endif  // __ITERATOR_H__