#include <bits/stdc++.h>

using namespace std;

//d[u]: distance from u to s
//pred[u]: return the vertex preceding u

int V;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> d;
vector<int> pred;

void BFS(int s){
    queue<char> queue;

    visited[s] = true;
    d[s] = 0;
    pred[s] = INT_MIN;
    queue.push(s);

    while(!queue.empty()){
        int u = queue.front();
        cout << u << " ";
        queue.pop();
        for(int i = 0; i < V; i++){
            if(graph[u][i] == 1 & !visited[i]){
                visited[i] = true;
                d[i] = d[u] + 1;
                pred[i] = u;
                queue.push(i);
            }
        }
    }

    cout << endl;
}

int main(){
    cin >> V;
    graph.resize(V, vector<int>(V));
    visited.resize(V, false);
    d.resize(V);
    pred.resize(V);
    //input
    while(1){
        int initial, terminal;
        cin >> initial;
        if(initial == -1) break;
        cin >> terminal;
        graph[initial][terminal] = 1;
        graph[terminal][initial] = 1;
    }
    for(int i = 0; i < V; i++){
        d[i] = INT_MAX;
        pred[i] = INT_MIN;
    }
    
    int s;
    cin >> s;
    BFS(s);
    cout << d[5] << endl;
    cout << pred[5];
    return 0;
}