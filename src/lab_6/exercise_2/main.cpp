/*
* Implement a Stack (of char's) using a singly linked list
*/

#include <iostream>

using namespace std;


// Union Result type for handling function return values, in order to reduce number of variables in namespace
union Result {
    char *character;
    bool boolean;
};


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

void menu(Stack *);

int main(void) {
    Stack *stack = new Stack();

    while (true)
        menu(stack);
}


void menu(Stack *stack) {
    cout
        << "1. Push" << endl
        << "2. Pop" << endl
        << "3. Peek" << endl
        << "0. Exit" << endl
        << "Enter choice: ";
    
    unsigned choice;
    char elem;
    union Result result;
    cin >> choice;

    switch (choice) {
    case 0:
        stack->clear();
        exit(0);
    
    case 1:
        cout << "Enter element to push: ";
        cin >> elem;
        result.boolean = stack->push(elem);
        if (!result.boolean)
            cout << "Push failed; Insufficient space in stack!" << endl;
        break;
    
    case 2:
        result.character = stack->pop();
        if (result.character != nullptr)
            cout << "Popped element: " << *result.character << endl;
        else
            cout << "Cannot pop from empty stack!" << endl;
        break;
    case 3:
        result.character = stack->peek();
        if (result.character != nullptr)
            cout << "Top element: " << *result.character << endl;
        else
            cout << "Cannot peek empty stack!" << endl;
        break;

    default:
        cout << "Invalid input! please try again" << endl;
    }


    cout << endl << endl;
}


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


bool Stack::push(char elem) { 
    return insert_beg(elem);
}

char *Stack::pop(void) {
    char *to_del = new char;
    if (head == nullptr)
        return nullptr;
    *to_del = head->val;
    delete_beg();
    return to_del;
}

char *Stack::peek(void) {
    return head == nullptr ? nullptr : &(head->val);
}