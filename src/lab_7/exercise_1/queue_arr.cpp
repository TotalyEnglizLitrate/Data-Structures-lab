/*
 * @file queue_arr.cpp
 * @brief Implement a queue ADT using a fixed length integer array of length LENGTH
 * @details The queue must implement the following operations
 * i) Enqueue
 * ii) Dequeue
 * iii) Peek
*/

#include "queue_arr.hpp"

bool Queue::is_empty(void) {
    return rear == -1;
}

bool Queue::is_full(void) {
    return rear == LENGTH - 1;
}

void Queue::enqueue(int elem, bool *success) {
    *success = true;

    if (is_full())
        *success = false;
    else
        queue[++rear] = elem;
}

int Queue::dequeue(bool *success) {
    *success = true;
    if (is_empty()) {
        *success = false;
        return 0;
    } else if (rear == 0) {
        rear = -1;
        return queue[0];
    } else {
        int to_ret = queue[0];
        for (short i = 0; i < rear; i++)
            queue[i] = queue[i+1];
        rear--;
        return to_ret;
    }
}

int Queue::peek(bool *success) {
    return (*success = !is_empty()) ? queue[0]: 0;
}