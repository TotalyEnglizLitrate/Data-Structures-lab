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

// Union Result type for handling function return values, in order to reduce number of variables in namespace
union Result {
    int integer;
    bool boolean;
};

class ListNode {
    private:
      int val;
      ListNode *next;
    public:
      ListNode(int elem): val(elem), next(NULL) {}
      int get_val(void) {
        return this->val;
      }
      ListNode *get_next(void) {
        return this->next;
      }
      void set_val(int val) {
        this->val = val;
      }
      void set_next(ListNode *next) {
        this->next = next;
      }
};



class List {
    private:
        ListNode *head;
        ListNode *tail;
    public:
        unsigned int len;
        List(): head(NULL), tail(NULL), len(0) {}
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
    cout
        << "1. Insert at the beginning" << endl
        << "2. Insert at the end" << endl
        << "3. Insert at a given index" << endl
        << "4. Delete at the beginning" << endl
        << "5. Delete at the end"<< endl
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
    // 1. handle_boolean_return - For handling boolean return values of member functions of list ADT
    // 2. _return - For printing extra newlines before returning
    switch (choice) {
    case 0:
      list->clear(NULL);
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
      cout << "DEBUG:" << endl
        << list->len << endl;
      list->display();
      return;
}


bool List::insert_beginning(int elem) {
    ListNode *new_elem = (ListNode *)malloc(sizeof(ListNode));
    if (new_elem == NULL)
      return false;
    *new_elem = ListNode(elem);
    new_elem->set_next(this->head);
    if (this->head == NULL)
      this->tail = new_elem;
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

  ListNode *new_elem = (ListNode *)malloc(sizeof(ListNode));
  if (new_elem == NULL)
    return false;
  *new_elem = ListNode(elem);
  ListNode *iter_elem = this->head;
  unsigned i;
  
  for (i = 1; i < index; i++, iter_elem = iter_elem->get_next())
    ;
  
  new_elem->set_next(iter_elem->get_next());
  iter_elem->set_next(new_elem);

  this->len++;
  return true;
}


bool List::insert_end(int elem) {
  ListNode *new_elem = (ListNode *)malloc(sizeof(ListNode));
  if (new_elem == NULL)
    return false;
  *new_elem = ListNode(elem);

  this->tail->set_next(new_elem);
  this->tail = new_elem;
  this->len++;

  return true;
}


bool List::delete_beginning(void) {
  if (this->head == NULL)
    return false;
  ListNode *new_head = this->head->get_next();

  free(this->head);
  this->head = new_head;
  this->len--;

  if (this->len == 0)
    this->tail = NULL;

  return true;
}


bool List::delete_at(unsigned index) {
  if (index == 0)
    return this->delete_beginning();
  else if (index >= this->len)
    return false;

  ListNode *iter_elem = this->head;
  unsigned i;
  
  for (i = 0; i < index; i++, iter_elem = iter_elem->get_next())
    ;

  iter_elem->set_next(iter_elem->get_next()->get_next());
  free(iter_elem->get_next());
  this->len--;

  if (index == this->len - 1)
    this->tail = iter_elem;

  return true;
}


bool List::delete_end(void) {
  return this->len == 0 ? false : delete_at(this->len - 1);
}


long List::search(int target) {
  ListNode *iter_elem = this->head;
  for (unsigned int i = 0; i < this->len; i++, iter_elem = iter_elem->get_next())
    if (iter_elem->get_val() == target)
      return i;

  return -1;
}


void List::display(void) {
  cout << "HEAD -> ";
  ListNode *iter_elem = this->head;
  for (unsigned i = 0; i < this->len; i++, iter_elem = iter_elem->get_next())
    cout << iter_elem->get_val() << " -> ";
  cout << "NULL" << endl;
}


void List::display_rev(ListNode *elem=NULL) {
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


void List::reverse(void) {
  if (this->len <= 1)
    return;
  ListNode *start, *pre_start, *post_start, *end, *pre_end, *post_end;
  start = this->head;
  end = this->tail;
  pre_start = post_end = NULL;
  post_start = start->get_next();
  pre_end = this->get_index(this->len - 2);

  for (unsigned int i = 0; i < this->len / 2;  i++) {
    if (pre_start != NULL)
      pre_start->set_next(end);

    pre_end->set_next(start);
    end->set_next(post_start);
    start->set_next(post_end);

    pre_start = start;
    start = post_start;
    post_start = post_start->get_next();

    post_end = end;
    end = pre_end;
    pre_end = this->get_index(this->len - 1 - i);
  }
}


ListNode *List::get_index(unsigned index) {
  if (index >= this->len)
    return NULL;
  ListNode *iter_elem = this->head;
  for (unsigned i = 0; i <= index; i++, iter_elem = iter_elem->get_next())
    ;

  return iter_elem;
}


void List::clear(ListNode *head) {
  while (this->len > 0) {
    this->delete_end();
  }
}