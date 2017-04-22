#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Node.h"
#include "PriorityQueue.h"
#include "Graph.h"
using namespace std;

Graph::Graph(int size, float density, int range) {
    // seed RNG
    // srand(time(0));
    srand(0);

    // initialize vector of Nodes
    nodes = vector<Node>();
    for(int i = 0; i < size; i++) {
        nodes.push_back(Node(i));
    }

    generate_edges(density, range);
}

void Graph::generate_edges(float density, int range) {
    for(vector<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        Node& node = *it;
        for(unsigned int i = 0; i < nodes.size(); i++) {
            if (!(node.is_connected(nodes[i]))) {
                if (prob() < density) {
                    add_edge(node, nodes[i], range);
                }
            }
        }
    }
}

float Graph::prob() {
    return (float)(rand() % 100 + 1) / 100; 
}

void Graph::add_edge(Node& node_a, Node& node_b, int range) {
    int cost = generate_cost(range);
    node_a.add_edge(node_b, cost);
    node_b.add_edge(node_a, cost);
}

int Graph::generate_cost(int range) { 
    return rand() % range + 1; 
}

bool Graph::adjacent(int node1_id, int node2_id) {
    return nodes[node1_id].is_connected(nodes[node2_id]);
}

void Graph::neighbours(int node_id) {
    cout << nodes[node_id];
}

void Graph::Dijkstra_shortest_path() {
    nodes[0].set_value(3);
    nodes[1].set_value(1);
    nodes[2].set_value(5);
    PriorityQueue open_set;
    open_set.push(nodes[0]);
    open_set.push(nodes[1]);
    open_set.push(nodes[2]);
    cout << " -- open_set print out --" << endl;
    cout << open_set;
    cout << "open_set.contains(nodes[0]): " << open_set.contains(nodes[0]) << endl;
    cout << "open_set.contains(nodes[4]): " << open_set.contains(nodes[4]) << endl;
    cout << "open_set.get_top(): " << open_set.get_top();
}

ostream& operator<< (ostream& out, const Graph& graph) {
    for(unsigned int i = 0; i < graph.nodes.size(); i++) {
        out << graph.nodes[i];
    }
    return out;
}

int main(int argc, char* argv[]) {
    Graph graph = argc > 1 ? Graph(atoi(argv[1]), atof(argv[2])) : Graph();
    cout << graph;
    cout << "graph.adjacent(0,3): " << graph.adjacent(0,3) << endl;
    cout << "graph.adjacent(0,1): " << graph.adjacent(0,1) << endl;
    graph.neighbours(0);
    graph.Dijkstra_shortest_path();
}
