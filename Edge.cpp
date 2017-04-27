#include "Edge.h"
#include "Node.h"
using namespace std;

/* DEBUG stuff
Edge::~Edge() {
    cout << "*** ~Edge() dst: " << dst << " " << this << " ***" << endl;
}
*/
Edge::Edge(Node* dst, int cost) : dst(dst), value(cost) {
}

ostream& operator<< (ostream& out, const Edge& edge) {
    Node dst = *(edge.dst);
    out << " -> " << dst.get_id() << "(" << edge.value << ")";
    return out;
}
