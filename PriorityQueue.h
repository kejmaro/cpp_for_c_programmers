class PriorityQueue {
    std::vector<Node> nodes;
    void sort_container();
    friend std::ostream& operator<< (std::ostream& out, const PriorityQueue& pq); 
public:
    PriorityQueue();
    bool contains(Node& node);
    void push(Node& node);
    Node& get_top();
};
