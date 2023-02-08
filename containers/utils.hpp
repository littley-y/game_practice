#ifndef __UTILS_H__
#define __UTILS_H__

namespace ft {

template <bool B, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
  typedef T value;
};

template <typename T, T v>
struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef integral_constant<T, v> type;
  operator const T() { return v; }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template <typename _Tp>
struct is_integral : public false_type {};

template <>
struct is_integral<bool> : public true_type {};

template <>
struct is_integral<char> : public true_type {};

template <>
struct is_integral<signed char> : public true_type {};

template <>
struct is_integral<unsigned char> : public true_type {};

template <>
struct is_integral<wchar_t> : public true_type {};

template <>
struct is_integral<short> : public true_type {};

template <>
struct is_integral<unsigned short> : public true_type {};

template <>
struct is_integral<int> : public true_type {};

template <>
struct is_integral<unsigned int> : public true_type {};

template <>
struct is_integral<long> : public true_type {};

template <>
struct is_integral<unsigned long> : public true_type {};

template <>
struct is_integral<long long> : public true_type {};

template <>
struct is_integral<unsigned long long> : public true_type {};

// ft::equal
template <typename Iter1, typename Iter2>
bool equal(Iter1 first1, Iter1 last1, Iter2 first2) {
  while (first1 != last1) {
    if (*first1 != *first2)
      return (false);
    ++first1;
    ++first2;
  }
  return (true);
}

template <typename Iter1, typename Iter2, typename BinaryPredicate>
bool equal(Iter1 first1, Iter1 last1, Iter2 first2, BinaryPredicate pred) {
  while (first1 != last1) {
    if (!pred(*first1, *first2))
      return (false);
    ++first1;
    ++first2;
  }
  return (true);
}

template <typename Iter1, typename Iter2>
bool lexicographical_compare(Iter1 first1,
                             Iter1 last1,
                             Iter2 first2,
                             Iter2 last2) {
  while (first1 != last1) {
    if (first2 == last2 || *first2 < *first1)
      return (false);
    else if (*first1 < *first2)
      return (true);
    ++first1;
    ++first2;
  }
  return (first2 != last2);
}

template <typename Iter1, typename Iter2, typename Compare>
bool lexicographical_compare(Iter1 first1,
                             Iter1 last1,
                             Iter2 first2,
                             Iter2 last2,
                             Compare comp) {
  while (first1 != last1) {
    if (first2 == last2 || comp(first2, first1))
      return (false);
    else if (comp(first1, first2))
      return (true);
    ++first1;
    ++first2;
  }
  return (first2 != last2);
}

};  // namespace ft

#endif  // __UTILS_H__