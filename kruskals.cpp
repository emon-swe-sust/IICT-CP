#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool edgeComp (Edge a, Edge b) {
    return a.w < b.w;
}

int n = 6, numberOfEdges = 9;
vector<Edge> edges;
vector<int> tree_id(n);
vector<Edge> result;

void kruskals() {
    int cost = 0;
    for (int i = 0; i < n; i++)
        tree_id[i] = i;

    sort(edges.begin(), edges.end(), edgeComp);

    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.w;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }

    for(int i=0; i < n-1; i++) {
        cout << result[i].u << " " << result[i].v << " " << result[i].w << endl;
    }
}

int main() {
    int u, v, w;
    for(int i=0; i<numberOfEdges; i++) {
        cin >> u >> v >> w;
        Edge e;
        e.u = u;
        e.v = v;
        e.w = w;
        edges.push_back(e);
    }

    kruskals();
}

// 4 3 9
// 4 0 4
// 0 3 1
// 3 2 5
// 3 1 3
// 0 1 2
// 1 2 3
// 2 5 8
// 1 5 7
