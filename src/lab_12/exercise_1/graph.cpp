#include <bits/stl_pair.h>
#include <iostream>

#include "graph.hpp"


bool Graph::insert(int node, std::unordered_set<int> &connections) {
    if (search(node)) return false;
 
    int key;
    unsigned val;
    bool chk;
    std::vector<bool> new_row;

    node_val_ref.insert(std::pair(node, nodes));
    adjacency_matrix.push_back(new_row);
    adjacency_matrix[nodes].resize(nodes);

    for (std::pair pair: node_val_ref) {
        key = pair.first;
        val = pair.second;
        chk = connections.find(key) == connections.end() ? false : true;
        adjacency_matrix[val].push_back(chk);
        adjacency_matrix[nodes][val] = chk;
    }
    adjacency_matrix[nodes][nodes++] = false;

    return true;
}

bool Graph::search(int node) {
    return node_val_ref.find(node) != node_val_ref.end();
}

bool Graph::del(int node) {
    if (!search(node)) return false;

    unsigned to_rm = node_val_ref.at(node);
    for (unsigned i = 0; i < nodes; i++) {
        adjacency_matrix[i].erase(adjacency_matrix[i].cbegin() + to_rm);
    }
    adjacency_matrix.erase(adjacency_matrix.cbegin() + to_rm);
    node_val_ref.erase(node);
    for (auto pair: node_val_ref) if (pair.second > to_rm) node_val_ref[pair.first]--;
    nodes--;
    return true;
}

void Graph::display(void) {
    int arr[nodes];
    for (auto pair: node_val_ref) arr[pair.second] = pair.first;
    
    std::cout << "  ";
    for (int i: arr) std::cout << i << ' ';
    std::cout << std::endl;
    
    for (unsigned i = 0; i < nodes; i++) {
        std::cout << arr[i]<< ' ';
        for (bool link: adjacency_matrix[i]) {
            std::cout << (link ? 1 : 0) << ' ';
        }
        std::cout << std::endl;
    }
}