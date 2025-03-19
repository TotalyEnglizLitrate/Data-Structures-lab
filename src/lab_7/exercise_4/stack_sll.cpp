/*
 * @file stack_sll.cpp
 * @brief Implement a stack ADT using a singly linked list
 * @details The stack must implement the following operations
 * i) Push
 * ii) Pop
 */

#include "stack_sll.hpp"

bool Stack::is_empty(void) { return top == nullptr; }

void Stack::push(char elem, bool *success) {
  *success = true;
  Node *new_node = new Node{elem, top};
  if (new_node == nullptr)
    *success = false;
  else
    top = new_node;
}

char Stack::pop(bool *success) {
  if (!(*success = !is_empty()))
    return 0;

  int to_ret = top->val;
  Node *to_del = top;
  top = top->next;
  delete to_del;

  return to_ret;
} 