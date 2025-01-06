// https://cp-algorithms.com/graph/mst_prim.html

#include<bits/stdc++.h>
using namespace std;

int n = 9;
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

    adj[0][1] = 4;
    adj[0][7] = 8;
    adj[1][0] = 4;
    adj[1][2] = 8;
    adj[1][7] = 11;
    adj[2][1] = 8;
    adj[2][3] = 7;
    adj[2][5] = 4;
    adj[2][8] = 2;
    adj[3][2] = 7;
    adj[3][4] = 9;
    adj[3][5] = 14;
    adj[4][3] = 9;
    adj[4][5] = 10;
    adj[5][2] = 4;
    adj[5][3] = 14;
    adj[5][4] = 10;
    adj[5][6] = 2;
    adj[6][5] = 2;
    adj[6][7] = 1;
    adj[6][8] = 6;
    adj[7][0] = 8;
    adj[7][1] = 11;
    adj[7][6] = 1;
    adj[7][8] = 7;
    adj[8][2] = 2;
    adj[8][6] = 6;
    adj[8][7] = 7;

    prim();
}
