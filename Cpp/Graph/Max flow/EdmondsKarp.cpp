#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int capG[MAXN][MAXN], capRG[MAXN][MAXN];
int pred[MAXN];
int n, m, s, t;

bool bfs(int s, int t) {
    memset(pred, -1, sizeof(pred));
    queue<int> q;
    q.push(s);
    pred[s] = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (pred[v] == -1 && capRG[u][v] > 0) {
                pred[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int EK(int s, int t) {
    memcpy(capRG, capG, sizeof(capG));
    int maxflow = 0;
    while (bfs(s, t)) {
        int capP = INT_MAX;
        for (int v = t; v != s; v = pred[v]) {
            int u = pred[v];
            capP = min(capP, capRG[u][v]);
        }
        for (int v = t; v != s; v = pred[v]) {
            int u = pred[v];
            capRG[u][v] -= capP;
            capRG[v][u] += capP;
        }
        maxflow += capP;
    }
    return maxflow;
}

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> s >> t;

    // Convert to 0-indexed
    s--; t--;

    memset(capG, 0, sizeof(capG));
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        // Convert to 0-indexed
        x--; y--;
        capG[x][y] = w;
    }
    cout << EK(s, t) << endl;
}

int main() {
    input();
    return 0;
}

/* TEST CASE
6 9 1 6
1 2 10
1 3 10
2 3 2
2 5 4
2 4 8
3 4 9
4 5 6
4 6 10
5 6 10
-> 19
*/