class Graph {
    public:
        Graph(int size = 10, float density = 0.4);
        ~Graph();
        bool is_connected();

    private:
        const int size;
        bool** graph;
        float prob(); 
        friend std::ostream& operator<< (std::ostream& out, const Graph& graph);
};
