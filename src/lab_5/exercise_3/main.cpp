#include "cll_adt.hpp"
#include <iostream>

#define PROC_TIME 5

using namespace std;

void menu(List *);

int main(void) {
  List *sched_queue = new List();
  while (true)
    menu(sched_queue);
}

// Menu function that takes in a pointer to a list for modification
void menu(List *list) {
  cout << "1. Add process to queue" << endl
       << "2. Execute" << endl
       << "0. Exit" << endl
       << "Enter choice: ";

  // variables required for calling member functions of list ADT
  unsigned int choice, time;
  bool result;
  cin >> choice;

  // goto statments used for avoiding retyping the same code again and again
  // 1. handle_boolean_return - For handling boolean return values of member
  // functions of list ADT
  // 2. _return - For printing extra newlines before returning
  switch (choice) {
  case 0:
    list->clear();
    exit(0);

  case 1:
    cout << "Enter amount of time that the process will take to execute: ";
    cin >> time;
    result = list->insert_end((int)time);
    if (!result)
      cout << "Operation failed!" << endl;
    break;

  case 2: {
    if (list->get_index(0) == nullptr) {
      cout << "No processes in queue!" << endl;
      break;
    }

    time = list->get_index(0)->get_val();
    result = list->delete_beginning();
    cout << "Remaining time for process: ";
    if (result) {
      if (PROC_TIME < time) {
        result = list->insert_end(((int)time) - PROC_TIME);
        cout << ((int)time) - PROC_TIME << endl;
      } else {
        cout << 0 << endl;
      }
    } else {
      cout << "Operation failed!" << endl;
    }
    break;
  }

  default:
    cout << "Invalid input! please try again" << endl;
  }

  cout << endl << endl;
  return;
}
