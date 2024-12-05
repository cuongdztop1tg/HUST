#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
typedef pair<int, int> edge;
int V;
vector<edge> graph[N];
int d[N]; //Sum of weight of path from descendant of u to u
int num[N]; //number of descendant of u (including u)
int f[N]; //sum of weight of path from other nodes to u
int p[N]; //parent of u
void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V;
    for(int i = 0; i < V - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
}

void DFS1(int u){
    for(auto e : graph[u]){
        int v = e.first;
        int w = e.second;
        if(p[v] == 0){ //v not visited
            p[v] = u;
            DFS1(v);
            d[u] = d[u] + d[v] + num[v] * w;
            num[u] += num[v];
        }
    }
}

void solvePhase1(){
    for(int i = 1; i <= V; i++){
        p[i] = 0;
        d[i] = 0;
        num[i] = 1;
        f[i] = 0;
    }
    int root = 1;
    p[root] = root;
    DFS1(root);
}
//know f[u], compute f[v] for all child v of u
void DFS2(int u){
    for(auto e : graph[u]){
        int v = e.first;
        int w = e.second;
        if(p[v] == 0){
            int F = f[u] - (d[v] + w*num[v]);
            f[v] = F + d[v] + w*(V - num[v]);
            p[v] = u;
            DFS2(v);
        }
    }
}

void solvePhase2(){
    for(int i = 1; i <= V; i++){
        p[i] = 0;
    }
    int root = 1;
    f[root] = d[root];
    p[root] = root;
    DFS2(root);
    int ans = 0;
    for(int i = 1; i <= V; i++){
        ans = max(ans, f[i]);
    }
    cout << ans;
}
int main(){
    input();
    solvePhase1();
    solvePhase2();
    return 0;
}