#include <bits/stdc++.h>

using namespace std;

int V, E, Time = 0, Count = 0;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> d, f, id, pred;

void DFS(int s){
    visited[s] = true;
    cout << s << " ";
    id[s] = Count;
    Time++;
    d[s] = Time;
    for(auto i : graph[s]){
        if(!visited[i]){
            pred[i] = s;
            DFS(i);
        }
    }
    Time++;
    f[s] = Time;
}

void countConnectedComponents(){
    cout << "Number of connected components: " << Count << endl;
    for(int i = 1; i <= Count; i++){
        cout << "Components " << i << ": ";
        for(int j = 0; j < V; j++){
            if(id[j] == i) cout << j << " ";
        }
        cout << endl;
    }
}

void edgeClassification(){
    for(int i = 0; i < V; i++){
        cout << "Vertex " << i << ": " << d[i] << " " << f[i] << endl;
    }
}

void pathFinding(){
    int s, t;
    cin >> s >> t;
    for(int i = 0; i < V; i++){
        pred[i] = INT_MIN;
        visited[i] = false;
    }
    DFS(s);
    for(int i = 0; i < V; i++) cout << pred[i] << " ";
}

int main(){
    cin >> V >> E;
    graph.resize(V);
    visited.resize(V, false);
    d.resize(V);
    f.resize(V);
    id.resize(V);
    pred.resize(V);
    for(int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            Count++;
            DFS(i);
            cout << endl;
        }
    }

    countConnectedComponents();
    edgeClassification();
    pathFinding();
    return 0;
}