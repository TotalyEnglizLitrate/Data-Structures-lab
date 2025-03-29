/*
 * @file btree.hpp
 * @brief Define a Binary Tree Class
 */

#include <string>

class BTree {
public:
  struct TreeNode {
    char val;
    struct TreeNode *parent, *left, *right;
  };

private:
  TreeNode *root;
  unsigned size;

  /*
   * @brief Helper function to inorder that implements the recursive part
   * @param root root node of tree (or subtree) to traverse
   * @param traversal array of character values
   * @param end Index of end of string
   */
  int _inorder(TreeNode *root, char *traversal, int end);

  /*
   * @brief Helper function to preorder that implements the recursive part
   * @param root root node of tree (or subtree) to traverse
   * @param traversal array of character values
   * @param end Index of end of string
   */
  int _preorder(TreeNode *root, char *traversal, int end);

  /*
   * @brief Helper function to postorder that implements the recursive part
   * @param root root node of tree (or subtree) to traverse
   * @param traversal array of character values
   * @param end Index of end of string
   */
  int _postorder(TreeNode *root, char *traversal, int end);


  /*
   * @brief Helper function for destructor
   * @param root Root node of tree (or subtree) to delete
   */
  void clear(TreeNode *root);

public:
  /*
   * @brief Construncts a new empty BTree
   */
  BTree(void) : root(nullptr) {}

  /*
   * @brief Frees the memory allocated for the tree nodes
   */
  ~BTree(void) { clear(root); }

  /*
   * @brief Inorder traversal of the tree
   * @return char array with inorder traversal
   *
   */
  char *inorder(void);

  /*
   * @brief Pre-order traversal of the tree
   * @return char array with preorder traversal
   */
  char *preorder(void);

  /*
   * @brief Post-order traversal of the tree
   * @return char array with postorder traversal
   */
  char *postorder(void);


  /*
   * @brief Returns no. of elements in the Tree
   */
  unsigned get_size(void);

  /*
   * @brief Costructs an expression tree from a valid postfix expression
   * @param expr any valid postfix expression
   * @return Boolean flag indicating success/failure
   */
  bool create_expression_tree(std::string expr);
};
