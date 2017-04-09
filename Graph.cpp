#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graph.h"
using namespace std;

Graph::Graph(int size, float density) : size(size) {
    // seed RNG
    srand(time(0));

    // create 2D array of booleans on heap
    graph = new bool*[size];
    for(int i = 0; i < size; ++i)
    {
        this->graph[i] = new bool[size];
    }

    // initialize vertices
    for(int i = 0; i < size; ++i) {

        // graph is simmetric, thus j = i
        for(int j = i; j < size; ++j) {
            if (i == j) {
                // no loops
                graph[i][j] = false;
            } else {
                graph[i][j] = graph[j][i] = (prob() < density);
            }
        }
    }
}

float Graph::prob() {
    return (float)(rand() % 100 + 1) / 100;
}

Graph::~Graph() {
    // delete graph's rows...
    for(int i = 0; i < size ; ++i) {
        delete []graph[i];
    }

    // ... and finally the graph
    delete []graph;
}

ostream& operator<< (ostream& out, const Graph& graph) {
    for(int i = 0; i < graph.size; ++i) {
        for(int j = 0; j < graph.size ; ++j) {
            out << graph.graph[i][j] << " ";
        }
        out << endl;
    }

    return out;
}

bool Graph::is_connected() {
    int old_size = 0, c_size = 0;
    // init data structures
    bool* close = new bool[size];
    bool* open = new bool[size];
    for(int i = 0; i < size; ++i) {
        open[i] = close[i] = false;
    }

    // place first node in the open set so that it is automatically moved to
    // the closed set at the beginning of algorithm's execution
    open[0] = true;

    while ( c_size < size ) {
        for(int i = 0; i < size; ++i) {
            // needed for exit condition
            old_size = c_size;
            
            // move node i from the open set (if it's already there) to the closed one
            if (open[i] && (close[i] == false)) {
                close[i] = true;
                c_size++;

                // populate open set with nodes reachable from node i
                for(int j = 0; j < size; ++j) {
                    open[j] = open[j] || graph[i][j];
                }
            }
        }

        // check exit conditions
        if ( c_size == size ) {
            return true;
        }

        if ( old_size == c_size ) {
            return false;
        }
    }
    
    return false;
}

int main() {
    Graph graph(10, 0.3);
    cout << graph;
    cout << "graph is " << (graph.is_connected() ? "" : "NOT ") << "connected" << endl;
}
