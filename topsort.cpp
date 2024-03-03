#include<bits/stdc++.h>
using namespace std;

void dfs(int v, vector<bool> &visited, vector<int> &ans, vector<vector<int>> adj) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u, visited, ans, adj);
    }
    ans.push_back(v);
}

void topological_sort(int n, vector<bool> &visited, vector<int> &ans, vector<vector<int>> adj) {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, visited, ans, adj);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
    int n = 5;
    vector<vector<int>> adj(n);
    vector<bool> visited;
    vector<int> ans;

    adj[0] = {1,3,4};
    adj[1] = {2,3};
    adj[2] = {};
    adj[3] = {4};
    adj[4] = {};

    topological_sort(n, visited, ans, adj);

    for(int i=0; i<n; i++) {
        cout << ans[i] << " "; 
    }
    return 0;
}
