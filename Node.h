class Edge {
    int dst;
    int value;

    friend std::ostream& operator<< (std::ostream& out, const Edge& edge);

public:
    Edge(int dst_id, int cost) : dst(dst_id), value(cost) {
    }

    int get_dst() const {
        return dst;
    }
};

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
    bool operator< (const Node& node) const;
    bool operator== (const Node& node) const;
};
