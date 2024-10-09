#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int V, E, MSTweight = 0;
vector<pair<int, pair<int, int>>> graph, MST;
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

bool comp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b){
    return a.second.second < b.second.second;
}

void Kruskal(){
    makeSet();
    sort(graph.begin(), graph.end(), comp);
    for(auto i : graph){
        int rootU = Find(i.first);
        int rootV = Find(i.second.first);
        if(rootU != rootV){
            MST.push_back(i);
            MSTweight += i.second.second;
            Union(rootU, rootV);
            if(MST.size() == V - 1){
                cout << "MST weight: " << MSTweight << endl;
                for(auto i : MST){
                    cout << i.first << " " << i.second.first << " " << i.second.second << endl;
                }
                return;
            }
        }
    }
    if(MST.size() < V - 1){
        cout << "Not a connected graph -> NO MST FOUND" << endl;
    }
}

int main(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph.push_back({x, {y, w}});
        graph.push_back({y, {x, w}});
    }
    cout << endl;
    Kruskal();
    return 0;
}
/*
7 12
1 6 2
1 2 2
1 4 7
2 4 4
6 2 5
4 5 1
6 3 4
2 3 1
2 5 3
3 5 4
*/