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
   * @brief Helper function to search that implements the recursive part
   * @param root root node of tree (or subtree) to search
   * @param elem char to search for
   * @param string Path to keep track of to return at the end
   */
  std::string _search(TreeNode *root, char elem, std::string path);

  /*
   * @brief Helper function for destructor
   * @root Root node oftree (or subtree) to delete
   */
  void clear(TreeNode *root);

public:
  /*
   * @brief Construncts a new instance of the BTree class
   */
  BTree(void) : root(nullptr) {}

  /*
   * @brief Frees the memory allocated for the tree nodes
   */
  ~BTree(void) { clear(root); }

  /*
   * @brief Inserts an element into the tree
   * @param elem Character value to push
   * @return Boolean indicating success/failure
   */
  bool insert(char elem);

  /*
   * @brief Inorder traversal of the tree
   * @return Vector with inorder traversal
   *
   */
  char *inorder(void);

  /*
   * @brief Pre-order traversal of the tree
   * @return Vector with preorder traversal
   */
  char *preorder(void);

  /*
   * @brief Post-order traversal of the tree
   * @return Vector with postorder traversal
   */
  char *postorder(void);

  /*
   * @brief Search for an element and print it's path if found
   */
  std::string search(char elem);

  unsigned get_size(void);
};
