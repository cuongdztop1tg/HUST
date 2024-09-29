#include <bits/stdc++.h>

using namespace std;

int V, Count = 0, Time = 0;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> d, f, pred, id;

void DFS(int s){
    visited[s] = true;
    cout << s << " ";
    Time++;
    d[s] = Time;
    id[s] = Count;
    for(auto i : graph[s]){
        if(!visited[i]){
            DFS(i);
        }
    }
    Time++;
    f[s] = Time;
}

int main(){
    cin >> V;
    graph.resize(V);
    visited.resize(V, false);
    d.resize(V);
    f.resize(V);
    pred.resize(V, INT_MIN);
    id.resize(V);
    while(1){
        int initial, terminal;
        cin >> initial;
        if(initial == -1) break;
        cin >> terminal;
        graph[initial].push_back(terminal);
        //graph[terminal].push_back(initial);
    }
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            Count++;
            cout << "Source vertex " << i << ": ";
            DFS(i);
            cout << endl;
        }
    }

    for(int i = 0; i < V; i++){
        cout << "Vertex " << i << ": " << d[i] << " " << f[i] << endl; 
    }

    cout << "Number of connected components: " << Count << endl;
    for(int i = 1; i <= Count; i++){
        cout << "Component " << i << ": ";
        for(int j = 0; j < V; j++){
            if(id[j] == i) cout << j << " ";
        }
        cout << endl;
    }

    int s, t;
    cin >> s >> t;
    return 0;
}