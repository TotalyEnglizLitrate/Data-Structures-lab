/*
  Header file for a Sorted List ADT using a dynamically sized singly linked list
  Implements the following methods:
  1. Insert (maintains sorted order)
  2. Merge (combines two sorted lists)
  3. Display
  4. Clear
*/

#define NULL nullptr

class ListNode {
private:
  int val;        // Value stored in the node
  ListNode *next; // Pointer to the next node

public:
  ListNode(int);
  int get_val(void);
  ListNode *get_next(void);
  void set_val(int);
  void set_next(ListNode *);
};

class List {
private:
  ListNode *head;
  unsigned len;
  ListNode *get_head(void);    // Returns the head pointer
  bool delete_beginning(void); // Helper function to delete the first element

public:
  List();
  ~List();
  void insert(int);
  List *merge(List *);
  void display(void);
  void clear(void);
};
