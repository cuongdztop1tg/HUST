#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 1;

int V, E, numOfCutVertices = 0, numOfBridges = 0, Time = 0;
vector<vector<int>> graph;
int parent[N];
int num[N];
int low[N];
bool cutVertices[N];
vector<pair<int, int>> Bridges;
void DFS(int u){
    Time++;
    num[u] = Time;
    low[u] = Time;  //set low[u] = num[u]
    int numOfChild = 0;
    for(int v : graph[u]){
        if(num[v] == 0){    //v is not visited
            parent[v] = u;
            numOfChild++;
            DFS(v);
            low[u] = min(low[v], low[u]);
            if(parent[u] == -999 && numOfChild > 1) cutVertices[u] = true;
            if(parent[u] != -999 && low[v] >= num[u]) cutVertices[u] = true;
            if(low[v] > num[u]){
                numOfBridges++;
                Bridges.push_back({u, v});
            }
        }
        //v is ancestor of u -> (u, v) is a back-edge
        else if(parent[u] != v){
            low[u] = min(low[u], num[v]);
        }
    }
}

int main(){
    cin >> V >> E;
    graph.resize(V + 1);
    for(int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 1; i <= V; i++){
        parent[i] = -999;
        num[i] = 0;
        cutVertices[i] = false;
    }
    for(int i = 1; i <= V; i++){
        if(num[i] == 0) DFS(i);
    }
    cout << "Cut vertices: ";
    for(int i = 1; i <= V; i++){
        if(cutVertices[i] == true){
            numOfCutVertices++;
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "Bridges: " << endl;
    for(auto e : Bridges){
        cout << e.first << " - " << e.second << endl;
    }
    return 0;
}

/*Test case:
Input:
    11 14
    1 2
    1 3
    2 3
    3 4
    4 9
    4 6
    6 9
    6 7
    7 9
    7 10
    6 5
    5 8
    8 11
    5 11
Output:
    Cut vertices: 3 4 5 6 7 
    Bridges:
    7 - 10
    6 - 5
    3 - 4
*/