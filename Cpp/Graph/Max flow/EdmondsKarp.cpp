#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> capG;   //original graph, adj matrix
vector<vector<int>> capRG;  //residual graph, adj matrix
vector<int> pred;

bool BFS(int s, int t){
    fill(pred.begin(), pred.end(), -1);
    queue<int> q;
    q.push(s);
    pred[s] = s;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == t) return true;
        for(int v = 1; v <= V; v++){
            if(pred[v] == -1 && capRG[u][v] > 0){
                pred[v] = u;
                q.push(v);
            }
        }
    }
    return false;
}

int maxFlow(int s, int t){
    int maxFlow = 0;
    while(BFS(s, t)){
        int capP = INT_MAX;
        for(int v = t; v != s; v = pred[v]){
            int u = pred[v];
            capP = min(capP, capRG[u][v]);
        }
        for(int v = t; v != s; v = pred[v]){
            int u = pred[v];
            capRG[u][v] -= capP;
            capRG[v][u] += capP;
        }
        maxFlow += capP;
    }
    return maxFlow;
}

void minCut(int s, int t){
    vector<bool> visited(V + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 1; v <= V; v++){
            if(!visited[v] && capRG[u][v] > 0){
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "Min-cut edges: " << endl;
    for(int u = 1; u <= V; u++){
        for(int v = 1; v <= V; v++){
            if(visited[u] && !visited[v] && capG[u][v] > 0){
                cout << u << " -> " << v << endl;
            }
        }
    }
}
int main(){
    int s, t;
    cin >> V >> E >> s >> t;
    capG.resize(V + 1, vector<int>(V + 1, 0));
    capRG.resize(V + 1, vector<int>(V + 1, 0));
    pred.resize(V + 1, -1);
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        capG[u][v] = w;
        capRG[u][v] = w;
    }
    cout << maxFlow(s, t) << endl;
    minCut(s, t);
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