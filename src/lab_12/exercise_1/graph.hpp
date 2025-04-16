#include <vector>
#include <unordered_map>
#include <unordered_set>

class Graph {
private:
    unsigned nodes;
    std::vector<std::vector<bool>> adjacency_matrix;
    std::unordered_map<int, unsigned> node_val_ref;
public:
    Graph(void) : nodes(0) {}

    /*
     * @brief Inserts a new node into the graph
     * @param node Integer value of new node
     * @param connections set of integers the given node is connected to
     * @return boolean flag indicating success/failure
     */
    bool insert(int node, std::unordered_set<int> &connections);

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
     * @brief Function to display adjacency matrix used to represent the graph internally
     */
    void display(void);
};