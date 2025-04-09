#include <iostream>

#include "priority_queue.hpp"


bool is_pow2(unsigned n) { return (n > 0) && ((n & (n - 1)) == 0); }

void PriorityQueue::heapify_up(int index) {
    int parent_index = (index - 1) / 2;
    while (index > 0 && data[index] > data[parent_index]) {
        std::swap(data[index], data[parent_index]);
        index = parent_index;
        parent_index = (index - 1) / 2;
    }
}

void PriorityQueue::heapify_down(int index) {
    int leftChild_index, rightChild_index, largest_index;
    while (index < size) {
        leftChild_index = 2 * index + 1;
        rightChild_index = 2 * index + 2;
        largest_index = index;

        if (leftChild_index < size && data[leftChild_index] > data[largest_index])
            largest_index = leftChild_index;

        if (rightChild_index < size && data[rightChild_index] > data[largest_index])
            largest_index = rightChild_index;

        if (largest_index == index)
            break;

        std::swap(data[index], data[largest_index]);
        index = largest_index;
    }
}

void PriorityQueue::clear(void) {
    data.clear();
    size = 0;
}

bool PriorityQueue::insert(int value) {
    if (search(value))
        return false;

    if (size >= data.size())
        data.resize(size + 1);
    data[size++] = value;
    heapify_up(size - 1);

    return true;
}

bool PriorityQueue::remove(int value) {
    bool success;
    unsigned idx = _search(value, &success);
    if (!success)
        return false;
    return _remove(idx);
}

bool PriorityQueue::_remove(unsigned idx) {
    if (idx >= size)
        return false;
    data[idx] = data[--size];
    heapify_down(idx);
    return true;
}

bool PriorityQueue::is_empty(void) const { return size == 0; }

void PriorityQueue::print(void) {
    for (unsigned i = 0; i < size; i++) {
        std::cout << data[i];
        if (is_pow2(i + 2) || i == size - 1)
            std::cout << std::endl;
        else
            std::cout << " ";
    }
}

unsigned PriorityQueue::_search(int elem, bool *success) {
    *success = true;
    for (unsigned i = 0; i < size; i++) {
        if (data[i] == elem)
            return i;
    }

    return (*success = false);
}

bool PriorityQueue::search(int elem) {
    bool success;
    _search(elem, &success);
    return success;
}

std::vector<int> PriorityQueue::sort(void) {
    unsigned originalSize = size;
    std::vector<int> originalData = data;

    std::vector<int> sorted;
    while (size > 0) {
        sorted.push_back(data[0]);
        _remove(0);
    }

    size = originalSize;
    data = originalData;

    return sorted;
}