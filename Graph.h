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
};

class compare_nodes {
public:
    bool operator() (const Node& node1, const Node& node2) {
        // negation is used to have the shortest Node at the top of PQ
        return !(node1 < node2);
    }
};

class Graph {
    std::vector<Node> nodes;

    void generate_edges(float density, int range);
    float prob();
    void add_edge(Node& node_a, Node& node_b, int range);
    int generate_cost(int range);

    friend std::ostream& operator<< (std::ostream& out, const Graph& graph);

public:
    Graph(int size = 5, float density = 0.3, int range = 10);
    bool adjacent(int node1_id, int node2_id);
    void neighbours(int node_id);
    void Dijkstra_shortest_path();
};

