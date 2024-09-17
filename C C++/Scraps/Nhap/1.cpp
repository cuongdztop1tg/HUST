#include <bits/stdc++.h>
#include <vector>

using namespace std;

void BFS(vector<vector<int>> &graph, int s, int size) {
    queue<int> q;
    vector<bool> visited(size, false);

    visited[s] = true;
    q.push(s);
    cout << "BFS Traversal: " << s << " "; // Print the starting node

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < size; i++) {
            if (graph[u][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
                cout << i << " "; // Print the node when it's visited
            }
        }
    }
    cout << endl;
}

int main() {
    int size, s;
    cin >> size;
    vector<vector<int>> graph(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> graph[i][j];
        }
    }
    cin >> s;
    BFS(graph, s, size);
    return 0;
}
