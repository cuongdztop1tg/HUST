#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 1;
int V, E, Time = 0, numOfSCC = 0;
vector<vector<int>> graph;
vector<vector<int>> SCC;
int num[N];
int low[N];
bool inStack[N];
stack<int> s;

void Tarjan(int u){
    Time++;
    num[u] = Time;
    low[u] = Time;
    inStack[u] = true;
    s.push(u);
    for(int v : graph[u]){
        if(num[v] == 0){
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inStack[v]){
            low[u] = min(low[u], num[v]);
        }
    }
    if(num[u] == low[u]){
        vector<int> scc;
        while(1){
            int v = s.top();
            s.pop();
            inStack[v] = false;
            scc.push_back(v);
            if(u == v) break;
        }
        sort(scc.begin(), scc.end()); //just to make the output prettier, not necessary
        SCC.push_back(scc);
    }
}

int main(){
    cin >> V >> E;
    graph.resize(V + 1);
    for(int i = 0; i < E; i++){
        int x, y; 
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i = 1; i <= V; i++){
        num[i] = 0;
        inStack[i] = false;
    }
    for(int i = 1; i <= V; i++){
        if(num[i] == 0) Tarjan(i);
    }
    cout << "The SCCs are: " << endl;
    for(auto scc : SCC){
        numOfSCC++;
        cout << numOfSCC << ": ";
        for(int v : scc) cout << v << " ";
        cout << endl;
    }
    return 0;
}

/*Test case:
Input:
    11 14
    1 2
    2 3
    3 1
    3 4
    4 6
    6 7
    7 10
    7 9
    9 6
    9 4
    6 5
    5 8
    8 11
    11 5
Output:
    The SCCs are: 
    1: 10
    2: 5 8 11
    3: 4 6 7 9
    4: 1 2 3
*/