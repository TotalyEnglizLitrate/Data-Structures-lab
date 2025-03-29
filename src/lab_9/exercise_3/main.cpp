#include <iostream>

#include "bst.hpp"

using namespace std;

/*
 * @brief Print traversal array returned by the BST methods
 * @param arr Integer (array like) pointer, with first element being the length
 * of the array
 */
void print_traversal(int *arr);

/*
 * @brief Menu function to handle user input
 * @param tree Pointer to the BTree being modified
 * @return Does not return anything, but exits with status code 0 if the user chooses to exit
 */
void menu(BinarySearchTree *bst);

/*
 * @brief Main function that instantiates a new BST and defers to menu fucntion
 * @return Return is handled via exit in menu
 */
int main(void) {
    BinarySearchTree *bst = new BinarySearchTree();
    while (true)
        menu(bst);
}

void print_traversal(int *arr) {
    if (arr == nullptr) {
        cout << "Operation failed!" << endl;
        return;
    }
    if (arr[0] == 0)
        cout << "Empty Binary Tree!";
    for (unsigned i = 1; i <= arr[0]; arr++)
        cout << arr[i] << " ";
    cout << endl;
}

void menu(BinarySearchTree *bst) {
    cout
        << "1. Insert" << endl
        << "2. Preorder traversal" << endl
        << "3. Postorder traversal" << endl
        << "4. Inorder traversal" << endl
        << "5. Search" << endl
        << "0. Exit" << endl
        << "Enter choice: ";

    unsigned choice;
    int elem;
    bool success;
    string path;
    cin >> choice;

    switch (choice) {
    case 0:
        delete bst;
        exit(0);

    case 1:
        cout << "Enter element to insert: ";
        cin >> elem;
        success = bst->insert(elem);
        if (!success)
            cout << "Operation failed!" << endl;
        break;

    case 2:
        print_traversal(bst->preorder());
        break;

    case 3:
        print_traversal(bst->postorder());
        break;

    case 4:
        print_traversal(bst->inorder());
        break;

    case 5:
        cout << "Enter element to search: ";
        cin >> elem;
        path = bst->search(elem, &success);
        if (success)
            cout << path << " -> " << elem << endl;
        else
            cout << "Element not found in tree!" << endl;
        break;

    default:
        cout << "Invalid input! please try again" << endl;
    }


    cout << endl << endl;
}