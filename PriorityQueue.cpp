#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.h"
#include "PriorityQueue.h"
using namespace std;

PriorityQueue::PriorityQueue(vector<Node>& nodes) : nodes(nodes){
    sort_container();
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

int PriorityQueue::get_top_id() {
    Node& best = nodes.back();
    int top_id = best.get_id();
    nodes.pop_back();
    return top_id;
}

ostream& operator<< (ostream& out, const PriorityQueue& pq) {
    for(vector<Node>::const_iterator it = pq.nodes.begin(); it != pq.nodes.end(); ++it) {
        out << *it;
    }
    return out;
}
