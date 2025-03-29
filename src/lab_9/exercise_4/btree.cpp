/*
 * @file btree.cpp
 * @brief Implements Binary Tree defined in btree.hpp
 */

#include "btree.hpp"
#include <stack>

struct Op {
  char symbol;
  unsigned precedence;
};

static Op add = { '+', 0 }, sub = { '-', 0 }, mul = { '*', 1 }, divide = { '/', 1 },
mod = { '%', 1 };
static Op *operators[] = { &add, &sub, &mul, &divide, &mod };
static unsigned op_len = 5;

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

unsigned BTree::get_size(void) { return size; }

void BTree::clear(TreeNode *root) {
  if (root == nullptr)
    return;
  clear(root->left);
  clear(root->right);
  delete root;
}

bool is_operator(char c) {
  for (unsigned i = 0; i < op_len; i++) {
    if (operators[i]->symbol == c)
      return true;
  }

  return false;
}

bool BTree::create_expression_tree(std::string expr) {
  clear(root);

  std::stack<TreeNode *> conv;
  TreeNode *tmp, *tmp1, *tmp2;

  for (char c : expr) {
    if (is_operator(c)) {
      if (conv.empty()) {
        clear(root);
        return false;
      }

      tmp = conv.top();
      conv.pop();

      if (conv.empty()) {
        clear(root);
        return false;
      }

      tmp1 = conv.top();
      conv.pop();

      tmp2 = new TreeNode { c, nullptr, tmp1, tmp };
      if (tmp2 == nullptr) {
        clear(root);
        return false;
      }
      tmp2->left = tmp1;
      tmp2->right = tmp;
      tmp->parent = tmp1->parent = tmp2;
      conv.push(tmp2);
      continue;
    }

    tmp = new TreeNode { c, nullptr, nullptr, nullptr };
    if (tmp == nullptr) {
      clear(root);
      return false;
    }
    conv.push(tmp);

  }

  if (conv.empty()) {
    clear(root);
    return false;
  }

  tmp = conv.top();
  conv.pop();
  if (!conv.empty()) {
    clear(root);
    return false;
  }

  root = tmp;
  size = expr.length();
  return true;
}
