#include <bits/stdc++.h>

using namespace std;

int V;
vector<int> dist;
vector<vector<pair<int, int>>> graph;   //{v, w}

void init(){
    for(int i = 0; i <= V; i++){
        dist[i] = -1;
    }
}

void DFS(int u){
    for(auto e : graph[u]){
        int v = e.first, w = e.second;
        if(dist[v] < 0){
            dist[v] = dist[u] + w;
            DFS(v);
        }
    }
}

int main(){
    cin >> V;
    graph.resize(V + 1);
    dist.resize(V + 1);
    for(int i = 0; i < V - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    init();
    dist[1] = 0;
    DFS(1);
    int u = 1;
    for(int i = 1; i <= V; i++){
        if(dist[i] > dist[u]){
            u = i;
        }
    }
    init();
    dist[u] = 0;
    DFS(u);
    int res = *max_element(dist.begin(), dist.end());
    cout << res;
    return 0;
}