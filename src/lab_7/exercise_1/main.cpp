/*
 * @file main.cpp
 * @brief Menu driven program to interface with a queue
 * @details It contains the following options
 * i) Enqueue
 * ii) Dequeue
 * iii) Peek
 * iv) Exit
*/

#include <iostream>

#include "queue_arr.hpp"

using namespace std;

/*
 * @brief Menu function to handle user input
 * @details Take user input and performs appropriate operations and prints out
 * success or failure states to the console
 * @param Pointer to the queue being modified
 * @return Does not return anything, however exits with status code 0 if user exits
*/
void menu(Queue *queue);

/*
 * @brief Main function
 * @details Initializes the queue and defers to the menu function for operations
 * @return Return is handled via exit in menu
*/
int main(void) {
    Queue *queue = new Queue();
    while (true)
        menu(queue);
}

void menu(Queue *queue) {
    cout
        << "1. Enqueue" << endl
        << "2. Dequeue" << endl
        << "3. Peek" << endl
        << "0. Exit" << endl
        << "Enter choice: ";
    
    unsigned choice;
    int elem;
    bool success;
    cin >> choice;

    switch (choice) {
    case 0:
        delete queue;
        exit(0);
    
    case 1:
        cout << "Enter element to enqueue: ";
        cin >> elem;
        queue->enqueue(elem, &success);
        if (!success)
            cout << "Operation failed; Insufficient space in queue!" << endl;
        break;
    
    case 2:
        elem = queue->dequeue(&success);
        if (success)
            cout << "Dequeued element: " << elem << endl;
        else
            cout << "Cannot dequeue from empty queue!" << endl;
        break;
    case 3:
        elem = queue->peek(&success);
        if (success)
            cout << "Front element: " << elem << endl;
        else
            cout << "Cannot peek empty queue!" << endl;
        break;

    default:
        cout << "Invalid input! please try again" << endl;
    }


    cout << endl << endl;
}