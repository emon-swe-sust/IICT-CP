// https://cp-algorithms.com/graph/mst_prim.htm
#include<bits/stdc++.h>
using namespace std;

int n = 6;
vector<vector<int>> adj;
int INF = 1000000000;

struct Edge {
    int w = INF, to = -1;
};

void prim() {
    int total_weight = 0;
    vector<bool> visited(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (v == -1 || min_e[j].w < min_e[v].w)){
                v = j;
            }
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        visited[v] = true;
        total_weight += min_e[v].w;

        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    cout << total_weight << endl;

    for(int k=0; k<n; k++) {
        cout << k << " " << min_e[k].w << " " << min_e[k].to << endl;
    }
}

int main() {
    adj.resize(n, vector<int>(n, INF));

    adj[0][1] = 2;
    adj[0][3] = 1;
    adj[0][4] = 4;
    adj[1][0] = 2;
    adj[1][3] = 3;
    adj[1][2] = 3;
    adj[1][5] = 7;
    adj[2][1] = 3;
    adj[2][5] = 8;
    adj[2][3] = 5;
    adj[3][4] = 9;
    adj[3][0] = 1;
    adj[3][1] = 3;
    adj[3][2] = 5;
    adj[4][0] = 4;
    adj[4][3] = 9;
    adj[5][1] = 7;
    adj[5][2] = 8;

    prim();
}
