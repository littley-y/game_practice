/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:48:08 by yehyun            #+#    #+#             */
/*   Updated: 2023/01/17 18:08:09 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PAIR_H__
#define __PAIR_H__

namespace ft {

template <typename T1, typename T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  T1 first;
  T2 second;

  pair() : first(T1()), second(T2()) {}

  pair(const first_type& a, const second_type& b) : first(a), second(b) {}

  template <typename U1, typename U2>
  pair(const pair<U1, U2>& pr) : first(pr.first), second(pr.second) {}

  pair& operator=(const pair& pr) {
    if (this != &pr) {
      this->first = pr.first;
      this->second = pr.second;
    }
    return (*this);
  }

  friend bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return (lhs.first == rhs.first && lhs.second == rhs.second);
  }

  friend bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return !(lhs == rhs);
  }

  friend bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return (lhs.first < rhs.first ||
            (lhs.first == rhs.first && lhs.second < rhs.second));
  }

  friend bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return !(rhs < lhs);
  }

  friend bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return (rhs < lhs);
  }

  friend bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return !(lhs < rhs);
  }
};

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
  return (pair<T1, T2>(x, y));
}

}  // namespace ft

#endif  // __PAIR_H__