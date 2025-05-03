#include <iostream>

#include "graph.hpp"

using namespace std;

/*
 * @brief Menu function to handle user input
 * @details Takes user input and performs appropriate operations, printing success or
 * failure states to the console
 * @param graph Pointer to the Graph being modified
 */
void menu(Graph *graph);

/*
 * @brief Main function
 * @details Initializes the HashMap and defers to the menu function for operations
 * @return Return is handled via exit in menu
 */
int main(void) {
    Graph *graph = new Graph();
    while (true)
        menu(graph);
}

void menu(Graph *graph) {
    cout
        << "1. Insert vertex" << endl
        << "2. Insert edge" << endl
        << "3. Delete" << endl
        << "4. Search" << endl
        << "5. Display" << endl
        << "6. Construct MST using Prim's algorithm" << endl
        << "7. Construct MST using Kruskal's algorithm" << endl
        << "8. Find shortest path using Dijkstra's algorithm" << endl
        << "0. Exit" << endl
        << "Enter choice: ";

    unsigned choice;
    int vertex, vertex1;
    unsigned weight;
    char ans;
    bool success;
    cin >> choice;

    switch (choice) {
    case 0:
        delete graph;
        exit(0);

    case 1:
        cout << "Enter value to insert: ";
        cin >> vertex;
        success = graph->insert_vertex(vertex);
        if (success)
            cout << "Value inserted: " << vertex << endl;
        else
            cout << "Value already in graph!" << endl;

        break;

    case 2:
        cout << "Enter value of first vertex: ";
        cin >> vertex1;
        cout << "Enter value of second vertex: ";
        cin >> vertex;
        cout << "Enter weight of edge: ";
        cin >> weight;
        success = graph->insert_edge(vertex1, vertex, weight);
        if (success)
            cout << "Edge inserted" << endl;
        else
            cout << "One or both vertices do not exist!" << endl;
        break;

    case 3:
        cout << "Enter value to delete: ";
        cin >> vertex;
        success = graph->del(vertex);
        if (success)
            cout << "Value deleted: " << endl;
        else
            cout << "Value not in graph!" << endl;
        break;

    case 4:
        cout << "Enter value to search for: ";
        cin >> vertex;
        success = graph->search(vertex);
        if (success)
            cout << "Vertex in graph" << endl;
        else
            cout << "Vertex not in graph" << endl;
        break;

    case 5:
        graph->display();
        break;

    case 6:
        cout << "Constructing MST using Prim's algorithm..." << endl;
        graph->prim_mst();
        cout << "MST constructed!" << endl;
        for (auto edge : graph->prim_mst()) {
            edge.display();
            cout << endl;
        }
        break;

    case 7:
        cout << "Constructing MST using Kruskal's algorithm..." << endl;
        graph->kruskal_mst();
        cout << "MST constructed!" << endl;
        for (auto edge : graph->kruskal_mst()) {
            edge.display();
            cout << endl;
        }
        break;

    case 8:
        cout << "Enter source vertex: ";
        cin >> vertex1;
        cout << "Enter destination vertex: ";
        cin >> vertex;
        cout << "Finding shortest path using Dijkstra's algorithm..." << endl;
        graph->dijkstra(vertex1, vertex);
        cout << "Shortest path found!" << endl;
        weight = 0;
        for (auto edge : graph->dijkstra(vertex1, vertex)) {
            weight += (edge.weight -= weight);
            edge.display();
            cout << endl;
        }
        cout << "Cumulative weight of path: " << weight << endl;
        break;

    default:
        cout << "Invalid input! please try again" << endl;
    }


    cout << endl << endl;
}