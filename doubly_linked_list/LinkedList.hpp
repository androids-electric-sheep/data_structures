#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

#include "Node.hpp"

template <typename T> class LinkedList {
public:
  LinkedList(T val) { this->head = new Node<T>(val); }

  LinkedList(std::initializer_list<T> input_list) {
    for (const auto i : input_list) {
      this->add_element(i);
    }
  }

  ~LinkedList();

  void walk() const;
  void add_element(T new_value);
  void remove_element(T value);

private:
  Node<T> *head = nullptr;
};

template <typename T> LinkedList<T>::~LinkedList() {
  auto cur = this->head;
  while (cur != nullptr) {
    auto next = cur->next;
    delete cur;
    cur = next;
  }
}

template <typename T> void LinkedList<T>::walk() const {
  if (head == nullptr)
    return;

  auto cur = this->head;
  while (cur != nullptr) {
    std::cout << cur->val << std::endl;
    cur = cur->next;
  }
}

template <typename T> void LinkedList<T>::add_element(T new_value) {
  if (head == nullptr) {
    this->head = new Node<T>(new_value);
    return;
  }

  auto cur = this->head;
  while (cur->next != nullptr) {
    cur = cur->next;
  }

  cur->next = new Node<T>(new_value);
  cur->next->prev = cur;
}

template <typename T> void LinkedList<T>::remove_element(T element) {
  if (head == nullptr)
    return;

  auto cur = this->head;
  while (cur->val != element && cur != nullptr) {
    cur = cur->next;
  }

  if (cur == nullptr)
    return;

  cur->prev->next = cur->next;
  delete cur;
}

#endif
