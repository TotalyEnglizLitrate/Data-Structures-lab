#include <iostream>

#include "priority_queue.hpp"

using namespace std;

/*
 * @brief Menu function to handle user input
 * @details Takes user input and performs appropriate operations, printing success or failure states to the console
 * @param queue Pointer to the PriorityQueue being modified
 */
void menu(PriorityQueue *queue);

/*
 * @brief Main function
 * @details Initializes the PriorityQueue and defers to the menu function for operations
 * @return Return is handled via exit in menu
 */
int main(void) {
    PriorityQueue *queue = new PriorityQueue();
    while (true)
        menu(queue);
}

void menu(PriorityQueue *queue) {
    cout
        << "1. Insert element" << endl
        << "2. Remove element" << endl
        << "3. Display elements" << endl
        << "4. Search element" << endl
        << "5. Sort elements" << endl
        << "0. Exit" << endl
        << "Enter your choice: ";

    unsigned short choice;
    bool success;
    int elem;
    vector<int> sorted;
    cin >> choice;

    switch (choice) {
    case 0:
        delete queue;
        exit(0);

    case 1:
        cout << "Enter element to be inserted: ";
        cin >> elem;
        success = queue->insert(elem);
        if (!success)
            cout << "Element already in queue!" << endl;
        break;

    case 2:
        cout << "Enter element to be removed: ";
        cin >> elem;
        success = queue->remove(elem);
        if (!success)
            cout << "Element not in queue!" << endl;
        break;

    case 3:
        queue->print();
        break;

    case 4:
        cout << "Enter element to search for: ";
        cin >> elem;
        cout << "Element " << elem << " is" << (queue->search(elem) ? " " : " not ") << "in the queue" << endl;
        break;

    case 5:
        sorted = queue->sort();
        for (int i : sorted)
            cout << i << ", ";
        cout << endl;
        break;

    default:
        cout << "Invalid Choice! Try again" << endl;
        break;
    }


    cout << endl << endl;
}