#include <bits/stdc++.h>

using namespace std;

int V, E;
//Adjacency list, directed graph
vector<vector<int>> graph;
//Store the distance from source to another vertex
vector<int> dis;
//pred[v] = u --> u preceding v
vector<int> pred;

void BFS(vector<vector<int>>& graph, int source){
    queue<int> q;
    vector<bool> visited(V, false);
    //Push source into the queue
    q.push(source);
    visited[source] = true;
    dis[source] = 0;
    while(!q.empty()){
        int node = q.front();
        cout << node << " ";
        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                q.push(neighbour);
                dis[neighbour] = dis[node] + 1;
                visited[neighbour] = true;
            }
        }
    }
}

int main(){
    cin >> V >> E;
    graph.resize(V);
    pred.resize(V, -1);
    dis.resize(V, INT_MAX);
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