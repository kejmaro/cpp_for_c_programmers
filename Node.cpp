#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

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
    out << "id: " << node.id << " | value: " << node.value << " | edges:";
    for(vector<Edge>::const_iterator it = node.edges.begin(); it != node.edges.end(); ++it) {
        out << *it;
    }
    out << endl;
    return out;
}

bool Node::operator< (const Node& node) const {
    return (value < node.get_value());
}

bool Node::operator== (const Node& node) const {
    return id == node.id;
}
 
ostream& operator<< (ostream& out, const Edge& edge) {
    out << " -> " << edge.dst << "(" << edge.value << ")";
    return out;
}
