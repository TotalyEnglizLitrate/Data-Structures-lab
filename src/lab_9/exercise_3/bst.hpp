#include <string>

class BinarySearchTree {
private:
    struct Node {
        int data;
        struct Node *parent, *left, *right;
    };
    Node *root;
    unsigned len;
    unsigned _preorder(Node *root, int *arr, unsigned index);
    unsigned _postorder(Node *root, int *arr, unsigned index);
    unsigned _inorder(Node *root, int *arr, unsigned index);
public:
    BinarySearchTree(void): root(nullptr), len(0) {}
    bool insert(int elem);
    int *preorder(void);
    int *postorder(void);
    int *inorder(void);
    std::string search(int elem, bool *success);
};