/*
  Main program that provides a menu-driven interface to work with sorted lists
  Implements the following operations:
  1. Insert elements into list 1
  2. Insert elements into list 2
  3. Merge lists 1 and 2 into list 3
  4. Display all lists
  5. Exit and cleanup
*/

#include "sorted_list_adt.hpp"

#include <iostream>

using namespace std;

void menu(List *[]);

int main(void) {
  // Create two empty lists and a nullptr for the merged list
  List *l1 = new List(), *l2 = new List(), *l3 = nullptr;
  List *lists[] = {l1, l2, l3};
  while (true)
    menu(lists);
}

// Menu function that handles user interaction and list operations
void menu(List *lists[]) {
  unsigned char choice;
  int elem;
  
  // Display menu options
  cout << "1. Insert into list 1" << endl
       << "2. Insert into list 2" << endl
       << "3. Merge list 1 and 2 into list 3" << endl
       << "4. Display" << endl
       << "0. Exit" << endl
       << "Enter your choice: ";
  cin >> choice;

  // Get element input if needed
  if (choice == 1 || choice == 2) {
    cout << "Enter element: ";
    cin >> elem;
  }

  // Handle user choice
  switch (choice) {
  case 0:
    for (int i = 0; i < 3; i++)
      delete lists[i];

  case 1:
    lists[0]->insert(elem);
    break;

  case 2:
    lists[1]->insert(elem);
    break;

  case 3:
    if (lists[2] != nullptr)
      delete lists[2];
    lists[2] = lists[0]->merge(lists[1]);
    break;

  case 4:
    cout << "List no. 1: ";
    lists[0]->display();
    cout << "List no. 2: ";
    lists[1]->display();

    if (lists[2] != nullptr) {
      cout << "List no. 3: ";
      lists[2]->display();
    }
    break;

  default:
    cout << "Invalid choice! Try again" << endl;
  }

  cout << endl << endl;
  return;
}
