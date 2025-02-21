/*
  Implement a List ADT using a dynamically sized doubly linked list
  Implement the following methods
  1. Insertion
    - Beginning
    - End
    - Position
  2. Deletion
    - Beginning
    - End
    - Position
  3. Search
  4. Display
  5. Reverse the List in place
*/

#include <iostream>

using namespace std;

// Union Result type for handling function return values, in order to reduce
// number of variables in namespace
union Result {
  int integer;
  bool boolean;
};

class ListNode {
private:
  int val;
  ListNode *next;
  ListNode *prev;

public:
  // Constructor function
  ListNode(int elem) : val(elem), next(nullptr), prev(nullptr) {}

  // Getter functions
  int get_val(void) { return this->val; }
  ListNode *get_next(void) { return this->next; }
  ListNode *get_prev(void) { return this->prev; }

  // Setter functions
  void set_val(int val) { this->val = val; }
  void set_next(ListNode *next) { this->next = next; }
  void set_prev(ListNode *prev) { this->prev = prev; }
};

class List {
private:
  ListNode *head;
  ListNode *tail;
  unsigned len;

public:
  List() : head(nullptr), tail(nullptr), len(0) {}
  bool insert_beginning(int);
  bool insert_at(int, unsigned);
  bool insert_end(int);
  bool delete_beginning(void);
  bool delete_at(unsigned);
  bool delete_end(void);
  long search(int);
  void display(void);
  void clear(ListNode *);
};

void menu(List *);

int main(void) {
  List list = List();
  while (true)
    menu(&list);
}

// Menu function that takes in a pointer to a list for modification
void menu(List *list) {
  cout << "1. Insert at the beginning" << endl
       << "2. Insert at the end" << endl
       << "3. Insert at a given index" << endl
       << "4. Delete at the beginning" << endl
       << "5. Delete at the end" << endl
       << "6. Delete at a given index" << endl
       << "7. Search for an element" << endl
       << "8. Display the list" << endl
       << "0. Exit" << endl
       << "Enter choice: ";

  // variables required for calling member functions of list ADT
  unsigned int choice, index;
  int elem;
  union Result result;
  cin >> choice;

  // goto statments used for avoiding retyping the same code again and again
  // 1. handle_boolean_return - For handling boolean return values of member
  // functions of list ADT
  // 2. _return - For printing extra newlines before returning
  switch (choice) {
  case 0:
    list->clear(nullptr);
    exit(0);

  case 1:
    cout << "Enter element to insert: ";
    cin >> elem;
    result.boolean = list->insert_beginning(elem);
    goto handle_boolean_return;

  case 2:
    cout << "Enter element to insert: ";
    cin >> elem;
    result.boolean = list->insert_end(elem);
    goto handle_boolean_return;

  case 3:
    cout << "Enter element to insert: ";
    cin >> elem;
    cout << "Enter index to insert element at: ";
    cin >> index;
    result.boolean = list->insert_at(elem, index);
    goto handle_boolean_return;

  case 4:
    result.boolean = list->delete_beginning();
    goto handle_boolean_return;

  case 5:
    result.boolean = list->delete_end();
    goto handle_boolean_return;

  case 6:
    cout << "Enter index to delete element at: ";
    cin >> index;
    result.boolean = list->delete_at(index);
    goto handle_boolean_return;

  case 7:
    cout << "Enter element to search for: ";
    cin >> elem;
    result.integer = list->search(elem);
    if (result.integer == -1)
      cout << "Unable to locate element in list!" << endl;
    else
      cout << "Element found at index " << result.integer << endl;
    goto _return;

  case 8:
    list->display();
    goto _return;

  default:
    cout << "Invalid input! please try again" << endl;
  }

handle_boolean_return:
  if (!result.boolean)
    cout << "Operation failed!" << endl;

_return:
  cout << endl << endl;
  return;
}

bool List::insert_beginning(int elem) {
  ListNode *new_elem = new ListNode(elem);
  if (new_elem == nullptr)
    return false;
  new_elem->set_next(this->head);
  if (this->head == nullptr)
    this->tail = new_elem;
  else
    this->head->set_prev(new_elem);
  this->head = new_elem;
  this->len++;

  return true;
}

bool List::insert_at(int elem, unsigned index) {
  if (index == 0)
    return this->insert_beginning(elem);
  else if (index == this->len)
    return this->insert_end(elem);
  else if (index > this->len)
    return false;

  ListNode *new_elem = new ListNode(elem);
  if (new_elem == nullptr)
    return false;

  ListNode *iter_elem = this->head;
  unsigned i = 0;

  while (++i < index)
    iter_elem = iter_elem->get_next();

  new_elem->set_next(iter_elem->get_next());
  new_elem->set_prev(iter_elem);
  iter_elem->get_next()->set_prev(new_elem);
  iter_elem->set_next(new_elem);

  this->len++;
  return true;
}

bool List::insert_end(int elem) {
  if (this->len == 0)
    return this->insert_beginning(elem);
  ListNode *new_elem = new ListNode(elem);
  if (new_elem == nullptr)
    return false;

  this->tail->set_next(new_elem);
  new_elem->set_prev(this->tail);

  this->tail = new_elem;
  this->len++;

  return true;
}

bool List::delete_beginning(void) {
  if (this->head == nullptr)
    return false;
  ListNode *new_head = this->head->get_next();

  if (new_head != nullptr)
    new_head->set_prev(nullptr);
  else
    this->tail = nullptr;

  delete this->head;
  this->head = new_head;
  this->len--;

  return true;
}

bool List::delete_at(unsigned index) {
  if (index == 0)
    return this->delete_beginning();
  else if (index == this->len - 1)
    return this->delete_end();
  else if (index >= this->len)
    return false;

  ListNode *to_delete = this->head;
  unsigned i = 0;
  while (++i <= index) {
    to_delete = to_delete->get_next();
  }

  to_delete->get_prev()->set_next(to_delete->get_next());
  to_delete->get_next()->set_prev(to_delete->get_prev());

  delete to_delete;
  this->len--;

  return true;
}

bool List::delete_end(void) {
  if (this->len == 1)
    return this->delete_beginning();

  this->tail = this->tail->get_prev();

  delete this->tail->get_next();
  this->len--;

  this->tail->set_next(nullptr);

  return true;
}

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

void List::display(void) {
  cout << "HEAD -> ";
  ListNode *iter_elem = this->head;
  for (unsigned i = 0; i < this->len; i++) {
    cout << iter_elem->get_val() << " -> ";
    iter_elem = iter_elem->get_next();
  }
  cout << "TAIL <- ";
  iter_elem = this->tail;
  for (unsigned i = 0; i < this->len; i++) {
    cout << iter_elem->get_val() << " <- ";
    iter_elem = iter_elem->get_prev();
  }
  cout << "HEAD" << endl;
}

void List::clear(ListNode *head) {
  while (this->len > 0) {
    this->delete_end();
  }
}
