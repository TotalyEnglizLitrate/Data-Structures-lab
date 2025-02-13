/*
  Implement a List ADT using a dynamically sized singly linked list
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
    - normal
    - reversed
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

public:
  ListNode(int elem) : val(elem), next(NULL) {}
  int get_val(void) { return this->val; }
  ListNode *get_next(void) { return this->next; }
  void set_val(int val) { this->val = val; }
  void set_next(ListNode *next) { this->next = next; }
};

class List {
private:
  ListNode *head;
  unsigned int len;

public:
  List() : head(NULL), len(0) {}
  bool insert_beginning(int);
  bool insert_at(int, unsigned);
  bool insert_end(int);
  bool delete_beginning(void);
  bool delete_at(unsigned);
  bool delete_end(void);
  long search(int);
  void display(void);
  void display_rev(ListNode *);
  void reverse(void);
  ListNode *get_index(unsigned);
  void clear(void);
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
       << "9. Display the list in reverse" << endl
       << "10. Reverse the list in place" << endl
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
    list->clear(); // Clear the list before exiting.
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

  case 9:
    list->display_rev(NULL);
    goto _return;
  case 10:
    list->reverse();
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

// Function that inserts an element at the beginning of the linked list
bool List::insert_beginning(int elem) {
  ListNode *new_elem = new ListNode(elem);
  new_elem->set_next(this->head);
  this->head = new_elem;
  this->len++;

  return true;
}

// Function that inserts at any given position of the linked list
bool List::insert_at(int elem, unsigned index) {
  if (index == 0)
    return this->insert_beginning(
        elem); // defer to List::insert_beginning for insertion at index 0
  else if (index > this->len)
    return false; // return false to indicate out of bounds failure

  ListNode *new_elem = new ListNode(elem);
  ListNode *iter_elem = this->get_index(index - 1);

  new_elem->set_next(iter_elem->get_next());
  iter_elem->set_next(new_elem);

  this->len++;
  return true;
}

// Special case of insert_at with index = length of list
bool List::insert_end(int elem) { return this->insert_at(elem, this->len); }

// Function to delete the first node of a linked list
bool List::delete_beginning(void) {
  if (this->len == 0)
    return false; // Cannot delete from an empty list
  ListNode *new_head = this->head->get_next();

  delete this->head;
  this->head = new_head;
  this->len--;

  return true;
}

// Function to delete element at a given index
bool List::delete_at(unsigned index) {
  if (index == 0)
    return this->delete_beginning(); // defer to List::delete_beginning to
                                     // delete the first index.
  else if (index >= this->len)
    return false; // return false to indicate out of bounds failure

  ListNode *iter_elem = this->get_index(index - 1);

  // The next node should be deleted and the current node modified accordingly
  ListNode *to_delete = iter_elem->get_next();
  iter_elem->set_next(to_delete->get_next());
  delete to_delete;
  this->len--;

  return true;
}

// Special case of List::delete_at with index = length - 1
bool List::delete_end(void) { return delete_at(this->len - 1); }

// Search through the list for a target element, return index if found; else
// return -1
long List::search(int target) {
  ListNode *iter_elem = this->head;
  for (unsigned int i = 0; i < this->len;
       i++, iter_elem = iter_elem->get_next())
    if (iter_elem->get_val() == target)
      return i;

  return -1;
}

// Display the elements of linked list like so,
// HEAD -> elem1 -> elem2 ..... -> elemn -> NULL
void List::display(void) {
  cout << "HEAD -> ";
  ListNode *iter_elem = this->head;
  for (unsigned i = 0; i < this->len; i++, iter_elem = iter_elem->get_next())
    cout << iter_elem->get_val() << " -> ";
  cout << "NULL" << endl;
}

// Display the elements of linked list in reverse like so,
// NULL <- elemn ...... elem2 <- elem1 <- HEAD
void List::display_rev(ListNode *elem = NULL) {
  if (elem == NULL) {
    elem = this->head;
    this->display_rev(elem);
    cout << "HEAD" << endl;
    return;
  }
  if (elem->get_next() != NULL) {
    this->display_rev(elem->get_next());
    cout << elem->get_val() << " <- ";
    return;
  }
  cout << "NULL <- " << elem->get_val() << " <- ";
  return;
}

// Reverse the list in place by swapping the extreme nodes outside in
void List::reverse(void) {
  if (this->len <= 1)
    return; // No need to reverse list with 0 or 1 elements

  ListNode *start, *pre_start, *post_start, *end, *pre_end, *post_end;
  // start and end are the extreme nodes that need to be swapped
  // pre_{start,end} are the nodes before the start and end nodes respectively
  // post_{start,end} are the nodes after the start and end nodes respectively
  // required to mark the proper next for the previous node and swapped node
  start = this->head;
  end = this->get_index(this->len - 1);
  pre_start = post_end = NULL;
  post_start = start->get_next();
  pre_end = this->get_index(this->len - 2);

  for (unsigned int i = 0; i < this->len / 2; i++) {
    // if pre_start is a non-null element i.e we are not at the start of the
    // list, point pre_start to the right extreme node to be swapped with
    if (pre_start != NULL)
      pre_start->set_next(end);

    // Similarly update the next pointers of other nodes involved in the swap
    pre_end->set_next(start);
    end->set_next(post_start);
    start->set_next(post_end);

    // Move the pointers inward to prepare for the next swap:
    pre_start = start;
    start = post_start;
    post_start = post_start->get_next();
    post_end = end;
    end = pre_end;
    pre_end = this->get_index(this->len - 1 - i);
  }
}

// Gets the node at a given index
ListNode *List::get_index(unsigned index) {
  if (index >= this->len)
    return NULL; // out of bounds
  ListNode *iter_elem = this->head;
  for (unsigned i = 0; i <= index; i++, iter_elem = iter_elem->get_next())
    ;

  return iter_elem;
}

// clears the entire list by deleting the last element until length = 0
void List::clear() {
  while (this->len > 0)
    this->delete_end();
}
