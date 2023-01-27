/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:57:43 by yehyun            #+#    #+#             */
/*   Updated: 2023/01/19 15:48:35 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RBT_H__
#define __RBT_H__

#include "iterator.hpp"
#include "pair.hpp"

namespace ft {

template <typename Key, typename T>
struct Node {
  pair<Key, T> _data;
  Node* _parent;
  Node* _left;
  Node* _right;
  bool _color;

  Node() : _data(), _parent(NULL), _left(NULL), _right(NULL), _color(0) {}

  Node(Key key)
      : _data(key, T()), _parent(nil), _left(nil), _right(nil), _color(1) {}

  Node(pair<Key, T> data)
      : _data(data), _parent(nil), _left(nil), _right(nil), _color(1) {}

  static Node* nil;
};

template <typename Key, typename T>
Node<Key, T>* Node<Key, T>::nil =
    std::allocator<Node<Key, T> >().allocate(sizeof(Node<Key, T>));

template <typename Key, typename T, typename Compare, typename Alloc>
class RBT {
 protected:
  typedef ft::pair<Key, T> value_type;
  typedef enum { BLACK, RED } Color;
  typedef Node<Key, T> node_type;
  typedef typename Alloc::template rebind<node_type>::other Alnod;
  typedef node_type* node_ptr;

  node_ptr _root;
  node_ptr _front;
  node_ptr _back;
  Alnod _n_alloc;
  Compare _comp;

  RBT(const Compare& comp = Compare(), const Alnod& alloc = Alnod()) {
    _root = node_type::nil;
    _front = node_type::nil;
    _back = node_type::nil;
    _n_alloc = alloc;
    _comp = comp;
  }

  virtual ~RBT() {
    if (_root != node_type::nil)
      deallocTree(_root);
  }

  RBT(const RBT& rhs) { *this = rhs; }

  RBT& operator=(const RBT& rhs) {
    if (this == &rhs)
      return (*this);
    if (this->_root != node_type::nil)
      deallocTree(_root);
    if (rhs._root != node_type::nil) {
      this->_root = _n_alloc.allocate(sizeof(node_type));
      _n_alloc.construct(this->_root, node_type(rhs._root->_data));
      this->_root->_color = rhs._root->_color;
      copyTree(this->_root, rhs._root);
    }
    _n_alloc = rhs._n_alloc;
    _comp = rhs._comp;
    _front = minimum(this->_root);
    _back = maximum(this->_root);
    return (*this);
  }

  void deallocTree(node_ptr root) {
    if (root->_left != node_type::nil)
      deallocTree(root->_left);
    if (root->_right != node_type::nil)
      deallocTree(root->_right);
    _n_alloc.deallocate(root, sizeof(node_type));
  }

  void copyTree(node_ptr& lhs, const node_ptr& rhs) {
    if (rhs->_left != node_type::nil) {
      lhs->_left = this->_n_alloc.allocate(sizeof(node_type));
      lhs->_left->_data = rhs->_left->_data;
      lhs->_left->_color = rhs->_left->_color;
      lhs->_left->_parent = lhs;
      copyTree(lhs->_left, rhs->_left);
    } else {
      lhs->_left = node_type::nil;
    }
    if (rhs->_right != node_type::nil) {
      lhs->_right = this->_n_alloc.allocate(sizeof(node_type));
      lhs->_right->_data = rhs->_right->_data;
      lhs->_right->_color = rhs->_right->_color;
      lhs->_right->_parent = lhs;
      copyTree(lhs->_right, rhs->_right);
    } else {
      lhs->_right = node_type::nil;
    }
  }

  node_ptr successor(node_ptr node) const {
    node_ptr parent(node->_parent);

    if (node->_right != node_type::nil)
      return (minimum(node->_right));
    while (parent != node_type::nil && node == parent->_right) {
      node = parent;
      parent = parent->_parent;
    }
    return (parent);
  }

  node_ptr predecessor(node_ptr node) const {
    node_ptr parent(node->_parent);

    if (node->_left != node_type::nil)
      return (maximum(node->_left));
    while (parent != node_type::nil && node == parent->_left) {
      node = parent;
      parent = parent->_parent;
    }
    return (parent);
  }

  node_ptr insertNode(value_type data) {
    node_ptr newNode = _n_alloc.allocate(sizeof(node_type));
    _n_alloc.construct(newNode, node_type(data));
    insertHelper(newNode);
    if (newNode == _root) {
      _front = _root;
      _back = _root;
    } else {
      if (_comp(data.first, _front->_data.first))
        _front = newNode;
      if (_comp(_back->_data.first, data.first))
        _back = newNode;
    }
    return (newNode);
  }

  node_ptr insertNode(Key key) {
    node_ptr newNode = _n_alloc.allocate(sizeof(node_type));
    _n_alloc.construct(newNode, node_type(key));
    insertHelper(newNode);
    if (_root->_left == node_type::nil && _root->_right == node_type::nil) {
      _front = _root;
      _back = _root;
    } else {
      if (_comp(key, _front->_data.first))
        _front = newNode;
      if (_comp(_back->_data.first, key))
        _back = newNode;
    }
    return (newNode);
  }

  void insertHelper(node_ptr newNode) {
    node_ptr leafNode(node_type::nil);
    node_ptr tmpNode(this->_root);

    while (tmpNode != node_type::nil) {
      leafNode = tmpNode;
      if (_comp(newNode->_data.first, tmpNode->_data.first))
        tmpNode = tmpNode->_left;
      else
        tmpNode = tmpNode->_right;
    }
    newNode->_parent = leafNode;
    if (leafNode == node_type::nil)
      this->_root = newNode;
    else if (_comp(newNode->_data.first, leafNode->_data.first))
      leafNode->_left = newNode;
    else
      leafNode->_right = newNode;
    if (newNode->_parent == node_type::nil) {
      newNode->_color = BLACK;
      return;
    }
    if (newNode->_parent->_parent == node_type::nil)
      return;
    insertFix(newNode);
  }

  void insertFix(node_ptr node) {
    node_ptr uncle;

    while (node->_parent->_color == RED) {
      if (node->_parent == node->_parent->_parent->_right) {
        uncle = node->_parent->_parent->_left;
        if (uncle->_color == RED) {
          uncle->_color = BLACK;
          node->_parent->_color = BLACK;
          node->_parent->_parent->_color = RED;
          node = node->_parent->_parent;
        } else {
          if (node == node->_parent->_left) {
            node = node->_parent;
            rightRotate(node);
          }
          node->_parent->_color = BLACK;
          node->_parent->_parent->_color = RED;
          leftRotate(node->_parent->_parent);
        }
      } else {
        uncle = node->_parent->_parent->_right;
        if (uncle->_color == RED) {
          uncle->_color = BLACK;
          node->_parent->_color = BLACK;
          node->_parent->_parent->_color = RED;
          node = node->_parent->_parent;
        } else {
          if (node == node->_parent->_right) {
            node = node->_parent;
            leftRotate(node);
          }
          node->_parent->_color = BLACK;
          node->_parent->_parent->_color = RED;
          rightRotate(node->_parent->_parent);
        }
      }
      if (node == _root)
        break;
    }
    _root->_color = BLACK;
  }

  bool deleteNode(Key key) {
    node_ptr target = node_type::nil;
    node_ptr node = this->_root;

    while (node != node_type::nil) {
      if (node->_data.first == key) {
        target = node;
      }
      if (!_comp(key, node->_data.first)) {
        node = node->_right;
      } else {
        node = node->_left;
      }
    }
    if (target == node_type::nil)
      return (false);
    if (target == _front)
      _front = _front->_parent;
    if (target == _back)
      _back = _back->_parent;
    deleteNodeHelper(target);
    return (true);
  }

  void deleteNodeHelper(node_ptr target) {
    node_ptr childNode;
    node_ptr preNode = target;
    bool originalNodeColor = preNode->_color;

    if (target->_left == node_type::nil) {
      childNode = target->_right;
      changeNode(target, target->_right);
    } else if (target->_right == node_type::nil) {
      childNode = target->_left;
      changeNode(target, target->_left);
    } else {
      preNode = minimum(target->_right);
      originalNodeColor = preNode->_color;
      childNode = preNode->_right;
      if (preNode->_parent == target) {
        childNode->_parent = preNode;
      } else {
        changeNode(preNode, preNode->_right);
        preNode->_right = target->_right;
        preNode->_right->_parent = preNode;
      }
      changeNode(target, preNode);
      preNode->_left = target->_left;
      preNode->_left->_parent = preNode;
      preNode->_color = target->_color;
    }
    _n_alloc.deallocate(target, sizeof(node_type));
    if (originalNodeColor == BLACK)
      deleteFix(childNode);
  }

  void changeNode(node_ptr node1, node_ptr node2) {
    if (node1->_parent == node_type::nil)
      this->_root = node2;
    else if (node1 == node1->_parent->_left)
      node1->_parent->_left = node2;
    else
      node1->_parent->_right = node2;
    node2->_parent = node1->_parent;
  }

  void deleteFix(node_ptr node) {
    node_ptr sibling;

    while (node != _root && node->_color == BLACK) {
      if (node == node->_parent->_left) {
        sibling = node->_parent->_right;
        if (sibling->_color == RED) {
          sibling->_color = BLACK;
          node->_parent->_color = RED;
          leftRotate(node->_parent);
          sibling = node->_parent->_right;
        }
        if (sibling->_left->_color == BLACK &&
            sibling->_right->_color == BLACK) {
          sibling->_color = RED;
          node = node->_parent;
        } else {
          if (sibling->_right->_color == BLACK) {
            sibling->_left->_color = BLACK;
            sibling->_color = RED;
            rightRotate(sibling);
            sibling = node->_parent->_right;
          }
          sibling->_color = node->_parent->_color;
          node->_parent->_color = BLACK;
          sibling->_right->_color = BLACK;
          leftRotate(node->_parent);
          node = _root;
        }
      } else {
        sibling = node->_parent->_left;
        if (sibling->_color == RED) {
          sibling->_color = BLACK;
          node->_parent->_color = RED;
          rightRotate(node->_parent);
          sibling = node->_parent->_left;
        }
        if (sibling->_left->_color == BLACK &&
            sibling->_right->_color == BLACK) {
          sibling->_color = RED;
          node = node->_parent;
        } else {
          if (sibling->_left->_color == BLACK) {
            sibling->_right->_color = BLACK;
            sibling->_color = RED;
            leftRotate(sibling);
            sibling = node->_parent->_left;
          }
          sibling->_color = node->_parent->_color;
          node->_parent->_color = BLACK;
          sibling->_left->_color = BLACK;
          rightRotate(node->_parent);
          node = _root;
        }
      }
    }
    node->_color = BLACK;
  }

  node_ptr searchTree(Key key) const {
    return (searchTreeHelper(this->_root, key));
  }

  node_ptr searchTreeHelper(node_ptr node, Key key) const {
    if (node == node_type::nil || key == node->_data.first)
      return (node);
    else if (_comp(key, node->_data.first))
      return (searchTreeHelper(node->_left, key));
    else
      return (searchTreeHelper(node->_right, key));
  }

  node_ptr minimum(node_ptr node) const {
    while (node != node_type::nil && node->_left != node_type::nil)
      node = node->_left;
    return (node);
  }

  node_ptr maximum(node_ptr node) const {
    while (node != node_type::nil && node->_right != node_type::nil)
      node = node->_right;
    return (node);
  }

  void leftRotate(node_ptr node) {
    node_ptr rightChild(node->_right);

    node->_right = rightChild->_left;
    if (rightChild->_left != node_type::nil)
      rightChild->_left->_parent = node;
    rightChild->_parent = node->_parent;
    if (node->_parent == node_type::nil)
      this->_root = rightChild;
    else if (node == node->_parent->_left)
      node->_parent->_left = rightChild;
    else
      node->_parent->_right = rightChild;
    rightChild->_left = node;
    node->_parent = rightChild;
  }

  void rightRotate(node_ptr node) {
    node_ptr leftChild = node->_left;

    node->_left = leftChild->_right;
    if (leftChild->_right != node_type::nil)
      leftChild->_right->_parent = node;
    leftChild->_parent = node->_parent;
    if (node->_parent == node_type::nil)
      this->_root = leftChild;
    else if (node == node->_parent->_right)
      node->_parent->_right = leftChild;
    else
      node->_parent->_left = leftChild;
    leftChild->_right = node;
    node->_parent = leftChild;
  }

  class map_iterator {
   public:
    typedef node_ptr iterator_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;
    typedef typename RBT::value_type value_type;
    typedef value_type& reference;
    typedef value_type* pointer;

   private:
    iterator_type _ptr;
    const RBT* _tree;

   public:
    map_iterator() : _ptr(node_type::nil), _tree(NULL) {}

    map_iterator(const iterator_type rhs1, const RBT* rhs2)
        : _ptr(rhs1), _tree(rhs2) {}

    map_iterator(const map_iterator& rhs) { *this = rhs; }

    map_iterator& operator=(const map_iterator& rhs) {
      if (this == &rhs)
        return (*this);
      this->_ptr = rhs._ptr;
      this->_tree = rhs._tree;
      return (*this);
    }

    iterator_type base() const { return (_ptr); }
    const RBT* getTree() const { return (_tree); }

    bool operator==(const map_iterator& rhs) const {
      return (base() == rhs.base() && _tree == rhs._tree);
    }

    bool operator!=(const map_iterator& rhs) const {
      return (base() != rhs.base() || _tree != rhs._tree);
    }

    reference operator*() const { return (_ptr->_data); }

    pointer operator->() const { return (&operator*()); }

    map_iterator& operator++() {
      if (_ptr == node_type::nil) {
        _ptr = _tree->_front;
      } else
        _ptr = _tree->successor(_ptr);
      return (*this);
    }

    const map_iterator operator++(int) {
      const map_iterator tmp = *this;

      ++(*this);
      return (tmp);
    }

    map_iterator& operator--() {
      if (_ptr == node_type::nil) {
        _ptr = _tree->_back;
      } else
        _ptr = _tree->predecessor(_ptr);
      return (*this);
    }

    const map_iterator operator--(int) {
      const map_iterator tmp = *this;

      --(*this);
      return (tmp);
    }
  };

  class const_map_iterator {
   public:
    typedef node_ptr iterator_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;
    typedef typename RBT::value_type value_type;
    typedef const value_type& reference;
    typedef const value_type* pointer;

   private:
    iterator_type _ptr;
    const RBT* _tree;

   public:
    const_map_iterator() : _ptr(node_type::nil), _tree(NULL) {}

    const_map_iterator(const iterator_type rhs1, const RBT* rhs2)
        : _ptr(rhs1), _tree(rhs2) {}

    const_map_iterator(const map_iterator& rhs) {
      this->_ptr = rhs.base();
      this->_tree = rhs.getTree();
    }

    const_map_iterator(const const_map_iterator& rhs) { *this = rhs; }

    const_map_iterator& operator=(const const_map_iterator& rhs) {
      if (this == &rhs)
        return (*this);
      this->_ptr = rhs._ptr;
      this->_tree = rhs._tree;
      return (*this);
    }

    iterator_type base() const { return (_ptr); }

    bool operator==(const const_map_iterator& rhs) const {
      return (base() == rhs.base());
    }

    bool operator!=(const const_map_iterator& rhs) const {
      return (base() != rhs.base());
    }

    reference operator*() const { return (_ptr->_data); }

    pointer operator->() const { return (&operator*()); }

    const_map_iterator& operator++() {
      if (_ptr == node_type::nil) {
        _ptr = _tree->_front;
      } else
        _ptr = _tree->successor(_ptr);
      return (*this);
    }

    const const_map_iterator operator++(int) {
      const const_map_iterator tmp = *this;

      ++(*this);
      return (tmp);
    }

    const_map_iterator& operator--() {
      if (_ptr == node_type::nil) {
        _ptr = _tree->_back;
      } else
        _ptr = _tree->predecessor(_ptr);
      return (*this);
    }

    const const_map_iterator operator--(int) {
      const const_map_iterator tmp = *this;

      --(*this);
      return (tmp);
    }
  };

  class set_iterator {
   public:
    typedef node_ptr iterator_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;
    typedef Key value_type;
    typedef const value_type& reference;
    typedef const value_type* pointer;

   private:
    iterator_type _ptr;
    const RBT* _tree;

   public:
    set_iterator() : _ptr(node_type::nil), _tree(NULL) {}

    set_iterator(const iterator_type rhs1, const RBT* rhs2)
        : _ptr(rhs1), _tree(rhs2) {}

    set_iterator(const set_iterator& rhs) { *this = rhs; }

    set_iterator& operator=(const set_iterator& rhs) {
      if (this == &rhs)
        return (*this);
      this->_ptr = rhs._ptr;
      this->_tree = rhs._tree;
      return (*this);
    }

    iterator_type base() const { return (_ptr); }
    const RBT* getTree() const { return (_tree); }

    bool operator==(const set_iterator& rhs) const {
      return (base() == rhs.base());
    }

    bool operator!=(const set_iterator& rhs) const {
      return (base() != rhs.base());
    }

    reference operator*() const { return (_ptr->_data.first); }

    pointer operator->() const { return (&operator*()); }

    set_iterator& operator++() {
      if (_ptr == node_type::nil) {
        _ptr = _tree->_front;
      } else
        _ptr = _tree->successor(_ptr);
      return (*this);
    }

    const set_iterator operator++(int) {
      const set_iterator tmp = *this;

      ++(*this);
      return (tmp);
    }

    set_iterator& operator--() {
      if (_ptr == node_type::nil) {
        _ptr = _tree->_back;
      } else
        _ptr = _tree->predecessor(_ptr);
      return (*this);
    }

    const set_iterator operator--(int) {
      const set_iterator tmp = *this;

      --(*this);
      return (tmp);
    }
  };
};

}  // namespace ft

#endif  // __RBT_H__