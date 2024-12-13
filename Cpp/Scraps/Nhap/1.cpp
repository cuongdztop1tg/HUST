#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;
vector<pair<int, int>> capG[MAXN];
int pred[MAXN];
int V, E, s, t;

bool bfs(int s, int t) {
    memset(pred, -1, sizeof(pred));
    queue<int> q;
    q.push(s);
    pred[s] = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : capG[u]) {
            if (pred[v.first] == -1 && v.second != 0) {
                pred[v.first] = u;
                if (v.first == t) return true;
                q.push(v.first);
            }
        }
    }
    return false;
}

pair<int, int> *findEdge(int u, int v) {
    for (pair<int, int> &edge : capG[u]) {
        if (edge.first == v) {
            return &edge;
        }
    }
    return nullptr;
}

int Edmond_Karp(int s, int t) {
    int maxflow = 0;
    while (bfs(s, t)) {
        int capP = INT_MAX;
        for (int v = t; v != s; v = pred[v]) {
            int u = pred[v];
            capP = min(capP, findEdge(u, v)->second);
        }
        for (int v = t; v != s; v = pred[v]) {
            int u = pred[v];
            findEdge(u, v)->second -= capP;
            findEdge(v, u)->second += capP;
        }
        maxflow += capP;
    }
    return maxflow;
}

int main() {
    cin >> V >> E >> s >> t;
    for (int i = 0; i < E; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        capG[x].push_back({y, w});
        capG[y].push_back({x, 0});
    }
    cout << Edmond_Karp(s, t) << endl;
    return 0;
}