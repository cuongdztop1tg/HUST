#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V;
vector<pair<int, int>> Adj[100001];
int sizeTree[100001];
int visited[100001];
long long answer[100001];

void DFS1(int s, int length) {
    visited[s] = 1;
    answer[1] += length;
    for (auto it : Adj[s]) {
        int v = it.first;
        if (!visited[v]) {
            DFS1(v, length + it.second);
            sizeTree[s] += sizeTree[v];
        }
    }
}

void DFS2(int s) {
    visited[s] = 1;
    for (auto it : Adj[s]) {
        int v = it.first;
        if (!visited[v]) {
            answer[v] = answer[s] - it.second * sizeTree[v] + it.second * (V - sizeTree[v]);
            DFS2(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V;
    for (int i = 0; i < V - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        Adj[x].push_back({y, w});
        Adj[y].push_back({x, w});
    }
    
    for (int i = 1; i <= V; i++) {
        visited[i] = 0;
        sizeTree[i] = 1;
        answer[i] = 0;
    }

    DFS1(1, 0);

    for (int i = 1; i <= V; i++) {
        visited[i] = 0;
    }

    DFS2(1);

    long long maxAnswer = 0;
    for (int i = 1; i <= V; i++) {
        maxAnswer = max(maxAnswer, answer[i]);
    }

    cout << maxAnswer << endl;

    return 0;
}