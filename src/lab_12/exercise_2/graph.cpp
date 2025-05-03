#include <bits/stl_pair.h>
#include <iostream>

#include "graph.hpp"


bool Graph::insert(int node, std::unordered_set<int> &connections) {
    if (search(node)) return false;

    int key;
    std::unordered_set<int> conns;
    std::unordered_set<int> new_row;

    adjacency_list[node] = new_row;

    for (int i : connections) {
        if (adjacency_list.find(i) != adjacency_list.end()) {
            adjacency_list[i].insert(node);
            adjacency_list[node].insert(i);
        }
    }
    nodes++;

    return true;
}

bool Graph::search(int node) {
    return adjacency_list.find(node) != adjacency_list.end();
}

bool Graph::del(int node) {
    if (!search(node)) return false;

    std::unordered_set<int> to_rm = adjacency_list.at(node);
    for (int i : to_rm) adjacency_list[i].erase(node);

    adjacency_list.erase(node);

    nodes--;
    return true;
}

void Graph::display(void) {
    for (auto pair : adjacency_list) {
        std::cout << pair.first << " -> [ ";
        for (int i : pair.second) std::cout << i << ", ";
        std::cout << "]" << std::endl;
    }
}