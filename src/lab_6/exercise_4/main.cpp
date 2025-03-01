/*
 * Menu driven program to check if a given string of '(' and ')' parens are
 * balanced.
 */

#include <iostream>
#include <string>

using namespace std;

class BalancedParenCounter {
private:
  unsigned counter;
  bool reverse;

public:
  enum Paren { opening, closing };
  BalancedParenCounter(void) : BalancedParenCounter(false) {};
  BalancedParenCounter(bool reverse) : counter(0), reverse(reverse) {};
  bool add_paren(enum Paren);
  bool is_rev(void) { return reverse; }
};

void menu(void);
bool is_balanced(string *, BalancedParenCounter *);

int main(void) {
  while (true)
    menu();

  return 0;
}

void menu(void) {
  unsigned choice;
  string input_parens;
  BalancedParenCounter counter = BalancedParenCounter();

  cout << "1. Check parentheses" << endl
       << "0. Exit" << endl
       << "Enter choice: ";

  cin >> choice;
  cin.ignore(); // ignore the newline character

  switch (choice) {
  case 0:
    exit(0);
  case 1:
    cout << "Enter parentheses: ";
    getline(cin, input_parens);
    cout << "The input parentheses are "
         << (is_balanced(&input_parens, &counter) ? "" : "un") << "balanced"
         << endl;
    break;
  default:
    cout << "Invalid Choice!" << endl;
  }

  cout << endl << endl;
}

// Function to check if a string of parentheses is balanced
bool is_balanced(string *parens, BalancedParenCounter *counter) {
  bool res = true;

  unsigned start = counter->is_rev() ? parens->length() - 1 : 0;
  unsigned end = counter->is_rev() ? 0 : parens->length();
  unsigned step = counter->is_rev() ? -1 : 1;

  for (unsigned i = start; i != end && res; i += step) {
    if (parens->at(i) == '(')
      res = counter->add_paren(BalancedParenCounter::opening);
    else if (parens->at(i) == ')')
      res = counter->add_paren(BalancedParenCounter::closing);
    else
      res = false;
  }

  return res;
}

// Function to add a parenthesis to the counter and check if the balance is
// maintained
bool BalancedParenCounter::add_paren(enum Paren paren) {
  enum Paren check_paren = reverse ? closing : opening;

  if (paren == check_paren) {
    counter++;
  } else if (counter == 0) {
    return false;
  } else {
    counter--;
  }

  return true;
}
