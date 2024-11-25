#include <bits/stdc++.h>

using namespace std;

int V, E, Time = 0, numOfConnectedComponents = 0;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> startTime, endTime, componentID, pred;

void DFS(int source){
    visited[source] = true;
    cout << source << " ";
    componentID[source] = numOfConnectedComponents;
    Time++;
    startTime[source] = Time;
    for(auto neighbour : graph[source]){
        if(!visited[neighbour]){
            pred[neighbour] = source;
            DFS(neighbour);
        }
    }
    Time++;
    endTime[source] = Time;
}

void countConnectedComponents(){
    cout << "Number of connected components: " << numOfConnectedComponents << endl;
    for(int i = 1; i <= numOfConnectedComponents; i++){
        cout << "Components " << i << ": ";
        for(int j = 0; j < V; j++){
            if(componentID[j] == i) cout << j << " ";
        }
        cout << endl;
    }
}

void edgeClassification(){
    for(int i = 0; i < V; i++){
        cout << "Vertex " << i << ": " << startTime[i] << " " << endTime[i] << endl;
    }
}

//NOT DONE YET
void pathFinding(){
    int source, destination;
    cin >> source >> destination;
    for(int i = 0; i < V; i++){
        pred[i] = INT_MIN;
        visited[i] = false;
    }
    DFS(source);
    for(int i = 0; i < V; i++) cout << pred[i] << " ";
}

int main(){
    cin >> V >> E;
    graph.resize(V);
    visited.resize(V, false);
    startTime.resize(V);
    endTime.resize(V);
    componentID.resize(V);
    pred.resize(V);
    //Create graph
    for(int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            numOfConnectedComponents++;
            DFS(i);
            cout << endl;
        }
    }
    countConnectedComponents();
    edgeClassification();
    pathFinding();
    return 0;
}