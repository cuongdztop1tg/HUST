#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> graph;

void BFS(int s){
    queue<int> q;
    vector<bool> visited(V, false);

    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        cout << u << " ";
        q.pop();
        for(auto i : graph[u]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
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
    int s;
    cin >> s;
    BFS(s);
    return 0;
}