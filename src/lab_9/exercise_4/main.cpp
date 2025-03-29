#include <iostream>

#include "btree.hpp"

using namespace std;

/*
 * @brief Menu function to handle user input
 * @details Takes user input and performs appropriate operations, printing success or failure states to the console
 * @param tree Pointer to the BTree being modified
 * @param expr Reference to a string for storing the postfix expression
 * @return Does not return anything, but exits with status code 0 if the user chooses to exit
 */
void menu(BTree *tree, string &expr);

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
    string expr;
    while (true)
        menu(tree, expr);
}

void menu(BTree *tree, string &expr) {
    cout
        << "1. Input Postfix expression" << endl
        << "2. Create Expression Tree" << endl
        << "3. Preorder Traversal" << endl
        << "4. Inorder Traversal" << endl
        << "5. Postorder Traversal" << endl
        << "0. Exit" << endl
        << "Enter choice: ";

    unsigned choice;
    char elem;
    char *traversal;
    bool success;
    string path;
    cin >> choice;

    switch (choice) {
    case 0:
        delete tree;
        exit(0);

    case 1:
        expr.clear();
        cout << "Enter postfix expression: ";
        cin >> expr;
        break;

    case 2:
        cout << "Creating expression tree..." << endl;
        if (expr.empty()) {
            cout << "Postfix expression is empty!" << endl;
            break;
        }
        success = tree->create_expression_tree(expr);
        if (success)
            cout << "Expression tree created successfully!" << endl;
        else
            cout << "Failed to create expression tree, Invalid postfix expression!" << endl;
        break;

    case 3:
        traversal = tree->preorder();
        if (traversal != nullptr) {
            cout << "Preorder Traversal: ";
            display_traversal(traversal, tree->get_size());
        } else {
            cout << "Tree is empty!" << endl;
        }
        break;

    case 4:
        traversal = tree->inorder();
        if (traversal != nullptr) {
            cout << "Inorder Traversal: ";
            display_traversal(traversal, tree->get_size());
        } else {
            cout << "Tree is empty!" << endl;
        }
        break;

    case 5:
        traversal = tree->postorder();
        if (traversal != nullptr) {
            cout << "Postorder Traversal: ";
            display_traversal(traversal, tree->get_size());
        } else {
            cout << "Tree is empty!" << endl;
        }
        break;

    default:
        cout << "Invalid input! Please try again." << endl;
    }

    cout << endl << endl;
}

void display_traversal(char *traversal, int size) {
    for (int i = 0; i < size; ++i) cout << traversal[i];
    cout << endl;
    delete[] traversal;
}
