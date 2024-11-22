#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> graph;
vector<bool> visited;
stack<int> topo;

void DFS(int s){
    visited[s] = true;
    for(auto i : graph[s]){
        if(!visited[i]) DFS(i);
    }
    topo.push(s);
}

void topoSort(){
    visited.resize(V, false);
    for(int i = 0; i < V; i++){
        if(!visited[i]) DFS(i);
    }
    while(!topo.empty()){
        cout << topo.top() << " ";
        topo.pop();
    }
} 

int main(){
    cin >> V >> E;
    graph.resize(V);
    for(int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    topoSort();
    return 0;
}