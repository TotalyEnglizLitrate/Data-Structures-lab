/*
 * @file btree.cpp
 * @brief Implements Binary Tree defined in btree.hpp
 */

#include "btree.hpp"
#include <queue>

bool BTree::insert(char elem) {
  if (root == nullptr) {
    root = new TreeNode { elem, nullptr, nullptr, nullptr };
    if (root == nullptr)
      return false;
    size++;
    return true;
  }

  std::queue<TreeNode *> to_check;
  to_check.push(root);
  TreeNode *traversal_node;
  while (!to_check.empty()) {
    traversal_node = to_check.front();
    to_check.pop();

    if (traversal_node->left == nullptr) {
      traversal_node->left =
        new TreeNode { elem, traversal_node, nullptr, nullptr };
      if (traversal_node->left == nullptr)
        return false;
      size++;
      return true;
    } else {
      to_check.push(traversal_node->left);
    }

    if (traversal_node->right == nullptr) {
      traversal_node->right =
        new TreeNode { elem, traversal_node, nullptr, nullptr };
      if (traversal_node->right == nullptr)
        return false;
      size++;
      return true;
    } else {
      to_check.push(traversal_node->right);
    }
  }

  return false;
}

int BTree::_inorder(TreeNode *root, char *traversal, int end) {
  if (root == nullptr)
    return end;

  TreeNode *traversal_node = root;
  while (traversal_node->left != nullptr)
    traversal_node = traversal_node->left;
  traversal[++end] = traversal_node->val;

  while (traversal_node != root) {
    traversal_node = traversal_node->parent;
    traversal[++end] = traversal_node->val;
    end = _inorder(traversal_node->right, traversal, end);
  }

  return end;
}

char *BTree::inorder(void) {
  if (root == nullptr)
    return nullptr;

  char *traversal = new char[size];
  _inorder(root, traversal, -1);
  return traversal;
}

int BTree::_preorder(TreeNode *root, char *traversal, int end) {
  if (root == nullptr)
    return end;

  traversal[++end] = root->val;
  TreeNode *traversal_node = root;
  while (traversal_node->left != nullptr) {
    traversal_node = traversal_node->left;
    traversal[++end] = traversal_node->val;
  }

  while (traversal_node != root) {
    traversal_node = traversal_node->parent;
    end = _preorder(traversal_node->right, traversal, end);
  }

  return end;
}

char *BTree::preorder(void) {
  if (root == nullptr)
    return nullptr;

  char *traversal = new char[size];
  _preorder(root, traversal, -1);
  return traversal;
}

int BTree::_postorder(TreeNode *root, char *traversal, int end) {
  if (root == nullptr)
    return end;

  TreeNode *traversal_node = root;
  while (traversal_node->left != nullptr)
    traversal_node = traversal_node->left;

  traversal[++end] = traversal_node->val;

  while (traversal_node != root) {
    traversal_node = traversal_node->parent;
    end = _postorder(traversal_node->right, traversal, end);
    traversal[++end] = traversal_node->val;
  }

  return end;
}

char *BTree::postorder(void) {
  if (root == nullptr)
    return nullptr;

  char *traversal = new char[size];
  _postorder(root, traversal, -1);
  return traversal;
}

std::string BTree::_search(TreeNode *node, char elem, std::string path) {
  if (node == nullptr)
    return "";

  if (node->val == elem)
    return "root -> " + path;

  std::string _path;
  if ((_path = _search(node->left, elem, path + "left" + " -> ")) != "")
    return _path;
  if ((_path = _search(node->right, elem, path + "right" + " -> ")) != "")
    return _path;

  return "";
}

std::string BTree::search(char elem) { return _search(root, elem, ""); }

unsigned BTree::get_size(void) { return size; }

void BTree::clear(TreeNode *root) {
  if (root == nullptr) return;
  clear(root->left);
  clear(root->right);
  delete root;
}