#include <iostream>
#include "bst.hpp"

int main(void) {
    BinarySearchTree bst = BinarySearchTree();
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Done inserting" << std::endl;

    int *inorder = bst.inorder();
    int *preorder = bst.preorder();
    int *postorder = bst.postorder();

    std::cout << "Done forming traversals" << std::endl;

    std::cout << "Inorder - ";
    for (unsigned i = 1; i <= inorder[0]; i++)
        std::cout << inorder[i] << " ";
    std::cout << std::endl;

    std::cout << "Preorder - ";
    for (unsigned i = 1; i <= preorder[0]; i++)
        std::cout << preorder[i] << " ";
    std::cout << std::endl;

    std::cout << "Postorder -";
    for (unsigned i = 1; i <= postorder[0]; i++)
        std::cout << postorder[i] << " ";
    std::cout << std::endl;

    bool idk;
    std::cout << bst.search(30, &idk) << std::endl;
    std::cout << bst.search(50, &idk) << std::endl;
    std::cout << bst.search(80, &idk) << std::endl;

    delete[] inorder;
    delete[] postorder;
    delete[] preorder;
    
    return 0;
}