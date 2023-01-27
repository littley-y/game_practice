/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:36:04 by yehyun            #+#    #+#             */
/*   Updated: 2023/01/27 13:08:44 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SET_H__
#define __SET_H__

#include <memory>
#include "rbt.hpp"
#include "utils.hpp"
namespace ft {

template <typename Key,
          typename Compare = std::less<Key>,
          typename Alloc = std::allocator<Key> >
class set : public RBT<Key, Key, Compare, Alloc> {
 private:
  typedef RBT<Key, Key, Compare, Alloc> tree_type;
  typedef typename tree_type::node_type node_type;
  typedef typename tree_type::node_ptr node_ptr;
  size_t _size;

 public:
  typedef Key key_type;
  typedef Key value_type;
  typedef Compare key_compare;
  typedef Compare value_compare;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef typename Alloc::template rebind<value_type>::other allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename tree_type::set_iterator iterator;
  typedef iterator const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  explicit set(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type())
      : tree_type(comp, alloc), _size(0) {}

  template <typename InputIterator>
  set(InputIterator first,
      InputIterator last,
      const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type())
      : tree_type(comp, alloc), _size(0) {
    for (InputIterator it = first; it != last; ++it) {
      if (tree_type::searchTree(*it) == node_type::nil) {
        tree_type::insertNode(*it);
        ++_size;
      }
    }
  }

  set(const set& rhs) { *this = rhs; }

  set& operator=(const set& rhs) {
    if (this == &rhs)
      return (*this);
    tree_type::operator=(rhs);
    this->_size = rhs._size;
    return (*this);
  }

  ~set() {}

  iterator begin() { return (iterator(this->_front, this)); }
  const_iterator begin() const { return (const_iterator(this->_front, this)); }

  iterator end() { return (iterator(node_type::nil, this)); }
  const_iterator end() const { return (const_iterator(node_type::nil, this)); }

  reverse_iterator rbegin() { return (reverse_iterator(end())); }
  const reverse_iterator rbegin() const {
    return (const_reverse_iterator(end()));
  }
  reverse_iterator rend() { return (reverse_iterator(begin())); }
  const reverse_iterator rend() const {
    return (const_reverse_iterator(begin()));
  }

  void clear() {
    erase(begin(), end());
    this->_size = 0;
  }

  size_type count(const value_type& val) const {
    if (tree_type::searchTree(val) == node_type::nil)
      return (0);
    else
      return (1);
  }

  bool empty() const { return (this->_size == 0); }
  size_type size() const { return (this->_size); }
  size_type max_size() const { return (this->_n_alloc.max_size()); }

  void swap(set& x) {
    node_ptr tmpRoot = this->_root;
    node_ptr tmpFront = this->_front;
    node_ptr tmpBack = this->_back;
    size_type tmpSize = this->_size;

    this->_root = x._root;
    this->_front = x._front;
    this->_back = x._back;
    this->_size = x._size;

    x._root = tmpRoot;
    x._front = tmpFront;
    x._back = tmpBack;
    x._size = tmpSize;
  }

  pair<iterator, iterator> equal_range(const value_type& k) const {
    return (ft::make_pair(lower_bound(k), upper_bound(k)));
  }

  void erase(iterator position) {
    tree_type::deleteNode(*position);
    --_size;
  }

  size_type erase(const value_type& val) {
    if (tree_type::deleteNode(val)) {
      --_size;
      return (1);
    } else {
      return (0);
    }
  }

  void erase(iterator first, iterator last) {
    value_type tmpKey;

    while (first != last) {
      tmpKey = *first;
      ++first;
      tree_type::deleteNode(tmpKey);
      --_size;
    }
  }

  iterator find(const value_type& val) const {
    return (iterator(tree_type::searchTree(val), this));
  }

  allocator_type get_allocator() const { return (this->_n_alloc); }

  pair<iterator, bool> insert(const value_type& val) {
    node_ptr target = tree_type::searchTree(val);

    if (target != node_type::nil) {
      return (ft::make_pair(iterator(target, this), false));
    } else {
      ++_size;
      return (ft::make_pair(iterator(tree_type::insertNode(val), this), true));
    }
  }

  iterator insert(iterator position, const value_type& val) {
    iterator target(tree_type::searchTree(val), this);

    (void)position;
    if (target.base() != node_type::nil) {
      return (target);
    } else {
      ++_size;
      return (iterator(tree_type::insertNode(val), this));
    }
  }

  template <typename InputIterator>
  void insert(InputIterator first, InputIterator last) {
    for (InputIterator it = first; it != last; ++it) {
      if (tree_type::searchTree(*it) == node_type::nil) {
        tree_type::insertNode(*it);
        ++_size;
      }
    }
  }

  iterator lower_bound(const value_type& val) {
    node_ptr tmp(tree_type::_root);
    node_ptr result(node_type::nil);

    while (tmp != node_type::nil) {
      if (!tree_type::_comp(tmp->_data.first, val)) {
        result = tmp;
        tmp = tmp->_left;
      } else {
        tmp = tmp->_right;
      }
    }
    return (iterator(result, this));
  }

  const_iterator lower_bound(const value_type& val) const {
    node_ptr tmp(tree_type::_root);
    node_ptr result(node_type::nil);

    while (tmp != node_type::nil) {
      if (!tree_type::_comp(tmp->_data.first, val)) {
        result = tmp;
        tmp = tmp->_left;
      } else {
        tmp = tmp->_right;
      }
    }
    return (iterator(result, this));
  }

  iterator upper_bound(const value_type& val) {
    node_ptr tmp(tree_type::_root);
    node_ptr result(node_type::nil);

    while (tmp != node_type::nil) {
      if (tree_type::_comp(val, tmp->_data.first)) {
        result = tmp;
        tmp = tmp->_left;
      } else {
        tmp = tmp->_right;
      }
    }
    return (iterator(result, this));
  }

  const_iterator upper_bound(const value_type& val) const {
    node_ptr tmp(tree_type::_root);
    node_ptr result(node_type::nil);

    while (tmp != node_type::nil) {
      if (tree_type::_comp(val, tmp->_data.first)) {
        result = tmp;
        tmp = tmp->_left;
      } else {
        tmp = tmp->_right;
      }
    }
    return (iterator(result, this));
  }

  key_compare key_comp() const { return (tree_type::_comp); }

  value_compare value_comp() const { return (tree_type::_comp); }

  friend bool operator==(const set& lhs, const set& rhs) {
    if (lhs._size != rhs._size)
      return (false);
    return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
  }

  friend bool operator!=(const set& lhs, const set& rhs) {
    return (!(lhs == rhs));
  }

  friend bool operator<(const set& lhs, const set& rhs) {
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                        rhs.end()));
  }

  friend bool operator<=(const set& lhs, const set& rhs) {
    return (!(rhs < lhs));
  }

  friend bool operator>(const set& lhs, const set& rhs) { return (rhs < lhs); }

  friend bool operator>=(const set& lhs, const set& rhs) {
    return (!(lhs < rhs));
  }
};

template <class Key, class Compare, class Alloc>
void swap(set<Key, Compare, Alloc>& lhs, set<Key, Compare, Alloc>& rhs) {
  lhs.swap(rhs);
}

}  // namespace ft

#endif  // __SET_H__