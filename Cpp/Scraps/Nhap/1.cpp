#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> graph;
map<string, int> visited;

// Cycle detection function
bool cycleDetect(string s, int k, int depth, string start) {
    visited[s] = 1;

    for (auto i : graph[s]) {
        if (visited[i] == 1) { // If revisiting a node already in the current path
            if (i == start && depth == k) {  // Check if it's the starting node and cycle length is k
                return true;  // Cycle detected
            }
        } else if (visited[i] == 0) {  // Unvisited node, continue DFS
            if (cycleDetect(i, k, depth + 1, start)) {
                return true;
            }
        }
    }

    visited[s] = 0;  // Mark node as unvisited for other paths
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    string from, to, Time, atm;
    long long money;
    while (1) {
        cin >> from;
        if (from == "#") break;  // End of input
        cin >> to >> money >> Time >> atm;
        graph[from].push_back(to);  // Add directed edge
    }

    // Initialize visited map
    for (auto& it : graph) {
        visited[it.first] = 0;
    }

    // Start cycle detection from vertex "T000010010" and k = 3
    string startVertex = "T000010010";
    int cycleLength = 5;

    if (cycleDetect(startVertex, cycleLength, 1, startVertex)) {
        cout << "Cycle of length " << cycleLength << " detected starting from " << startVertex << endl;
    } else {
        cout << "No cycle of length " << cycleLength << " detected starting from " << startVertex << endl;
    }

    return 0;
}
