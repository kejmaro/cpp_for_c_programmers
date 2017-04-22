#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.h"
#include "PriorityQueue.h"
using namespace std;

PriorityQueue::PriorityQueue() {
    nodes = vector<Node>();
}

bool PriorityQueue::contains(Node& node) {
    return find(nodes.begin(), nodes.end(), node) != nodes.end();
}

void PriorityQueue::push(Node& node) {
    nodes.push_back(node);
    sort_container();
}

void PriorityQueue::sort_container() {
    sort(nodes.begin(), nodes.end());
}

Node& PriorityQueue::get_top() {
    return *(nodes.begin());
}

ostream& operator<< (ostream& out, const PriorityQueue& pq) {
    for(vector<Node>::const_iterator it = pq.nodes.begin(); it != pq.nodes.end(); ++it) {
        out << *it;
    }
    return out;
}
