#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> graph;
vector<int> visited; //mar the state of the vertices. 0->unvisited, 1->visiting, 2->visited

void cycleDetection(int source){
    visited[source] = 1; //visiting source
    for(int neighbour : graph[source]){
        if(visited[neighbour] == 0) cycleDetection(neighbour);
        else if(visited[neighbour] == 1){
            cout << "The graph has a cycle" << endl;
            return;
        }
    }
    visited[source] = 2;
}

int main(){
    cin >> V >> E;
    graph.resize(V);
    visited.resize(V, 0);
    for(int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i = 0; i < V; i++){
        if(visited[i]) cycleDetection(i);
    }
    return 0;
}