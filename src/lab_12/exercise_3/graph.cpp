#include <bits/stl_pair.h>
#include <bits/stl_algo.h>
#include <queue>

#include "graph.hpp"


bool Graph::insert_vertex(int vertex) {
    if (search(vertex)) return false;

    adjacency_list[vertex] = std::unordered_map<int, unsigned>();
    nodes++;

    return true;
}

bool Graph::insert_edge(int vertex1, int vertex2, unsigned weight) {
    if (!search(vertex1) || !search(vertex2)) return false;

    adjacency_list[vertex1][vertex2] = adjacency_list[vertex2][vertex1] = weight;
    edges++;

    return true;
}

bool Graph::search(int node) {
    return adjacency_list.find(node) != adjacency_list.end();
}

bool Graph::del(int node) {
    if (!search(node)) return false;

    std::unordered_map<int, unsigned> to_rm = adjacency_list.at(node);
    for (auto pair : to_rm) adjacency_list[pair.first].erase(node);

    adjacency_list.erase(node);

    nodes--;
    return true;
}

void Graph::display(void) {
    for (auto pair : adjacency_list) {
        std::cout << pair.first << " -> [ ";
        for (auto pair1 : pair.second) std::cout << "(" << pair1.first << ", weight=" << pair1.second << "), ";
        std::cout << "]" << std::endl;
    }
}

std::vector<EdgeInfo> Graph::prim_mst(void) {
    std::vector<EdgeInfo> mst;
    std::unordered_set<int> visited;
    std::priority_queue<EdgeInfo, std::vector<EdgeInfo>, std::greater<EdgeInfo>> pq;

    EdgeInfo edge;
    int vertex = adjacency_list.cbegin()->first;
    visited.insert(vertex);

    for (const auto &pair : adjacency_list[vertex]) {
        pq.emplace(vertex, pair.first, pair.second);
    }

    while (!pq.empty() && visited.size() < nodes) {
        edge = pq.top();
        pq.pop();

        if (visited.count(edge.vertex1) && visited.count(edge.vertex2)) {
            continue;
        }

        mst.push_back(edge);

        vertex = visited.count(edge.vertex1) ? edge.vertex2 : edge.vertex1;
        visited.insert(vertex);

        for (const auto &pair : adjacency_list[vertex]) {
            if (!visited.count(pair.first)) {
                pq.emplace(vertex, pair.first, pair.second);
            }
        }
    }

    return mst;
}

// Disjoint set helper functions
int find(std::unordered_map<int, int> &parent, int v) {
    if (parent[v] != v) {
        parent[v] = find(parent, parent[v]);
    }
    return parent[v];
}

bool union_sets(std::unordered_map<int, int> &parent,
    std::unordered_map<int, int> &rank,
    int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a != b) {
        if (rank[a] < rank[b]) std::swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) ++rank[a];
        return true;
    }
    return false;
}

std::vector<EdgeInfo> Graph::kruskal_mst(void) {
    std::vector<EdgeInfo> mst;
    std::priority_queue<EdgeInfo, std::vector<EdgeInfo>, std::greater<EdgeInfo>> pq;

    EdgeInfo edge;

    // Disjoint set structures for detecting cycles
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> rank;

    for (const auto &pair : adjacency_list) {
        parent[pair.first] = pair.first;
        rank[pair.first] = 0;
    }

    for (const auto &pair : adjacency_list) {
        for (const auto &pair1 : pair.second) {
            if (pair.first < pair1.first) pq.emplace(pair.first, pair1.first, pair1.second);
        }
    }

    while (!pq.empty() && mst.size() < nodes - 1) {
        edge = pq.top();
        pq.pop();

        if (union_sets(parent, rank, edge.vertex1, edge.vertex2)) {
            mst.push_back(edge);
        }
    }

    return mst;
}

std::vector<EdgeInfo> Graph::dijkstra(int src, int dest) {
    if (!(adjacency_list.count(src) && adjacency_list.count(dest)) || src == dest) return {};

    std::unordered_set<int> explored;
    std::unordered_map<int, std::pair<unsigned, int>> path; // map nodes to least path length and backpointer for backtracking
    std::priority_queue<EdgeInfo, std::vector<EdgeInfo>, std::greater<EdgeInfo>> pq;

    path[src] = { 0, src };

    EdgeInfo edge;
    pq.emplace(src, src, 0);

    while (!pq.empty() && explored.size() < nodes) {
        edge = pq.top();
        pq.pop();

        if (explored.count(edge.vertex2)) continue;

        for (const auto &pair : adjacency_list[edge.vertex2]) {
            auto tmp = std::make_pair(edge.weight + pair.second, edge.vertex2);
            if (path.find(pair.first) != path.end() && path[pair.first].first < tmp.first) continue;

            path[pair.first] = tmp;
            pq.emplace(edge.vertex2, pair.first, tmp.first);
        }

        explored.insert(edge.vertex2);
    }

    if (!path.count(dest)) return {};


    std::vector<EdgeInfo> result;
    edge = EdgeInfo(path[dest].second, dest, path[dest].first);
    result.push_back(edge);
    while (edge.vertex1 != src) {
        edge = EdgeInfo(path[edge.vertex1].second, edge.vertex1, path[edge.vertex1].first);
        result.push_back(edge);
    }

    std::reverse(result.begin(), result.end());

    return result;
}