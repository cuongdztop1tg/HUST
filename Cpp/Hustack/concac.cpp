#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
int V, E;
typedef pair<int, int> edge;
vector<edge> graph[N];
vector<int> topoList;
int d[N];
int F[N];
int inDeg[N];
int ans = 0;

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    memset(inDeg, 0, sizeof(inDeg));
    for(int i = 1; i <= V; i++){
        cin >> d[i];
    }
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, d[u]});
        inDeg[v]++;
    }
}

void topoSort(){
    queue<int> q;
    for(int i = 1; i <= V; i++){
        if(inDeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topoList.push_back(u);
        for(auto e : graph[u]){
            int v = e.first;
            inDeg[v]--;
            if(inDeg[v] == 0) q.push(v);
        }
    }
}

void solve(){
    memset(F, 0, sizeof(F));
    for(int i = 0; i < topoList.size(); i++){
        int u = topoList[i];
        ans = max(ans, F[u] + d[u]);
        for(auto e : graph[u]){
            int v = e.first;
            int w = e.second;
            F[v] = max(F[v], F[u] + w);
        }
    }
    cout << ans;
}

int main(){
    input();
    topoSort();
    solve();
    return 0;
}