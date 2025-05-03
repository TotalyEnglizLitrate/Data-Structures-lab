#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class EdgeInfo {
public:
    int vertex1, vertex2;
    unsigned weight;
    EdgeInfo(void) : vertex1(0), vertex2(0), weight(0) {}
    EdgeInfo(int vertex1, int vertex2, unsigned weight) : vertex1(vertex1), vertex2(vertex2), weight(weight) {}

    /*
     * @brief Implement > for class
     * @param other Other instance of EdgeInfo to compare with
     * @return bool
     */
    bool operator>(const EdgeInfo &other) const {
        return weight > other.weight;
    }

    /*
     * @brief Display vertices and weight of edge
     * @return void
     */
    void display() const {
        std::cout << vertex1 << " <—" << weight << "—> " << vertex2;
    }
};

class Graph {
private:
    unsigned nodes, edges;
    std::unordered_map<int, std::unordered_map<int, unsigned>> adjacency_list; // map node -> map of connected nodes and their weights
public:
    Graph(void) : nodes(0), edges(0) {}


    /*
     * @brief Inserts a new vertex without any connections into the graph
     * @param vertex Integer value of new vertex
     * @return boolean flag indicating success/failure
    */
    bool insert_vertex(int vertex);

    /*
     * @brief Insert a new edge/Update existing edge between two (pre existing) vertices
     * @param vertex1 Integer value of first vertex
     * @param vertex2 Integer value of second vertex
     * @param weight Weight associated with edge
     * @return boolean flag indicating success/failure
    */
    bool insert_edge(int vertex1, int vertex2, unsigned weight);


    /*
     * @brief Searches for a given node in the graph
     * @param node Integer value of node to search for
     * @return boolean flag indicating prescense/absence of node
     */
    bool search(int node);

    /*
     * @brief Deletes a given node from the graph
     * @param node Integer value of node to delete
     * @return boolean flag indicating success/failure
     */
    bool del(int node);

    /*
     * @brief Function to display adjacency list used to represent the graph internally
     */
    void display(void);

    /*
     * @brief Generate mst using Prim's algorithm
     * @return vector of edges in the mst
     */
    std::vector<EdgeInfo> prim_mst(void);

    /*
     * @brief Generate mst using Kruskal's algorithm
     * @return vector of edges in the mst
     */
    std::vector<EdgeInfo> kruskal_mst(void);

    /*
     * @brief Get the shortest path between two vertices (using Dijkstra's algorithm)
     * @param src Integer value of source vertex
     * @param dest Integer value of destination vertex
     * @return vector of edges in the shortest path
     */
    std::vector<EdgeInfo> dijkstra(int src, int dest);
};