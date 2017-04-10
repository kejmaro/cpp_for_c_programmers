#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
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
    // vector<Node> open_set = vector<Node>();
    priority_queue<Node, vector<Node>, compare_nodes> open_set;
    vector<Node> close_set = vector<Node>();
    
    nodes[0].set_value(3);
    nodes[1].set_value(1);
    nodes[2].set_value(5);
    open_set.push(nodes[0]);
    open_set.push(nodes[1]);
    open_set.push(nodes[2]);
    // sort(open_set.begin(), open_set.end());
    // for(vector<Node>::const_iterator it = open_set.begin(); it != open_set.end(); ++it) {
    //     cout << (*it).get_value() << " ";
    // }
    // cout << endl;
    cout << " -- open_set print out --" << endl;
    while (!open_set.empty()) {
        cout << open_set.top();
        open_set.pop();
    }
}

ostream& operator<< (ostream& out, const Graph& graph) {
    for(unsigned int i = 0; i < graph.nodes.size(); i++) {
        out << graph.nodes[i];
    }
    return out;
}

Node::Node(int id) : id(id), value(0) {
    edges = std::vector<Edge>();
}

bool Node::is_connected(Node& other) {
    // no loops
    if (this == &other) {
        return true;
    }
    
    // go through each edge of the node
    for(vector<Edge>::const_iterator it = edges.begin(); it != edges.end(); ++it) {
        if ((*it).get_dst() == other.id) {
            return true;
        }
    }

    return false;
}

void Node::add_edge(Node& dst, int cost) {
    edges.push_back(Edge(dst.id, cost));
}

void Node::set_value(int value) {
    this->value = value;
}

int Node::get_value() const {
    return value;
}

ostream& operator<< (ostream& out, const Node& node) {
    out << "node " << node.id << ":";
    for(vector<Edge>::const_iterator it = node.edges.begin(); it != node.edges.end(); ++it) {
        out << *it;
    }
    out << endl;
    return out;
}

bool Node::operator< (const Node& node) const {
    return (value < node.get_value());
}
 
ostream& operator<< (ostream& out, const Edge& edge) {
    out << " -> " << edge.dst << "(" << edge.value << ")";
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
