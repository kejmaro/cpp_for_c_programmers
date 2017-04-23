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
    std::vector<Node> neighbours(int node_id);
    void Dijkstra_shortest_path();
};
