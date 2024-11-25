#include <bits/stdc++.h>

using namespace std;

int V, E;
//Using stack instead of recursion
bool DFS(vector<vector<int>>& graph, int source){
    stack<int> s;
    unordered_set<int> visited;
    //push source to stack
    s.push(source);
    visited.insert(source);
    while(!s.empty()){
        int node = s.top();
        for(int neighbour : graph[node]){
            if(visited.find(neighbour) == visited.end()){
                visited.insert(neighbour);
                s.push(neighbour);
            }
        }
    }
    if(visited.size() == V) return true;
    else return false;
}

int main(){
    cin >> V >> E;
    vector<vector<int>> graph(V);
    vector<vector<int>> transposeGraph(V);
    for(int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        transposeGraph[y].push_back(x);
    }
    if(DFS(graph, 0) && DFS(transposeGraph, 0)) cout << "Strongly connected" << endl;
    else cout << "Not strongly connected" << endl;
    return 0;
}