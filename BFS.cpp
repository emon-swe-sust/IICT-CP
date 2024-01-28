#include<bits/stdc++.h>
using namespace std;

void initial() {
    #ifndef LEETCODE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

queue<int> qu; 
int visited[6] = {0};

int main()
{
    initial();
    int numberOfNodes  = 9;
    int startingNode = 0;

    // int graph[numberOfNodes][numberOfNodes] = {{0, 1, 1, 0, 0, 0},
    //                            {1, 0, 1, 0, 0, 0},
    //                            {1, 1, 0, 1, 1, 0},
    //                            {0, 0, 1, 0, 0, 0},
    //                            {0, 0, 1, 0, 0, 1},
    //                            {0, 0, 0, 0, 1, 0}};

   int graph[numberOfNodes][numberOfNodes] = {{0, 1, 1, 1, 0, 0, 0, 0, 0},
               {1, 0, 0, 0, 1, 1, 0, 0, 0},
               {1, 0, 0, 0, 0, 0, 0, 0, 0},
               {1, 0, 0, 0, 0, 0, 0, 1, 1},
               {0, 1, 0, 0, 0, 0, 1, 0, 0},
               {0, 1, 0, 0, 0, 0, 1, 0, 0},
               {0, 0, 0, 0, 0, 1, 1, 0, 0},
               {0, 0, 0, 1, 0, 0, 0, 0, 0},
               {0, 0, 0, 1, 0, 0, 0, 0, 0}};
    
    qu.push(startingNode);
    visited[startingNode] = 1;
    while(!qu.empty())
    {
        int current = qu.front();
        printf("visiting node %d \n", current);
        qu.pop();
 
        for(int i=0;i<numberOfNodes;i++)
        {
            if((graph[current][i] == 1) && (visited[i] == 0))
            {
                qu.push(i);
                visited[i] = 1;
            }
        }
    }
    return 0;
}