/*
 * @file queue_sll.cpp
 * @brief Implement a queue ADT using a singly linked list
 * @details The queue must implement the following operations
 * i) Enqueue
 * ii) Dequeue
 * iii) Peek
*/

#include "queue_sll.hpp"

bool Queue::is_empty(void) {
    return front == nullptr;
}

void Queue::enqueue(int elem, bool *success) {
    *success = true;
    Node *new_node = new Node {elem, nullptr};
    if (new_node == nullptr)
        *success == false;
    else if (is_empty())
        front = rear = new_node;
    else
        rear = rear->next = new_node;
}

int Queue::dequeue(bool *success) {
    if (!(*success = !is_empty()))
        return 0;

    int to_ret = front->val;
    Node *to_del = front;
    rear = rear == front ? nullptr : rear;
    front = front->next;
    delete to_del;

    return to_ret;
}

int Queue::peek(bool *success) {
    return (*success = !is_empty()) ? front->val: 0;
}