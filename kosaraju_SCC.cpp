#include<bits/stdc++.h>
using namespace std;

const int max_node = 1000;
vector<int> graph[max_node];
vector<int> transpose_graph[max_node];
bool vis[max_node];
stack<int> st;

void dfs(int n){
    if(vis[n]) return;

    int len=graph[n].size();
    vis[n]=true;

    for(int i= 0; i<len; i++){
        dfs(graph[n][i]);
    }
    cout << n << " ";
    st.push(n);
}

void dfs_print(int n){
    if(vis[n] == true) return;

    cout<< n <<" ";

    int len= transpose_graph[n].size();
    vis[n]= true;

    for(int i= 0; i<len; i++){
        dfs_print(transpose_graph[n][i]);
    }
}

int kosarajuSCC(int numberOfNodes){
    int scc_count=0;
    for(int i=0; i<numberOfNodes; i++){
        if(vis[i] == false){
            dfs(i);
        }
    }

    for(int i=0; i<numberOfNodes; i++){
        vis[i]=false;
    }

    while(!st.empty()){
        if(vis[st.top()] == false){
            dfs_print(st.top());
            scc_count++;
            cout<<endl;
        }
        st.pop();
    }

    return scc_count;
}

int main(){
    int numberOfNodes, numberOfEdges, u, v;
    cin>>numberOfNodes>>numberOfEdges;

    for(int i= 0; i<=numberOfNodes; i++){
        vis[i] = false;
        graph[i].clear();
        transpose_graph[i].clear();
    }

    for(int i= 0; i<numberOfEdges; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        transpose_graph[v].push_back(u);
    }

    int components= kosarajuSCC(numberOfNodes);
    cout<< "Components: "<< components <<endl;


    return 0;
}

/*
8 9
0 1
1 2
2 3
3 0
2 4
4 5
5 6
6 4
6 7
*/
