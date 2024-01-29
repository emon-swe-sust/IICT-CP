#include<bits/stdc++.h>
using namespace std;

void initial() {
    #ifndef LEETCODE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

stack<int> st; 
int visited[6] = {0};

int main()
{
    initial();
    int numberOfNodes  = 9;
    int startingNode = 0;

    // int graph[numberOfNodes][numberOfNodes] = {{0, 1, 1, 1, 0},
    //                            {1, 0, 1, 0, 0},
    //                            {1, 0, 0, 0, 1},
    //                            {1, 0, 0, 0, 0},
    //                            {0, 0, 1, 0, 0}};

                                            //  0  1  2  3  4  5  6  7  8
    int graph[numberOfNodes][numberOfNodes] = {{0, 1, 1, 1, 0, 0, 0, 0, 0},
                                               {1, 0, 0, 0, 1, 1, 0, 0, 0},
                                               {1, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {1, 0, 0, 0, 0, 0, 0, 1, 1},
                                               {0, 1, 0, 0, 0, 0, 1, 0, 0},
                                               {0, 1, 0, 0, 0, 0, 1, 0, 0},
                                               {0, 0, 0, 0, 0, 1, 1, 0, 0},
                                               {0, 0, 0, 1, 0, 0, 0, 0, 0},
                                               {0, 0, 0, 1, 0, 0, 0, 0, 0}};
    
    st.push(startingNode);
    visited[startingNode] = 1;
    while(!st.empty())
    {
        int current = st.top();
        printf("visiting node %d \n", current);
        st.pop();
 
        for(int i=0;i<numberOfNodes;i++)
        {
            if((graph[current][i] == 1) && (visited[i] == 0))
            {
                st.push(i);
                visited[i] = 1;

            }
        }
    }
    return 0;
}