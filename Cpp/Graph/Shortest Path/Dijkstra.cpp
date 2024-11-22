#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> edge;
map<edge, int> graph;
int V, E;
int d[1000], p[1000];
vector<int> S;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> T;

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
        if (find(S.begin(), S.end(), u) != S.end()) continue;
        S.push_back(u);
        for (auto i : graph) {
            if (i.first.first == u) {
                relax(i.first.first, i.first.second);
            }
        }
    }
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[{x, y}] = w;
    }
    int s;
    cin >> s;
    Dijkstra(s);

    for (int i = 1; i <= V; i++) {
        if (d[i] == INT_MAX) {
            cout << "Path from " << s << " to " << i << " is unreachable" << endl;
        } else {
            cout << "Path from " << s << " to " << i << " has distance " << d[i] << endl;
        }
    }
    return 0;
}
