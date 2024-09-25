#include <bits/stdc++.h>

using namespace std;

int V;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> d;
vector<int> pred;

void DFS(int s){
    visited[s] = true;
    cout << s << " ";
    for(auto i : graph[s]){
        if(!visited[i]) DFS(i);
    }
}

int main(){
    cin >> V;
    graph.resize(V);
    visited.resize(V, false);
    d.resize(V);
    pred.resize(V);
    while(1){
        int initial, terminal;
        cin >> initial;
        if(initial == -1) break;
        cin >> terminal;
        graph[initial].push_back(terminal);
        graph[terminal].push_back(initial);
    }
    DFS(0);
    return 0;
}