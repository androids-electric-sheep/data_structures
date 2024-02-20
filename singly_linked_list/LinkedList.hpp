/*

TODO

write copy constructor
write copy assignment operator

*/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <memory>

#include "Node.hpp"

template <typename T> class LinkedList {
private:
  Node<T> *head = nullptr;

public:
  LinkedList() { this->head = nullptr; }
  LinkedList(T val) { this->head = new Node<T>(val); }
  LinkedList(Node<T> *head) { this->head = head; }
  LinkedList(std::initializer_list<T> initial_list);
  LinkedList(LinkedList<T> &&l) {
    std::cout << "Move constructor for list" << std::endl;
    this->head = l.head;
    l.head = nullptr;
  }
  ~LinkedList();

  LinkedList<T> &operator=(LinkedList<T> &&l) {
    std::cout << "Move assignment operator" << std::endl;
    this->head = l.head;
    l.head = nullptr;
    return *this;
  }

  void walk() const;
  void add_element(T new_value);
  void remove_element(T value);
  Node<T> *find_element(T value);
};

template <typename T> LinkedList<T>::~LinkedList() {
  auto cur = this->head;
  while (cur != nullptr) {
    auto next = cur->next;
    delete cur;
    cur = next;
  }
}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> new_list) {
  for (const auto i : new_list) {
    this->add_element(i);
  }
}

template <typename T> void LinkedList<T>::walk() const {
  auto cur = this->head;
  while (cur != nullptr) {
    std::cout << cur->val << std::endl;
    cur = cur->next;
  }
}

template <typename T> void LinkedList<T>::add_element(T new_value) {
  if (this->head == nullptr) {
    this->head = new Node<T>(new_value);
    return;
  }

  auto cur = this->head;
  while (cur->next != nullptr) {
    cur = cur->next;
  }

  cur->next = new Node<T>(new_value);
}

template <typename T> void LinkedList<T>::remove_element(T value) {
  if (this->head == nullptr) {
    return;
  } else if (this->head->val == value) {
    Node<T> *tmp = this->head;
    this->head = this->head->next;
    delete tmp;
    return;
  }

  auto cur = head, next = cur->next;
  while (next != nullptr && next->val != value) {
    cur = next;
    next = next->next;
  }

  if (next != nullptr) {
    Node<T> *tmp = next;
    cur->next = next->next;
    delete tmp;
  }
}

template <typename T> Node<T> *LinkedList<T>::find_element(T value) {
  if (this->head == nullptr) {
    return nullptr;
  }

  auto cur = this->head;
  while (cur != nullptr && cur->val != value) {
    cur = cur->next;
  }

  return cur == nullptr ? nullptr : cur;
}

#endif
