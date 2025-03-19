/*
 * @file queue_sll.hpp
 * @brief Define a queue ADT using a singly linked list
*/

/*
 * @brief A queue class implemented using a singly linked list
*/
class Dequeue {
private:
    struct Node {
        char val;
        struct Node *next;
    };
    
    struct Node *front, *rear;

    /*
     * @brief Returns boolean indicating whether the queue is empty or not
    */
    bool is_empty(void);
public:
    
    /*
     * @brief Constructs a new instance of the queue class
     * @details Initialises front and rear to -1 to indicate empty queue
    */
    Dequeue(void): front(nullptr), rear(nullptr) {}

    /*
     * @brief Enqueues an element at the back of the queue
     * @param elem Character value to enqueue
     * @param success Boolean pointer to set to true/false to indicate success/failure
    */
    void enqueue_back(char elem, bool *success);

    /*
     * @brief Enqueues an element at the front of the queue
     * @param elem Character value to enqueue
     * @param success Boolean pointer to set to true/false to indicate success/failure
    */
    void enqueue_front(char elem, bool *success);

    /*
     * @brief Dequeues an element from the front of the queue
     * @param elem Boolean pointer to set to true/false to indicate success/failure 
     * @return success Returns the element removed from the front of the queue or 0
     * upon failure
    */
    char dequeue_front(bool *success);

    /*
     * @brief Dequeues an element from the back of the queue
     * @param success Boolean pointer to set to true/false to indicate success/failure 
     * @return Returns the element removed from the front of the queue or 0
     * upon failure
    */
    char dequeue_back(bool *success);

    /*
     * @brief Peeks at the front of the queue
     * @param success Boolean pointer to set to true/false to indicate success/failure
     * @return Returns the front of the queue or 0 upon failure
    */
    char peek(bool *success);
};