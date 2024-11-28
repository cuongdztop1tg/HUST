#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> edge;
map<edge, int> graph;
int V, E;
int d[1000], p[1000];
unordered_set<int> S;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> T;
int source, des;

void relax(int u, int v) {
    if (d[v] > d[u] + graph[{u, v}]) {
        d[v] = d[u] + graph[{u, v}];
        p[v] = u;
        T.push({d[v], v});
    }
}

void Dijkstra(int s) {
    for (int v = 1; v <= V; v++) {
        d[v] = INT_MAX;
        p[v] = -1;
    }
    d[s] = 0;
    p[s] = s;
    T.push({0, s});
    while (!T.empty()) {
        int u = T.top().second;
        T.pop();
        if (S.find(u) != S.end()) continue;
        S.insert(u);
        for (auto i : graph) {
            if (i.first.first == u) {
                int v = i.first.second;
                relax(u, v);
            }
        }
    }
}

int main(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v, d, t;
        cin >> u >> v >> d >> t;
        graph[{u, v}] = d * t;
        graph[{v, u}] = d * t;
    }
    cin >> source >> des;
    Dijkstra(source);
    if(d[des] == INT_MAX) cout << -1;
    else cout << d[des];
    return 0;
}