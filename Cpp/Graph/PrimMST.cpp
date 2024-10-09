#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> edge; //<weight, destination>
vector<vector<edge>> graph;
vector<pair<int, edge>> MST;
int V, E, weight = 0;

void Prim(){
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    vector<bool> selected(V + 1, false);
    vector<int> key(V + 1, INT_MAX);
    vector<int> parent(V + 1, -1);

    //select vertex 1
    key[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        int v = pq.top().second;
        int vWeight = pq.top().first;
        pq.pop();
        if(selected[v]) continue;
        selected[v] = true;
        weight += vWeight;
        if(parent[v] != -1) MST.push_back({parent[v], {vWeight, v}});
        for(auto u : graph[v]){
            int neibour = u.second;
            int neibourWeight = u.first;
            if(!selected[neibour] && neibourWeight < key[neibour]){
                key[neibour] = neibourWeight;
                pq.push({neibourWeight, neibour});
                parent[neibour] = v;
            }
        }
    }
    if(MST.size() < V - 1) cout << "Not a connected graph -> NO MST FOUND" << endl;
    else{
        cout << "MST weight: " << weight << endl;
        for(auto i : MST){
            cout << i.first << " " << i.second.second << " " << i.second.first << endl;
        }
    }
}

int main(){
    cin >> V >> E;
    graph.resize(V + 1);
    for(int i = 0; i < E; i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({w,y});
        graph[y].push_back({w,x});
    }
    Prim();
    return 0;
}