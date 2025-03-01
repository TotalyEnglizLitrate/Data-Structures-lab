/*
 * Implement a Stack (of unsigned int's) using a singly linked list
 */

class Stack {
private:
  struct Node {
    unsigned val;
    Node *next;
  };
  unsigned len;
  Node *head;
  bool insert_beg(char);
  void delete_beg(void);

public:
  Stack(void) : len(0), head(nullptr) {}
  bool push(char);
  unsigned *pop(void);
  unsigned *peek(void);
  void clear(void);
};
