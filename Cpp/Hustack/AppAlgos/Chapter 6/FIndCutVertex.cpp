#include <bits/stdc++.h>

using namespace std;

int V, E, Time, numOfBridges = 0, numOfCutVertex = 0;
vector<vector<int>> graph;
int parent[50000];
int num[50000];
int low[50000];
bool cutVertex[50000];

void DFS(int u){
    Time++;
    num[u] = Time; low[u] = Time;
    int numChild = 0;
    for(auto v : graph[u]){
        if(num[v] == 0){
            numChild++;
            parent[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if(parent[u] == -999 && numChild > 1) cutVertex[u] = true;
            if(parent[u] != -999 && low[v] >= num[u]) cutVertex[u] = true;
            if(low[v] > num[u]) numOfBridges++;
        }
        else if(parent[u] != v){
            low[u] = min(low[u], num[v]);
        }
    }
}

int main(){
    cin >> V >> E;
    graph.resize(V + 1);
    for(int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 0; i < V; i++){
        parent[i] = -999;
        num[i] = 0;
        cutVertex[i] = false;
    }
    Time = 0;
    for(int i = 1; i <= V; i++){
        if(num[i] == 0) DFS(i);
    }
    for(int i = 1; i <= V; i++){
        if(cutVertex[i]) numOfCutVertex++;
    }
    cout << numOfCutVertex << " " << numOfBridges;
    return 0;
}