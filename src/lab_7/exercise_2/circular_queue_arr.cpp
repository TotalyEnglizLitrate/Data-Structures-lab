/*
 * @file circular_queue_arr.cpp
 * @brief Implement a circular queue ADT using a fixed length integer array of length LENGTH
 * @details The queue must implement the following operations
 * i) Enqueue
 * ii) Dequeue
 * iii) Peek
*/


#include "circular_queue_arr.hpp"

bool Queue::is_empty(void) {
    return rear == -1;
}

bool Queue::is_full(void) {
    return rear == (front - 1) % LENGTH;
}

void Queue::enqueue(int elem, bool *success) {
    *success = true;

    if (is_full()) {
        *success = false;
    } else if (is_empty()) {
        front = rear = 1;
        queue[rear] = elem;
    } else {
        rear = (rear + 1) % LENGTH;
        queue[rear] = elem;
    }
}

int Queue::dequeue(bool *success) {
    *success = true;
    int to_ret;

    if (is_empty()) {
        *success = false;
        to_ret = 0;
    } else if (front == rear) {
        to_ret = queue[front];
        front = rear = -1;
    } else {
        to_ret = queue[front];
        front = (front + 1) % 5;
    }

    return to_ret;
}

int Queue::peek(bool *success) {
    return (*success = !is_empty()) ? queue[front]: 0;
}