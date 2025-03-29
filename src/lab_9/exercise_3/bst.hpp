#include <string>

class BinarySearchTree {
private:
  struct Node {
    int data;
    struct Node *parent, *left, *right;
  };
  Node *root;
  unsigned len;

  /*
   * @brief Helper function to preorder that implements the recursive part
   * @param root root node of tree (or subtree) to traverse
   * @param traversal array of integer values
   * @param end Index of end of last inserted value
   */
  unsigned _preorder(Node *root, int *arr, unsigned index);

  /*
   * @brief Helper function to postorderthat implements the recursive part
   * @param root root node of tree (or subtree) to traverse
   * @param traversal array of integer values
   * @param end Index of end of last inserted value
   */
  unsigned _postorder(Node *root, int *arr, unsigned index);

  /*
   * @brief Helper function to inorder that implements the recursive part
   * @param root root node of tree (or subtree) to traverse
   * @param traversal array of integer values
   * @param end Index of end of last inserted value
   */
  unsigned _inorder(Node *root, int *arr, unsigned index);

  /*
   * @brief Helper function for destructor
   * @root Root node oftree (or subtree) to delete
   */
  void clear(Node *root);

public:

  /*
   * @brief Construncts a new instance of the BTree class
   */
  BinarySearchTree(void) : root(nullptr), len(0) {}

  /*
   * @brief Frees the memory allocated for the tree nodes
   */
  ~BinarySearchTree(void) { clear(root); }

  /*
   * @brief Inserts an element into the tree
   * @param elem Character value to push
   * @return Boolean indicating success/failure
   */
  bool insert(int elem);

  /*
   * @brief Preorder traversal of the binary search tree
   * @return Integer (array like) pointer, first element being length of the
   * array
   */
  int *preorder(void);

  /*
   * @brief Postorder traversal of the binary search tree
   * @return Integer (array like) pointer, first element being length of the
   * array
   */
  int *postorder(void);

  /*
   * @brief Inorder traversal of the binary search tree
   * @return Integer (array like) pointer, first element being length of the
   * array
   */
  int *inorder(void);

  /*
   * @brief Search for an element and print it's path if found
   * @param elem Element to search
   * @param success Boolean pointer - flag var to indicate success/failure
   * @return String representing steps taken to reach the node from the root
   */
  std::string search(int elem, bool *success);
};