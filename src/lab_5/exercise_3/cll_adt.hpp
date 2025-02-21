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
  // Constructor function
  ListNode(int elem) : val(elem), next(nullptr) {}

  // Getter functions
  int get_val(void) { return this->val; }
  ListNode *get_next(void) { return this->next; }

  // Setter functions
  void set_val(int val) { this->val = val; }
  void set_next(ListNode *next) { this->next = next; }
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
  ListNode *get_index(unsigned);
  void display(void);
  void clear();
};
