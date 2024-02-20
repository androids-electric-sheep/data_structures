#ifndef NODE_HPP
#define NODE_HPP

#include <memory>

template <typename T> class LinkedList;

template <typename T> struct Node {
  friend class LinkedList<T>;
  Node() = default;
  Node(T val) : val(val), next(nullptr) {}
  Node(T val, Node *next) : val(val), next(next) {}

  Node(Node<T> &&n) {
    std::cout << "Move constructor" << std::endl;
    this->val = n.val;
    this->next = n.next;
    n.next = nullptr;
    n.val = T();
  }

  Node &operator=(Node<T> &&n) {
    std::cout << "Move assignment operator" << std::endl;
    this->next = n.next;
    this->val = n.val;
    n.next = nullptr;
    n.val = T();
  }

  T val;
  Node<T> *next;
};

#endif
