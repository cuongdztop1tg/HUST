#include <bits/stdc++.h>

using namespace std;

int V;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> pred;
vector<int> d;
vector<int> f;
vector<int> id;
int Time = 0, Count = 0;

void DFS(int s){
    visited[s] = true;
    Time++;
    d[s] = Time;
    id[s] = Count;

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
    id.resize(V, 0);

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
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            Count++;
            cout << "Source vertex " << i << ": ";
            DFS(i);
            cout << endl;
        }
    }
    //Vertex classification
    for(int i = 0; i < V; i++){
        cout << "Vertex " << i << ": " << d[i] << " " << f[i] << endl;
    }
    //count connected components
    cout << "Number of connected components: " << Count << endl;
    for(int i = 1; i <= Count; i++){
        cout << "Component " << i << ": "; 
        for(int j = 0; j < V; j++){
            if(id[j] == Count) cout << j << " ";
        }
        cout << endl;
    }
    //Pathfinding
    
    return 0;
}