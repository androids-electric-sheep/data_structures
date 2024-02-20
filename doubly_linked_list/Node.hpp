#ifndef NODE_HPP
#define NODE_HPP

template <typename T> struct Node {
public:
  Node(T val) : val(val) {}
  T val;
  Node<T> *prev = nullptr;
  Node<T> *next = nullptr;
};

#endif
