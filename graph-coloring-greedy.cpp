// the max number of color will be (d + 1); where d is the max degree of a node. 

#include <iostream>
#include <vector>
using namespace std;

struct Graph {
    int V;       // number of vertex               
    vector<vector<int>> adj;
};

void createGraph(Graph& g, int V) {
    g.V = V;
    g.adj.resize(V);
}

void addEdge(Graph& g, int v, int w) {
    g.adj[v].push_back(w);
    g.adj[w].push_back(v);
}

void greedyColoring(Graph& g) {
    int V = g.V;
    vector<int> result(V, -1);
    result[0] = 0;


    for (int u = 1; u < V; u++) {
        vector<bool> available(V, false);

        for (int neighbor : g.adj[u]) {
            if (result[neighbor] != -1) {
                available[result[neighbor]] = true;
            }
        }

        int cr;
        for (cr = 0; cr < V; cr++) {
            if (!available[cr]) {
                break;
            }
        }

        result[u] = cr;
    }

    for (int u = 0; u < V; u++) {
        cout << "Vertex " << u << " ---> Color " << result[u] << endl;
    }
}

int main() {
    Graph g1;
    createGraph(g1, 5);
    addEdge(g1, 0, 1);
    addEdge(g1, 0, 2);
    addEdge(g1, 1, 2);
    addEdge(g1, 1, 3);
    addEdge(g1, 2, 3);
    addEdge(g1, 3, 4);
    cout << "Coloring of graph 1 \n";
    greedyColoring(g1);

    Graph g2;
    createGraph(g2, 5);
    addEdge(g2, 0, 1);
    addEdge(g2, 0, 2);
    addEdge(g2, 1, 2);
    addEdge(g2, 1, 4);
    addEdge(g2, 2, 4);
    addEdge(g2, 4, 3);
    cout << "\nColoring of graph 2 \n";
    greedyColoring(g2);

    return 0;
}