/*
  Implement a list ADT using a fixed length array of length 5
  implement the following functions
  1. Insertion
    - Beginning
    - Given position
    - End
  2. Deletion
    - Beginning
    - Given position
    - End
  3. Search
  4. Display
  5. Rotate
*/

#include <iostream>

#define LENGTH 5 // Hardcoded array length as given in question

using namespace std;

// Union Result type for handling function return values, in order to reduce number of variables in namespace
union Result {
    int integer;
    bool boolean;
};

// List ADT implemented using a static array satisfying the parameters given in the question
class List {
    private:
        int arr[LENGTH];
        int curr;
    public:
        List(): curr(-1) {};
        bool insert_beginning(int);
        bool insert_at(int, int);
        bool insert_end(int);
        bool delete_beginning(void);
        bool delete_at(int);
        bool delete_end(void);
        int search(int);
        void display(void);
        void rotate(int);
};


void menu(List *);


int main(void) {
    List list = List();
    while (true)
        menu(&list);
    return 0;
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
        << "9. Rotate the list (to the right) by a specified amount" << endl
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
        result.boolean = list->insert_at(elem, (int) index);
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
        result.boolean = list->delete_at((int) index);
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
        cout << "Enter amount to rotate by: ";
        // elem is actually the amount to rotate by and not element,
        // reusing variable name as to not clutter the namespace for a single function call
        cin >> elem;
        list->rotate(elem);
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


// Generalized insert function that takes in element to insert and index to insert at
// returns false for failure, true otherwise
// Causes of failure 
//   - index greater than bound
//   - no space to insert a new element in list
bool List::insert_at(int elem, int index) {
    if (index > this->curr + 1 || this->curr == LENGTH - 1)
        return false;

    int curr;
    for (curr = this->curr; curr != index -1; curr--)
        this->arr[curr + 1] = this->arr[curr];

    this->arr[curr + 1] = elem;
    this->curr++;

    return true;
}


// Special case of insert function with index = 0
bool List::insert_beginning(int elem) {
    return this->insert_at(elem, 0);
}


// Special case of insert function with index = current + 1
bool List::insert_end(int elem) {
    return this->insert_at(elem, this->curr + 1);
}


// Generalized delete function that takes in index to delete at
// returns false for failure, true otherwise
// Causes of failure 
//   - index greater than bound
//   - deletion from empty list
bool List::delete_at(int index) {
    if (index > this->curr || this->curr == -1)
        return false;

    for (int i = index; i < this->curr; i++)
        this->arr[i] = this->arr[i + 1];
    this->curr--;

    return true;
}


// Special case of delete function with index = 0
bool List::delete_beginning(void) {
    return this->delete_at(0);
}


// Sepecial case of delete function with index = current
bool List::delete_end(void) {
    return this->delete_at(this->curr);
}


// Searches the array for a given element
// returns index of element if found, `-1` if element not in array
int List::search(int elem) {
    for (int i = 0; i <= this->curr; i++)
        if (arr[i] == elem)
            return i;
    return -1;
}


// Simple function to display elements in the list
// elements beyond currently filled point (current) are represented by `_`
void List::display(void) {
    cout << "[ ";
    for (int i = 0; i < LENGTH; i++) {
        if (i > this->curr)
            cout << "_, ";
        else
            cout << this->arr[i] << ", ";
    }
    cout << "]";

    return;
}


// Rotates the list elements (to the right) by "amount" places, in place
void List::rotate(int amount) {
    for (int i = 0; i <= this->curr; i++)
        swap(arr[0], arr[(i + amount) % (this->curr + 1)]);
}
