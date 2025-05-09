/*
 * @file main.cpp
 * @brief Implements the menu for lab 7 exercise 4
 * @details Write a program that takes in a given string and removes a
 * character immediately to the left whenever a `+` is encountered
 */

#include <iostream>

#include "stack_sll.hpp"

using namespace std;

/*
 * @brief Function to process input string as follows,
 * takes in a given string and removes a character immediately to the left
 * whenever a `+` is encountered
 * @param str input string to process
 * @param success Boolean pointer to set to true/false to indicate
 * success/failure
 * @return processed string
 */
const string process_str(const string &str, bool *success);

int main(void) {
  string in_str, out_str;
  short unsigned choice;
  bool result;
  while (true) {
    cout << "1. Enter string" << endl << "2. Exit" << endl << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter string to process: ";
      cin >> in_str;
      out_str = process_str(in_str, &result);
      if (!result)
        cout << "Invalid string/other error while processing string" << endl;
      else
        for (auto c : string(out_str.rbegin(), out_str.rend()))
          cout << c;
      cout << endl;
      break;

    case 2:
      return 0;

    default:
      cout << "Invalid Choice!" << endl;
    }

    cout << endl << endl;
  }
}

const string process_str(const string &str, bool *success) {
  *success = true;
  Stack stack;
  bool result;
  for (auto c : str) {
    if (c == '+')
      stack.pop(&result);
    else
      stack.push(c, &result);

    if (!result) {
      *success = false;
      return "";
    }
  }

  string ret_str;
  char c;
  while (true) {
    c = stack.pop(&result);
    if (result)
      ret_str.push_back(c);
    else
      break;
  }

  return ret_str;
}
