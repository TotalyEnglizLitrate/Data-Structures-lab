#include "hashmap.hpp"

using namespace std;

/*
 * @brief Menu function to handle user input
 * @details Takes user input and performs appropriate operations, printing
 * success or failure states to the console
 * @param map Pointer to the HashMap being modified
 */
void menu(HashMap *map);

/*
 * @brief Main function
 * @details Initializes the HashMap and defers to the menu function for operations
 * @return Return is handled via exit in menu
 */
int main(void) {
    HashMap *map = new HashMap();
    while (true)
        menu(map);
}

void menu(HashMap *map) {
    cout
        << "1. Insert" << endl
        << "2. Delete" << endl
        << "3. Search" << endl
        << "4. Display" << endl
        << "0. Exit" << endl
        << "Enter choice: ";

    unsigned choice;
    int key, val;
    bool success;
    cin >> choice;

    switch (choice) {
    case 0:
        delete map;
        exit(0);

    case 1:
        cout << "Enter key to insert: ";
        cin >> key;
        cout << "Enter value associated with key " << key << ": ";
        cin >> val;
        success = map->insert(key, val);
        if (!success)
            cout << "Operation failed!" << endl;
        break;

    case 2:
        cout << "Enter key of key-value pair to delete: ";
        cin >> key;
        val = map->del(key, &success);
        if (success)
            cout << "Value associated with deleted key: " << val << endl;
        else
            cout << "Operation failed!" << endl;
        break;

    case 3:
        cout << "Enter key to search for: ";
        cin >> key;
        val = map->search(key, &success);
        if (success)
            cout << "Value associated with key: " << val << endl;
        else
            cout << "Key not in map" << endl;
        break;

    case 4:
        map->display();
        break;

    default:
        cout << "Invalid input! please try again" << endl;
    }


    cout << endl << endl;
}