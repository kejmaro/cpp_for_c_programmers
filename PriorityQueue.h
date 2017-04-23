class PriorityQueue {
    std::vector<Node>& nodes;
    void sort_container();
    void remove_node(Node& node);
    friend std::ostream& operator<< (std::ostream& out, const PriorityQueue& pq); 
public:
    PriorityQueue(std::vector<Node>& nodes);
    bool contains(Node& node);
    void push(Node& node);
    int get_top_id();
};
