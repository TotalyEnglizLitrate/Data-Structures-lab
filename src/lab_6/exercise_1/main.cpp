/*
* Implement a Stack (of char's) using a fixed length array of size 5
*/

#include <iostream>

#define LENGTH 5

using namespace std;


// Union Result type for handling function return values, in order to reduce number of variables in namespace
union Result {
    char *character;
    bool boolean;
};


class Stack {
private:
    char arr[LENGTH];
    int top;
public:
    Stack(void): top(-1) {}
    bool push(char);
    char *pop(void);
    char *peek(void);
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


bool Stack::push(char elem) {
    if (top == LENGTH - 1)
        return false;
    
    arr[++top] = elem;
    return true;
}

char *Stack::pop(void) {
    return top == -1 ? nullptr : &(arr[top--]);
}

char *Stack::peek(void) {
    return top == -1 ? nullptr : &(arr[top]);
}