#include <bits/stdc++.h>

using namespace std;

int V;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> pred;
vector<int> d;
vector<int> f;
int Time = 0;

void DFS(int s){
    visited[s] = true;
    Time++;
    d[s] = Time;

    cout << s << " ";
    for(int i = 0; i < V; i++){
        if(graph[s][i] == 1 && !visited[i]){
            DFS(i);
            pred[i] = s;
        }
    }
    Time++;
    f[s] = Time;
}

int main(){
    cin >> V;
    graph.resize(V, vector<int>(V));
    visited.resize(V, false);
    d.resize(V);f.resize(V);
    pred.resize(V);

    while(1){
        int initial, terminal;
        cin >> initial;
        if(initial == -1) break;
        cin >> terminal;
        graph[initial][terminal] = 1;
        // graph[terminal][initial] = 1;
    }

    for(int i = 0; i < V; i++){
        visited[i] = false;
        pred[i] = INT_MIN;
    }
    DFS(0);
    cout << endl;
    cout << d[4] << " " << f[4];
    return 0;
}