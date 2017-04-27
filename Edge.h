#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Node; // forward declaration

class Edge {

    friend std::ostream& operator<< (std::ostream& out, const Edge& edge);

public:
    Node* dst;
    int value;

    Edge(Node* dst, int cost);
};
#endif // EDGE_H
