#include <bits/stdc++.h>
using namespace std;

#define V 9

int G[V][V] = { 
            {0, 4, 0, 0, 0, 0, 0, 8 ,0},
            {4, 0, 8, 0, 0, 0, 0, 11 ,0} ,
            {0, 8, 0, 7, 0, 4, 0, 0 ,2} ,
            {0, 0, 7, 0, 9, 14, 0, 0 ,0} ,
            {0, 0, 0, 9, 0, 10, 0, 0 ,0} ,
            {0, 0, 4, 14, 10, 0, 2, 0 ,0} ,
            {0, 0, 0, 0, 0, 2, 0, 1 ,6} ,
            {8, 11, 0, 0, 0, 0, 1, 0 ,7} ,
            {0, 0, 2, 0, 0, 0, 6, 7 ,0} 
          };

int main() {
  int numberOfEdges = 0;

  int visited[V];

  memset(visited, false, sizeof(visited));

  numberOfEdges = 0;

  visited[0] = true;

  int x;
  int y;

  while (numberOfEdges < V - 1) {

    int min = INT_MAX;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (visited[i]) {
        for (int j = 0; j < V; j++) {
          if (!visited[j] && G[i][j]) { 
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << G[x][y];
    cout << endl;
    visited[y] = true;
    numberOfEdges++;
  }

  return 0;
}