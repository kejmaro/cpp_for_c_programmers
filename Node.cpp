#include "Node.h"
using namespace std;

Node::Node(int id) : id(id), value(0) {
    edges = std::vector<Edge>();
}
/* DEBUG stuff
Node::~Node() {
    cout << "*** ~Node() id: " << id << " " << this << " edges: " << &edges << endl;
}

Node::Node(const Node& other) : id(other.id), value(other.value) {
    cout << "*** Copy constructor of: " << other.id << endl;
    edges = other.edges;
    cout << "other.edges: " << &(other.edges) << " | edges: " << &edges << endl;
}
*/
bool Node::is_connected(Node& other) {
    // no loops
    if (this == &other) {
        return true;
    }
    
    // go through each edge of the node
    for(vector<Edge>::const_iterator it = edges.begin(); it != edges.end(); ++it) {
        // FIXME implement Node::equals
        if ((*it).dst == &other) {
            return true;
        }
    }

    return false;
}

void Node::add_edge(Node& dst, int cost) {
    edges.push_back(Edge(&dst, cost));
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

void Node::print_nodes(const vector<Node>& nodes) {
    for(vector<Node>::const_iterator it = nodes.begin(); it != nodes.end(); ++it) {
        cout << *it;
    }
}

bool Node::operator< (const Node& node) const {
    // FIXME add comment (having best available by back())
    return (value > node.get_value());
}

bool Node::operator== (const Node& node) const {
    return id == node.id;
}
