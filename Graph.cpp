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
            } }
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

vector<Node> Graph::neighbours(int node_id) {
    vector<Edge>& edges = nodes[node_id].get_edges();
    vector<Node> neighbours;
    for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); ++it) {
        Edge& edge = *it;
        Node neighbour = nodes[edge.dst];
        neighbour.set_value(edge.value);
        neighbours.push_back(neighbour);
    }

    cout << "printing neighbours: " << endl;
    Node::print_nodes(neighbours);

    return neighbours;
}

void Graph::Dijkstra_shortest_path() {
    vector<Node> test = neighbours(0);
    PriorityQueue open_set = PriorityQueue(test);
    int top_id = open_set.get_top_id();
    cout << "top_id: " << top_id << endl;
    // PriorityQueue close_set;
    // close_set.push(nodes[top_id]);
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
    graph.Dijkstra_shortest_path();
}
