/*
 * @file dequeue_sll.cpp
 * @brief Implement a dequeue ADT using a singly linked list
 * @details The queue must implement the following operations
 * i) Enqueue back
 * ii) Enqueue front
 * iii) Dequeue front
 * iv) Dequeue back
 * v) Peek
*/

#include "dequeue_sll.hpp"

bool Dequeue::is_empty(void) {
    return front == nullptr;
}

void Dequeue::enqueue_back(char elem, bool *success) {
    *success = true;
    Node *new_node = new Node {elem, nullptr};
    if (new_node == nullptr)
        *success == false;
    else if (is_empty())
        front = rear = new_node;
    else
        rear = rear->next = new_node;
}

void Dequeue::enqueue_front(char elem, bool *success) {
    *success = true;
    Node *new_node = new Node {elem, front};
    if (new_node == nullptr)
        *success = false;
    else
        front = new_node;
}

char Dequeue::dequeue_front(bool *success) {
    if (!(*success = !is_empty()))
        return 0;

    int to_ret = front->val;
    Node *to_del = front;
    rear = rear == front ? nullptr : rear;
    front = front->next;
    delete to_del;

    return to_ret;
}

char Dequeue::dequeue_back(bool *success) {
    if (!(*success = !is_empty()))
        return 0;

    int to_ret = rear->val;
    Node *to_del = rear;
    
    if (front == rear) {
        front = rear = nullptr;
    } else {
        Node *iter = front;
        while (iter->next != rear)
            iter = iter->next;
        rear = iter;
    }

    delete to_del;
    return to_ret;
}

char Dequeue::peek(bool *success) {
    return (*success = !is_empty()) ? front->val: 0;
}