/*
 * @file main.cpp
 * @brief Menu-driven program to interface with a Binary Tree ADT
 * @details It contains the following options:
 * 1. Insert
 * 2. Preorder Traversal
 * 3. Inorder Traversal
 * 4. Postorder Traversal
 * 5. Search
 * 6. Exit
 */

#include <iostream>
#include "btree.hpp"

using namespace std;

/*
 * @brief Menu function to handle user input
 * @details Takes user input and performs appropriate operations, printing success or failure states to the console
 * @param tree Pointer to the BTree being modified
 * @return Does not return anything, but exits with status code 0 if the user chooses to exit
 */
void menu(BTree *tree);

/*
 * @brief Displays the traversal result
 * @details Prints the elements of the traversal array and frees the allocated memory
 * @param traversal Pointer to the traversal array
 * @param size Size of the traversal array
 */
void display_traversal(char *traversal, int size);

/*
 * @brief Main function
 * @details Initializes the BTree and defers to the menu function for operations
 * @return Return is handled via exit in menu
 */
int main(void) {
    BTree *tree = new BTree();
    while (true)
        menu(tree);
}

void menu(BTree *tree) {
    cout
        << "1. Insert" << endl
        << "2. Preorder Traversal" << endl
        << "3. Inorder Traversal" << endl
        << "4. Postorder Traversal" << endl
        << "5. Search" << endl
        << "0. Exit" << endl
        << "Enter choice: ";

    unsigned choice;
    char elem;
    bool success;
    string path;
    cin >> choice;

    switch (choice) {
    case 0:
        delete tree;
        exit(0);

    case 1:
        cout << "Enter character to insert: ";
        cin >> elem;
        success = tree->insert(elem);
        if (success)
            cout << "Element inserted successfully!" << endl;
        else
            cout << "Operation failed!" << endl;
        break;

    case 2: {
        char *traversal = tree->preorder();
        if (traversal != nullptr) {
            cout << "Preorder Traversal: ";
            display_traversal(traversal, tree->get_size());
        } else {
            cout << "Tree is empty!" << endl;
        }
        break;
    }

    case 3: {
        char *traversal = tree->inorder();
        if (traversal != nullptr) {
            cout << "Inorder Traversal: ";
            display_traversal(traversal, tree->get_size());
        } else {
            cout << "Tree is empty!" << endl;
        }
        break;
    }

    case 4: {
        char *traversal = tree->postorder();
        if (traversal != nullptr) {
            cout << "Postorder Traversal: ";
            display_traversal(traversal, tree->get_size());
        } else {
            cout << "Tree is empty!" << endl;
        }
        break;
    }

    case 5:
        cout << "Enter character to search: ";
        cin >> elem;
        if ((path = tree->search(elem)) != "") {
            cout << "Element '" << elem << "' found in the tree!" << endl;
            cout << path << elem << endl;
        } else {
            cout << "Element '" << elem << "' not found in the tree!" << endl;
        }
        break;

    default:
        cout << "Invalid input! Please try again." << endl;
    }

    cout << endl << endl;
}

void display_traversal(char *traversal, int size) {
    for (int i = 0; i < size; ++i) {
        cout << traversal[i] << " ";
    }
    cout << endl;
    delete[] traversal;
}