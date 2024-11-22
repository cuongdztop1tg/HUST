#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> inDegree;
vector<int> order;

void topoSort(){
    queue<int> topo;
    visited.resize(V, false);
    order.resize(V);
    for(int i = 0; i < V; i++){
        if(inDegree[i] == 0) topo.push(i);
    }
    int num = 0;
    while(!topo.empty()){
        int u = topo.front();
        cout << u << " ";
        num++;
        order[u] = num;
        topo.pop();
        for(auto i : graph[u]){
            inDegree[i]--;
            if(inDegree[i] == 0) topo.push(i);
        }
    }
    cout << endl;
    cout << "Order: ";
    for(auto i : order) cout << i << " ";
}

int main(){
    cin >> V >> E;
    graph.resize(V);
    inDegree.resize(V, 0);
    for(int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        inDegree[y]++;
    }
    topoSort();
    return 0;
}