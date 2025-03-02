#include "cll_adt.hpp"

#include <iostream>

using namespace std;

// Function that inserts an element at the beginning of the circular linked list
bool List::insert_beginning(int elem) {
  ListNode *new_elem = new ListNode(elem);
  if (new_elem == nullptr)
    return false;
  new_elem->set_next(this->head);
  if (this->head == nullptr)
    this->tail = new_elem;

  this->head = new_elem;
  this->tail->set_next(new_elem);
  this->len++;

  return true;
}

// Function that inserts an element at a given index in the circular linked
// list
bool List::insert_at(int elem, unsigned index) {
  if (index == 0)
    return this->insert_beginning(elem); // defer to insert_beginning if index
                                         // is 0
  if (index == this->len)
    return this->insert_end(elem); // defer to insert_end if index is equal to
                                   // length

  ListNode *new_elem = new ListNode(elem);
  if (new_elem == nullptr)
    return false;

  ListNode *iter_elem = this->head;
  unsigned i = 0;

  while (++i < index)
    iter_elem = iter_elem->get_next();

  new_elem->set_next(iter_elem->get_next());
  iter_elem->set_next(new_elem);

  this->len++;
  return true;
}

// Function that inserts an element at the end of the circular linked list
bool List::insert_end(int elem) {
  if (this->len == 0)
    return this->insert_beginning(elem);
  ListNode *new_elem = new ListNode(elem);
  if (new_elem == nullptr)
    return false;

  this->tail->set_next(new_elem);
  new_elem->set_next(this->head);
  this->tail = new_elem;
  this->len++;

  return true;
}

// Function to delete the first node of the circular linked list
bool List::delete_beginning(void) {
  if (this->head == nullptr)
    return false;

  ListNode *temp = this->head;
  if (this->len == 1) {
    this->head = this->tail = nullptr;
  } else {
    this->head = this->head->get_next();
    this->tail->set_next(head);
  }
  delete temp;
  len--;
  return true;
}

// Function to delete an element at a given index in the circular linked list
bool List::delete_at(unsigned index) {
  if (index == 0)
    return this->delete_beginning();
  else if (index == this->len - 1)
    return this->delete_end();
  else if (index >= this->len)
    return false;

  ListNode *iter_elem = this->get_index(index - 1);
  ListNode *to_delete = iter_elem->get_next();
  iter_elem->set_next(to_delete->get_next());
  delete to_delete;
  this->len--;

  return true;
}

// Function to delete the last node of the circular linked list
bool List::delete_end(void) {
  if (this->len <= 1)
    return this->delete_beginning();

  this->tail = this->get_index(this->len - 2);

  delete this->tail->get_next();
  this->len--;

  this->tail->set_next(this->head);

  return true;
}

// Function to search for a target element in the circular linked list
long List::search(int target) {
  ListNode *iter_elem = this->head;
  unsigned i = 0;
  while (i < this->len) {
    if (iter_elem->get_val() == target)
      return (long)i;
    i++;
    iter_elem = iter_elem->get_next();
  }

  return -1;
}

// Function to display the elements of the circular linked list
void List::display(void) {
  cout << "HEAD -> ";
  ListNode *iter_elem = this->head;
  for (unsigned i = 0; i < this->len; i++) {
    cout << iter_elem->get_val() << " -> ";
    iter_elem = iter_elem->get_next();
  }
  cout << "HEAD";
}

// Helper function to get the node at a given index
ListNode *List::get_index(unsigned index) {
  if (index >= this->len || this->head == nullptr) {
    return nullptr;
  }
  ListNode *iter_elem = this->head;
  for (unsigned i = 0; i < index; i++) {
    iter_elem = iter_elem->get_next();
  }
  return iter_elem;
}

// Function to clear all nodes from the circular linked list
void List::clear(void) {
  while (this->len > 0) {
    this->delete_beginning();
  }
}
