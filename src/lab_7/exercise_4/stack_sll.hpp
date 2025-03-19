/*
 * @file stack_sll.hpp
 * @brief Define a stack ADT using a singly linked list
*/

/*
 * @brief A stack class implemented using a singly linked list
*/
class Stack {
private:
    struct Node {
        char val;
        struct Node *next;
    };
    
    struct Node *top;

    /*
     * @brief Returns boolean indicating whether the stack is empty or not
    */
    bool is_empty(void);
public:
    
    /*
     * @brief Constructs a new instance of the stack class
     * @details Initialises top to nullptr to indicate empty stack
    */
    Stack(void): top(nullptr) {}

    /*
     * @brief Destroys the stack
    */
    ~Stack(void) {
    Node *curr = top;
    while (curr != nullptr) {
        top = top->next;
        delete curr;
        curr = top;
    }

    /*
     * @brief Pushes an element onto the stack
     * @param elem Character value to push
     * @param success Boolean pointer to set to true/false to indicate success/failure
    */
    void push(char elem, bool *success);

    /*
     * @brief Pops an element from the stack
     * @param success Boolean pointer to set to true/false to indicate success/failure 
     * @return success Returns the element removed from the stack or 0
     * upon failure
    */
    char pop(bool *success);
}; 