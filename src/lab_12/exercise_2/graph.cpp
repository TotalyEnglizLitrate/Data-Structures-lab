#include <bits/stl_pair.h>
#include <iostream>

#include "graph.hpp"


bool Graph::insert(int node, std::unordered_set<int> &connections) {
    if (search(node)) return false;
 
    int key;
    std::unordered_set<int> conns;
    bool chk;
    std::unordered_set<int> new_row;

    adjacency_list.insert(std::pair(node, new_row));

    for (std::pair pair: adjacency_list) {
        key = pair.first;
        conns = pair.second;
        if (key == node) continue;
        if (connections.find(key) != connections.end()) {
            conns.insert(node);
            adjacency_list[node].insert(key);
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
    for (int i: to_rm) adjacency_list[i].erase(node);
    
    adjacency_list.erase(node);

    nodes--;
    return true;
}

void Graph::display(void) {
    for (auto pair: adjacency_list) {
        std::cout << pair.first << " -> [ ";
        for (int i: pair.second) std::cout << i << ", ";
        std::cout << "]" << std::endl;
    }
}