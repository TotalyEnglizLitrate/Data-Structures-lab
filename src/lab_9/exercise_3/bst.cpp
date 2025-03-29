#include "bst.hpp"

bool BinarySearchTree::insert(int elem) {
    Node *new_node = new Node {elem, nullptr, nullptr, nullptr};
    if (new_node == nullptr) return false;

    if (root == nullptr) {
        root = new_node;
        len++;
        return true;
    }

    Node *traversal_node = root;
    while (true) {
        if (traversal_node->data == elem) {
            delete new_node;
            return false;
        } else if (traversal_node->data > elem) {
            if (traversal_node->left == nullptr) {
                new_node->parent = traversal_node;
                traversal_node->left = new_node;
                len++;
                return true;
            } else {
                traversal_node = traversal_node->left;
            }
        } else {
            if (traversal_node->right == nullptr) {
                new_node->parent = traversal_node;
                traversal_node->right = new_node;
                len++;
                return true;
            } else {
                traversal_node = traversal_node->right;
            }
        }
    }
}


unsigned BinarySearchTree::_preorder(Node *root, int *arr, unsigned index) {
    if (root == nullptr) return index;
    arr[++index] = root->data;
    index = _preorder(root->left, arr, index);    
    index = _preorder(root->right, arr, index);
    return index;
}

int *BinarySearchTree::preorder(void) {
    int *ret_arr = new int[len + 1];
    if (ret_arr == nullptr) return nullptr;
    ret_arr[0] = len;
    _preorder(root, ret_arr, 0);
    return ret_arr;
}

unsigned BinarySearchTree::_postorder(Node *root, int *arr, unsigned index) {
    if (root == nullptr) return index;
    index = _postorder(root->left, arr, index);
    index = _postorder(root->right, arr, index);
    arr[++index] = root->data;
    return index;
}

int *BinarySearchTree::postorder(void) {
    int *ret_arr = new int[len + 1];
    if (ret_arr == nullptr) return nullptr;
    ret_arr[0] = len;
    _postorder(root, ret_arr, 0);
    return ret_arr;
}

unsigned BinarySearchTree::_inorder(Node *root, int *arr, unsigned index) {
    if (root == nullptr) return index;
    index = _inorder(root->left, arr, index);    
    arr[++index] = root->data;
    index = _inorder(root->right, arr, index);
    return index;
}

int *BinarySearchTree::inorder(void) {
    int *ret_arr = new int[len + 1];
    if (ret_arr == nullptr) return nullptr;
    ret_arr[0] = len;
    _inorder(root, ret_arr, 0);
    return ret_arr;
}

std::string BinarySearchTree::search(int elem, bool *success) {
    *success = false;
    if (root == nullptr) return "";

    Node *traversal_node = root;
    std::string path = "root";
    while (traversal_node != nullptr) {
        if (traversal_node->data == elem) {
            *success = true;
            return path;
        } else if (traversal_node->data > elem) {
            traversal_node = traversal_node->left;
            path.append(" -> left");
        } else {
            traversal_node = traversal_node->right;
            path.append(" -> right");
        }
    }

    return path;
}

void BinarySearchTree::clear(Node *root) {
    if (root == nullptr) return;
    clear(root->left);
    clear(root->right);
    delete root;
} 