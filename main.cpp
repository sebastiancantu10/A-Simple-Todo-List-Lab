#include <iostream>
#include "src/hello.hpp"
using namespace std;

int main() {
  TodoList list;

  list.add("Buy protein powder");
  list.add("Buy season pass");
  list.add("Clean bathroom");
  list.add("Study course layout");

  list.completeTask("Buy season pass");

  cout << "ALL TASKS:\n" << list.all() << endl;
  cout << "COMPLETED:\n" << list.complete() << endl;
  cout << "INCOMPLETE:\n" << list.incomplete() << endl;

  list.clear();

  cout << "CLEARED LIST:\n" << list.all() << endl;

  return 0;
}