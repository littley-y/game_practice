/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:51:46 by yehyun            #+#    #+#             */
/*   Updated: 2023/01/24 13:51:46 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>
#if 0  // CREATE A REAL STL EXAMPLE
#include <map>
#include <set>
#include <stack>
#include <vector>
namespace ft = std;
#else
#include "map.hpp"
#include "set.hpp"
#include "stack.hpp"
#include "vector.hpp"
#endif

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer {
  int idx;
  char buff[BUFFER_SIZE];

  Buffer() {}
  Buffer(int i) {
    idx = i;
    for (size_t i = 0; i != 10; ++i)
      buff[i] = rand() % 26 + 'a';
  }

  const std::string getBuff() const {
    std::string str;

    for (size_t i = 0; i != 10; i++)
      str += buff[i];
    return (str);
  }
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template <typename T>
class MutantStack : public ft::stack<T> {
 public:
  MutantStack() {}
  MutantStack(const MutantStack<T>& src) { *this = src; }
  MutantStack<T>& operator=(const MutantStack<T>& rhs) {
    this->c = rhs.c;
    return *this;
  }
  ~MutantStack() {}

  typedef typename ft::stack<T>::container_type::iterator iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
};

void vector_test() {
  ft::vector<std::string> vector_str;
  ft::vector<int> vector_int;
  ft::vector<Buffer> vector_buffer;

  for (int i = 0; i < COUNT; i++)
    vector_buffer.push_back(Buffer(i));
  std::cout << vector_buffer.at(10).getBuff();
  std::cout << std::endl;

  ft::vector<Buffer>().swap(vector_buffer);
  ft::vector<Buffer>().clear();
  try {
    for (int i = 0; i < COUNT; i++) {
      const int idx = rand();
      vector_buffer.at(idx);
      std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" << std::endl;
    }
  } catch (const std::exception& e) {
  }

  ft::vector<int>::iterator it;
  ft::vector<int>::const_iterator ite;
  it = vector_int.begin();
  ite = vector_int.begin();
  if (it != ite)
    std::cerr << "Error: two vector is different\n";
}

void map_test() {
  unsigned long sum = 0;
  ft::map<int, int> map_int, copy;
  ft::map<int, int>::iterator it;

  for (int i = 0; i < COUNT; ++i)
    map_int.insert(ft::make_pair(rand(), rand()));
  it = map_int.begin();
  for (int i = 0; i < 10; ++i) {
    sum += it->second;
    ++it;
  }
  std::cout << "should be constant with the same seed: " << sum << std::endl;

  copy = map_int;
  if (copy != map_int)
    std::cout << "copy failed!\n";
  map_int.clear();
  std::cout << "copy size : " << copy.size() << "\n";

  map_int.max_size();
}

void stack_test() {
  MutantStack<char>::iterator it;
  MutantStack<char> iterable_stack;

  for (char letter = 33; letter <= 126; letter++)
    iterable_stack.push(letter);
  it = iterable_stack.begin();
  for (; it != iterable_stack.end(); ++it)
    std::cout << *it;
  std::cout << std::endl;

  ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
  for (int i = 0; i < COUNT; i++)
    stack_deq_buffer.push(Buffer(i));
  for (int i = 0; i != 5; i++) {
    std::cout << stack_deq_buffer.top().getBuff();
    stack_deq_buffer.pop();
  }
  std::cout << std::endl;
}

void set_test() {
  unsigned long sum = 0;
  ft::set<int> set_int, copy;
  ft::set<int>::iterator it;

  for (int i = 0; i < COUNT; ++i)
    set_int.insert(rand());
  it = set_int.begin();
  for (int i = 0; i < 10; ++i) {
    sum += *it;
    ++it;
  }
  std::cout << "should be constant with the same seed: " << sum << std::endl;

  copy = set_int;
  if (copy != set_int)
    std::cout << "copy failed!\n";
  set_int.clear();
  std::cout << "copy size : " << copy.size() << "\n";
}

void leak_check() {
  system("leaks $PPID | grep leaked");
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./test seed" << std::endl;
    std::cerr << "Provide a seed please" << std::endl;
    std::cerr << "Count value:" << COUNT << std::endl;
    return (1);
  }
  atexit(leak_check);
  srand(atoi(argv[1]));
  std::cout << "--------------- vector test ---------------\n";
  vector_test();
  std::cout << "--------------- map_test ---------------\n";
  map_test();
  std::cout << "--------------- stack_test ---------------\n";
  stack_test();
  std::cout << "--------------- set_test ---------------\n";
  set_test();
  return (0);
}
