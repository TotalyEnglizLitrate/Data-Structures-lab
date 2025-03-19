/*
 * Write a menu driven program to do the following using an SLL stack
 * 1. Get infix expression
 * 2. Convert infix to postfix
 * 3. Evaluvate postfix expression
 * 4. Exit
 */

#include "stack.hpp"
#include <iostream>

using namespace std;

struct Op {
  char symbol;
  unsigned precedence;
};

static Op assign = {'=', 0}, add = {'+', 1}, sub = {'-', 1}, mul = {'*', 2},
          divide = {'/', 2}, mod = {'%', 2};
static Op *operators[] = {&assign, &add, &sub, &mul, &divide, &mod};
static unsigned op_len = 6;

void menu(Stack *);
bool validate_infix(string *);
bool is_op(char);
string to_postfix(string *);
Op *get_op(char);
unsigned *eval_postfix(string *);

int main(void) {
  Stack *stack = new Stack();
  while (true)
    menu(stack);
}

void menu(Stack *stack) {
  unsigned choice;
  string infix_expr, postfix_expr;
  unsigned *result;

  while (true) {
    cout << "1. Enter infix expression" << endl
         << "2. Convert infix to postfix" << endl
         << "3. Evaluate postfix expression" << endl
         << "0. Exit" << endl
         << "Enter choice: ";
    cin >> choice;
    cin.ignore(); // ignore the newline character

    switch (choice) {
    case 0:
      exit(0);
    case 1:
      cout << "Enter infix expression: ";
      getline(cin, infix_expr);
      if (!validate_infix(&infix_expr)) {
        cout << "Not a valid infix expression!" << endl;
      } else {
        cout << "Infix expression accepted." << endl;
      }
      break;
    case 2:
      if (infix_expr.empty()) {
        cout << "No infix expression entered yet!" << endl;
      } else {
        postfix_expr = to_postfix(&infix_expr);
        cout << "Postfix expression: " << postfix_expr << endl;
      }
      break;
    case 3:
      if (postfix_expr.empty()) {
        cout << "No postfix expression available!" << endl;
      } else {
        result = eval_postfix(&postfix_expr);
        if (result != nullptr) {
          cout << "Result: " << *result << endl;
          delete result;
        } else {
          cout << "Error evaluating postfix expression." << endl;
        }
      }
      break;
    default:
      cout << "Invalid choice!" << endl;
    }
    cout << endl << endl;
  }
}

bool validate_infix(string *infix_expr) {
  bool is_operator = true;
  char i_char;
  bool is_assignment = false;
  unsigned assignment_end_index = 0;

  if (infix_expr->length() >= 2) {
    unsigned i = 0;
    while (i < infix_expr->length() && infix_expr->at(i) == ' ') {
      i++;
    }
    if (i < infix_expr->length() &&
        ((65 <= infix_expr->at(i) && infix_expr->at(i) <= 90) ||
         (97 <= infix_expr->at(i) && infix_expr->at(i) <= 122))) {
      i++;
      while (i < infix_expr->length() && infix_expr->at(i) == ' ') {
        i++;
      }
      if (i < infix_expr->length() && infix_expr->at(i) == '=') {
        is_assignment = true;
        assignment_end_index = i + 1;
        is_operator = true;
      }
    }
  }

  for (unsigned i = assignment_end_index; i < infix_expr->length(); i++) {
    i_char = infix_expr->at(i);
    if (i_char == ' ')
      continue;

    if (is_operator) {
      if (is_op(i_char))
        return false;
      else
        is_operator = false;
    } else {
      if (!(48 <= i_char && i_char <= 57)) {
        if (!is_op(i_char))
          return false;
        else
          is_operator = true;
      } else {
        continue;
      }
    }
  }
  return !is_operator;
}

bool is_op(char c) {
  for (unsigned i = 0; i < op_len; i++) {
    if (c == operators[i]->symbol)
      return true;
  }
  return false;
}

string to_postfix(string *infix_expr) {
  string postfix_expr;
  Stack ops = Stack();
  char i_char;
  for (unsigned i = 0; i < infix_expr->length(); i++) {
    i_char = infix_expr->at(i);
    if (is_op(i_char)) {
      Op *i_op = get_op(i_char);

      while (true) {
        if (ops.peek() == nullptr) {
          ops.push(i_char);
          break;
        } else {
          Op *stack_operator = get_op(*ops.peek());
          if (stack_operator->precedence >= i_op->precedence) {
            postfix_expr.push_back(stack_operator->symbol);
            postfix_expr.push_back(' ');
            ops.pop();
          } else {
            ops.push(i_op->symbol);
            break;
          }
        }
      }
    } else {
      postfix_expr.push_back(i_char);
    }
  }

  char *c;
  while ((c = (char *)ops.pop()) != nullptr)
    postfix_expr.push_back(*c);

  return postfix_expr;
}

Op *get_op(char c) {
  for (unsigned i = 0; i < op_len; i++) {
    if (c == operators[i]->symbol)
      return operators[i];
  }
  return nullptr;
}

unsigned *eval_postfix(string *postfix_expr) {
  Stack num_stack = Stack();
  unsigned operand1, operand2;
  unsigned *result = new unsigned(0);
  unsigned num = 0;
  bool building_number = false;
  char c;
  for (unsigned i = 0; i < postfix_expr->length(); i++) {
    c = postfix_expr->at(i);

    if (48 <= c && c <= 57) {
      num = num * 10 + (c - '0');
      building_number = true;
    } else if (c == ' ') {
      if (building_number) {
        num_stack.push(num);
        num = 0;
        building_number = false;
      }
    } else if (is_op(c)) {
      if (building_number) {
        num_stack.push(num);
        num = 0;
        building_number = false;
      }

      if (num_stack.peek() == nullptr) {
        return nullptr;
      }
      operand2 = *num_stack.pop();
      if (num_stack.peek() == nullptr) {
        return nullptr;
      }
      operand1 = *num_stack.pop();
      switch (c) {
      case '+':
        *result = operand1 + operand2;
        break;
      case '-':
        *result = operand1 - operand2;
        break;
      case '*':
        *result = operand1 * operand2;
        break;
      case '/':
        if (operand2 == 0) {
          cout << "Division by zero" << endl;
          return nullptr;
        }
        *result = operand1 / operand2;
        break;
      case '%':
        if (operand2 == 0) {
          cout << "Modulo by zero" << endl;
          delete result;
          return nullptr;
        }
        *result = operand1 % operand2;
        break;
      default:
        delete result;
        return nullptr;
      }
      num_stack.push(*result);
      cout << *result << endl;
    }
  }

  if (building_number) {
    num_stack.push(num);
    num = 0;
    building_number = false;
  }

  if (num_stack.peek() == nullptr) {
    delete result;
    return nullptr;
  }
  *result = *num_stack.pop();
  if (num_stack.peek() != nullptr) {
    delete result;
    return nullptr;
  }
  return result;
}
