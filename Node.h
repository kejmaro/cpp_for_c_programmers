#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include "Edge.h"

class Node {
    int id, value;
    std::vector<Edge> edges;

    friend std::ostream& operator<< (std::ostream& out, const Node& node);

public:
    Node(int id);
    bool is_connected(Node& other);
    void add_edge(Node& dst, int cost);
    void set_value(int value);
    int get_value() const;
    bool operator < (const Node& node) const;
    bool operator == (const Node& node) const;
    int get_id() {
        return id;
    }
    std::vector<Edge>& get_edges() {
        return edges;
    }
    static void print_nodes(const std::vector<Node>& nodes);
};
#endif // NODE_H
