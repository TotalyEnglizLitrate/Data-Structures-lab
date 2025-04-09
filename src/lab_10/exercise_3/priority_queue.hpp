#include <vector>


/*
 * @brief Priority Queue implemented using a binary max heap
 */
class PriorityQueue {
private:
    std::vector<int> data;
    int size;

    /*
     * @brief Helper function to maintain the heap property
     * @param index Index of the element to heapify
     */
    void heapify_up(int index);

    /*
     * @brief Helper function to maintain the heap property
     * @param index Index of the element to heapify
     */
    void heapify_down(int index);

    /*
     * @brief Helper function to clear the heap
     */
    void clear(void);

    /*
     * @brief Private search function that returns index of element in vector
     * @param elem Element to search for
     * @param Boolean flag to indicate success/failure
     * @return Index of element
     */
    unsigned _search(int elem, bool *success);

    /*
     * @brief Removes element at given index from the priority queue
     * @param idx Index to remove
     * @return Boolean flag to indicate success/failure
     */
    bool _remove(unsigned idx);

public:
    PriorityQueue(void) : size(0) {}
    ~PriorityQueue(void) { clear(); }

    /*
     * @brief Inserts a new element into the priority queue
     * @param value Value to insert
     * @return true if insertion was successful, false otherwise
     */
    bool insert(int value);

    /*
     * @brief Removes a given element from the priority queue
     * @param value Reference to store the removed value
     * @return true if removal was successful, false otherwise
     */
    bool remove(int value);


    /*
     * @brief Checks if the priority queue is empty
     * @return true if empty, false otherwise
     */
    bool is_empty(void) const;

    /*
     * @brief Prints the elements of the priority queue
     */
    void print(void);

    /*
     * @brief Searches the heap for an element
     * @param elem Elemen to search for
     * @return Boolean indicating prescense/absence of element
     */
    bool search(int elem);

    /*
     * @brief Sorts the elements of the priority queue
     * @return Sorted array of elements
     */
    std::vector<int> sort(void);
};