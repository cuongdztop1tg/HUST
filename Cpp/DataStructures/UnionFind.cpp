#include <bits/stdc++.h>

using namespace std;

int V;
vector<int> parent, sz;

void makeSet(){
    parent.resize(V + 1);
    sz.resize(V + 1);
    for(int i = 1; i <= V; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u){
    if(u == parent[u]) return u;
    else return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]){
        swap(u, v);
    }
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

int main(){
    return 0;
}