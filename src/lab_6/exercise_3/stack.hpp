/*
* Implement a Stack (of char's) using a singly linked list
*/

#include <iostream>

using namespace std;


class Stack {
private:
    struct Node {
        char val;
        Node *next;
    };
    unsigned len;
    Node *head;
    bool insert_beg(char);
    void delete_beg(void);
    
public:
    Stack(void): len(0), head(nullptr) {}
    bool push(char);
    char *pop(void);
    char *peek(void);
    void clear(void);
};

