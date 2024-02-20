#include <cassert>
#include <iostream>

#include "LinkedList.hpp"

LinkedList<int> list_builder() { return LinkedList<int>({1, 2, 3}); }

int main() {
  LinkedList<int> list(10);
  list.add_element(20);
  list.walk();

  LinkedList<int> new_list({1, 2, 3, 4, 5});
  new_list.remove_element(3);
  new_list.walk();

  LinkedList<int> x({4, 5, 6});
  x = list_builder();
  x.walk();

  LinkedList<int> y{std::move(list_builder())};
  y.walk();

  auto spot = new_list.find_element(5);
  assert(spot != nullptr && spot->val == 5);
}
