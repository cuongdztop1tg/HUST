#include <bits/stdc++.h>

using namespace std;

int V, E;

void BFS(vector<vector<int>>& graph, int source){
    queue<int> q;
    vector<bool> visited(V, false);
    //Push source into the queue
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
        int node = q.front();
        cout << node << " ";
        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

int main(){
    cin >> V >> E;
    //Adjacency list, directed graph
    vector<vector<int>> graph(V);
    //Create graph
    for(int i = 0; i < E; i++){
        int initial, terminal;
        cin >> initial >> terminal;
        graph[initial].push_back(terminal);
    }
    int source;
    cin >> source;
    BFS(graph, source);
    return 0;
}