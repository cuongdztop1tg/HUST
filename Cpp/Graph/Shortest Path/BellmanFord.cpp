#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> edge; //source, des
int V, E;
int d[1000], p[1000];
map<edge, int> graph;

void relax(int u, int v){
    if(d[v] > d[u] + graph[{u, v}]){
        d[v] = d[u] + graph[{u, v}];
        p[v] = u;
    }
}

void initSingleSource(int s){
    for(int i = 1; i <= V; i++){
        d[i] = 9999;
        p[i] = -999;
    }
    d[s] = 0;
}

bool BellmanFord(int s){
    initSingleSource(s);
    for(int i = 1; i < V; i++){
        for(auto e : graph){
            relax(e.first.first, e.first.second);
        }
    }
    for(auto e : graph){
        if(d[e.first.second] > d[e.first.first] + e.second) return false;
    }
    return true;
}

int main(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph[{x, y}] = w;
    }
    int s;
    cin >> s;
    if(!BellmanFord(s)){
        cout << "The graph has negative cycle" << endl;
    }
    else{
        for(int i = 1; i <= V; i++) cout << "Path from " << s << " to " << i << " " << d[i] << endl;
    }
    return 0;
}