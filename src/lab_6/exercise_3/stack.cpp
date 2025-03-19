#include "stack.hpp"

bool Stack::insert_beg(char elem) {
  Node *new_node = new Node;
  if (new_node == nullptr)
    return false;
  new_node->next = head;
  new_node->val = elem;
  head = new_node;
  return true;
}

void Stack::delete_beg(void) {
  Node *old_head = head;
  head = head->next;
  delete old_head;
}

void Stack::clear(void) {
  while (head != nullptr) {
    delete_beg();
  }
}

bool Stack::push(char elem) { return insert_beg(elem); }

unsigned *Stack::pop(void) {
  unsigned *to_del = new unsigned;
  if (head == nullptr)
    return nullptr;
  *to_del = head->val;
  delete_beg();
  return to_del;
}

unsigned *Stack::peek(void) { return head == nullptr ? nullptr : &(head->val); }
