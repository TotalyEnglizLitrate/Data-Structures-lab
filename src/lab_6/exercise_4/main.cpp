/*
 * Menu driven program to check if a given string of '(' and ')' parens are
 * balanced.
 */

#include <iostream>
#include <string>

using namespace std;

class BalancedParenCounter {
private:
  unsigned opening_parens, closing_parens;
  bool reverse;

public:
  enum Paren { opening, closing };
  BalancedParenCounter(void) : BalancedParenCounter(false) {};
  BalancedParenCounter(bool reverse)
      : opening_parens(0), closing_parens(0), reverse(reverse) {};
  bool add_paren(enum Paren);
  bool is_eq(void);
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
  // Set start, stop, step based on if we're iterating forwards or backwards
  // (see: `BalancedParenCounter->reverse`)
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
  // if res is false at any point, this breaks out of the for loop and returns
  // false
  // if res is true till the end, check if the amount of opening_parens
  // and closing_parens are the same
  return res && counter->is_eq();
}

// Function to add a parenthesis to the counter and check if the balance is
// maintained
bool BalancedParenCounter::add_paren(enum Paren paren) {
  if (paren == opening)
    opening_parens++;
  else
    closing_parens++;

  // Check if the balance is maintained depending on whether we're traversing it
  // forwards or backwards
  return reverse ? closing_parens >= opening_parens
                 : opening_parens >= closing_parens;
}

// Function to check if the number of opening and closing parentheses are equal
bool BalancedParenCounter::is_eq(void) {
  return opening_parens == closing_parens;
}
