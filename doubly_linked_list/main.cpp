#include <cassert>
#include <iostream>

#include "LinkedList.hpp"

int main() {
  LinkedList<int> x{10};
  x.walk();

  LinkedList<int> y{1, 2, 3, 4, 5};
  y.remove_element(3);
  y.walk();
  return 0;
}
