#include<bits/stdc++.h>
using namespace std;

void initial() {
    #ifndef LEETCODE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

vector<int> visited;

void dfs(int current, vector<vector<int>>& graph) {
    printf("visiting node %d \n", current);
    visited[current] = 1;

    for(int i = 0; i < graph[current].size(); i++) {
        if(graph[current][i] == 1 && visited[i] == 0) {
            dfs(i, graph);
        }
    }
}

int main() {
    initial();
    int numberOfNodes  = 9;
    int startingNode = 0;

    vector<vector<int>> graph = {{0, 1, 1, 1, 0, 0, 0, 0, 0},
                                 {1, 0, 0, 0, 1, 1, 0, 0, 0},
                                 {1, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 0, 0, 0, 0, 0, 0, 1, 1},
                                 {0, 1, 0, 0, 0, 0, 1, 0, 0},
                                 {0, 1, 0, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 0, 1, 1, 0, 0},
                                 {0, 0, 0, 1, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 1, 0, 0, 0, 0, 0}};

    visited.resize(numberOfNodes, 0);
    
    dfs(startingNode, graph);

    return 0;
}
