#include <fstream>
#include <iostream>
#include <list>

using namespace std;
class Graph {        // định nghĩa lớp Graph
    int V;           // tập đỉnh V của đồ thị
    list<int> *adj;  // con trỏ đến mảng các danh sách kề
   public:
    Graph(int V);                // Constructor của lớp
    void addEdge(int v, int w);  // thêm một cạnh vào đồ thị
    void printGraph();           // in ra danh sách kề
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);  // thêm đỉnh w vào list(v).
    adj[w].push_back(v);  // Đồ thị vô hướng: thêm đỉnh v vào list(w).
}

void Graph::printGraph() {
    int v;
    list<int>::iterator i;
    for (v = 1; v < V; ++v) {
        cout << "\n Danh sách kề của đỉnh " << v << "\n head ";
        for (i = adj[v].begin(); i != adj[v].end(); ++i) cout << "-> " << *i;
        cout << endl;
    }
}