#include <bits/stdc++.h>

using namespace std;

int V, E, s;
vector<pair<int, int>> graph[1000];
int d[1000], found[1000], p[1000];


void Dijkstra(){
    for(int i = 0; i <= V; i++){
        d[i] = INT_MAX;
        found[i] = false;
    }
    d[s] = 0;
    for(int i = 1; i < V; i++){
        int minD = INT_MAX, u;
        for(int k = 1; k <= V; k++){
            if(!found[k] && d[k] < minD){
                minD = d[k];
                u = k;
            }
        }
        found[u] = true;
        for(int j = 0; j < graph[u].size(); j++){
            pair<int, int> e = graph[u][j];
            if(!found[e.first]){
                if(d[e.first] > d[u] + e.second){
                    d[e.first] = d[u] + e.second;
                    p[e.first] = u;
                }
            }
        }
    }
}

int main(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y,w});
    }
    cin >> s;
    Dijkstra();

    for (int i = 1; i <= V; i++) {
        if (d[i] == INT_MAX) {
            cout << "Path from " << s << " to " << i << " is unreachable" << endl;
        } else {
            cout << "Path from " << s << " to " << i << " has distance " << d[i] << endl;
        }
    }
    return 0;
}