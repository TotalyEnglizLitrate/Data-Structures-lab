/*
 * @file circular_queue_arr.hpp
 * @brief Define a queue ADT using a fixed length integer array of length LENGTH
*/

#define LENGTH 5

/*
 * @brief A queue class implemented using a fixed length array
*/
class Queue {
private:
    int queue[LENGTH];
    short front, rear;

    /*
     * @brief Returns boolean indicating whether the queue is full or not
    */
    bool is_full(void);

    /*
     * @brief Returns boolean indicating whether the queue is empty or not
    */
    bool is_empty(void);
public:
    
    /*
     * @brief Constructs a new instance of the queue class
     * @details Initialises front and rear to -1 to indicate empty queue
    */
    Queue(void): front(-1), rear(-1) {}

    /*
     * @brief Enqueues an element
     * @param elem Integer value to enqueue
     * @param success Boolean pointer to set to true/false to indicate success/failure
    */
    void enqueue(int elem, bool *success);

    /*
     * @brief Dequeues an element
     * @param success Boolean pointer to set to true/false to indicate success/failure 
     * @return Returns the element removed from the front of the queue or 0
     * upon failure
    */
    int dequeue(bool *success);

    /*
     * @brief Peeks at the front of the queue
     * @param success Boolean pointer to set to true/false to indicate success/failure
     * @return Returns the front of the queue or 0 upon failure
    */
    int peek(bool *success);
};