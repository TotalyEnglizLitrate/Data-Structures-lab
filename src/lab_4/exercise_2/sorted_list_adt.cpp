/*
  Implementation of a Sorted List ADT using a dynamically sized singly linked
  list The list maintains elements in ascending order during insertion
  Implements the following operations:
  1. Insert (maintains sorted order)
  2. Merge (combines two sorted lists)
  3. Display
  4. Clear
*/

#include "sorted_list_adt.hpp"

#include <iostream>

using namespace std;

// Constructor for ListNode that initializes value and sets next to nullptr
ListNode::ListNode(int elem) : val(elem), next(nullptr) {}

// Getter for node's value
int ListNode::get_val(void) { return this->val; }

// Getter for next pointer
ListNode *ListNode::get_next(void) { return this->next; }

// Setter for node's value
void ListNode::set_val(int val) { this->val = val; }

// Setter for next pointer
void ListNode::set_next(ListNode *next) { this->next = next; }

// Constructor for List that creates an empty list
List::List() : head(nullptr), len(0) {}

// Destructor that ensures all memory is freed
List::~List() { this->clear(); }

// Getter for head pointer
ListNode *List::get_head(void) { return this->head; }

// Delete the last element of the list
bool List::delete_beginning(void) {
  if (this->len == 0)
    return false; // list is empty, cannot delete

  if (this->len == 1) {
    delete this->head;
    this->head = nullptr;
    this->len--;
    return true;
  }

  ListNode *tmp = this->head;
  this->head = this->head->get_next();
  delete tmp;
  this->len--;

  return true;
}

// Insert an element while maintaining sorted order
void List::insert(int elem) {
  ListNode *new_node = new ListNode(elem);

  // Handle empty list case
  if (this->head == nullptr) {
    this->head = new_node;
    this->len++;
    return;
  }

  // Handle insertion at beginning if new element is smallest
  if (this->head->get_val() > elem) {
    new_node->set_next(this->head);
    this->head = new_node;
    this->len++;
    return;
  }

  // Find insertion point that maintains sorted order
  ListNode *i = this->head;
  while (i->get_next() != nullptr && i->get_next()->get_val() < elem)
    i = i->get_next();

  // Insert new node at position
  new_node->set_next(i->get_next());
  i->set_next(new_node);
  this->len++;
  return;
}

// Merge two sorted lists into a new sorted list
List *List::merge(List *other) {
  List *merged = new List();
  ListNode *self_node = this->head, *other_node = other->head;

  // Compare and insert elements from both lists
  while (other_node != nullptr && self_node != nullptr) {
    if (self_node->get_val() <= other_node->get_val()) {
      merged->insert(self_node->get_val());
      self_node = self_node->get_next();
    } else {
      merged->insert(other_node->get_val());
      other_node = other_node->get_next();
    }
  }

  // Handle remaining elements in either list because we stop iteration
  // when we have reached the end of the of the lists in the above while loop
  while (other_node != nullptr) {
    merged->insert(other_node->get_val());
    other_node = other_node->get_next();
  }
  while (self_node != nullptr) {
    merged->insert(self_node->get_val());
    self_node = self_node->get_next();
  }

  return merged;
}

// Display the list contents in format: HEAD -> elem1 -> elem2 -> ... -> NULL
void List::display(void) {
  cout << "HEAD -> ";
  ListNode *iter_elem = this->head;
  for (unsigned i = 0; i < this->len; i++, iter_elem = iter_elem->get_next())
    cout << iter_elem->get_val() << " -> ";
  cout << "NULL" << endl;
}

// Clear all elements from the list
void List::clear(void) {
  while (this->delete_beginning())
    ;
}
