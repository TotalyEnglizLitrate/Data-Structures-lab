#include <iostream>

#include "graph.hpp"

using namespace std;

/*
 * @brief Menu function to handle user input
 * @details Takes user input and performs appropriate operations, printing success or
 * failure states to the console
 * @param graph Pointer to the Graph being modified
 */
void menu(Graph *graph);

/*
 * @brief Main function
 * @details Initializes the HashMap and defers to the menu function for operations
 * @return Return is handled via exit in menu
 */
int main(void) {
    Graph *graph = new Graph();
    while (true)
        menu(graph);
}

void menu(Graph *graph) {
    cout
        << "1. Insert" << endl
        << "2. Delete" << endl
        << "3. Search" << endl
        << "4. Display" << endl
        << "0. Exit" << endl
        << "Enter choice: ";

    unsigned choice;
    int key;
    int val;
    char ans;
    std::unordered_set<int> vals;
    bool success;
    cin >> choice;

    switch (choice) {
    case 0:
        delete graph;
        exit(0);

    case 1:
        cout << "Enter value to insert: ";
        cin >> key;

        cout << "Enter connected nodes? ";
        cin >> ans;
        while (ans == 'y' || ans == 'Y') {
            cout << "Enter values connected with node " << key << ": ";
            cin >> val;
            vals.insert(val);
            cout << "Enter more connected nodes? ";
            cin >> ans;
        }

        success = graph->insert(key, vals);
        if (!success)
            cout << "Operation failed!" << endl;
        break;

    case 2:
        cout << "Enter value to delete: ";
        cin >> key;
        success = graph->del(key);
        if (success)
            cout << "Value deleted: " << endl;
        else
            cout << "Value not in graph!" << endl;
        break;

    case 3:
        cout << "Enter value to search for: ";
        cin >> key;
        success = graph->search(key);
        if (success)
            cout << "Value present in graph" << endl;
        else
            cout << "Value not in graph" << endl;
        break;

    case 4:
        graph->display();
        break;

    default:
        cout << "Invalid input! please try again" << endl;
    }


    cout << endl << endl;
}