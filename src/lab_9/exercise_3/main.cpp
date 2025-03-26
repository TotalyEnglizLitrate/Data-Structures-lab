#include <iostream>

#include "bst.hpp"

using namespace std;

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
        cout << "Enter element to enqueue: ";
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
            cout << path << endl;
        else
            cout << "Element not found in tree!" << endl;
        break;

    default:
        cout << "Invalid input! please try again" << endl;
    }


    cout << endl << endl;
}

int main(void) {
    BinarySearchTree *bst = new BinarySearchTree();
    while (true)
        menu(bst);
}