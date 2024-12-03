#include <bits/stdc++.h>

using namespace std;

int V, E, MSTweight = 0;
vector<tuple<int, int, int>> graph, MST; //u, v, w

class UnionFind{
private:
    vector<int> parent, size;
public:
    UnionFind(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int Find(int i){
        if(i == parent[i]) return i;
        else return parent[i] = Find(parent[i]);
    }
    bool Union(int u, int v){
        u = Find(u);
        v = Find(v);
        if(u == v) return false;
        if(size[u] < size[v]){
            swap(u, v);
        }
        size[u] += size[v];
        parent[v] = u;
        return true;
    }
};

bool comp(const tuple<int, int, int>& a, const tuple<int, int, int>& b){
    return get<2>(a) < get<2>(b);
}

int Kruskal(){
    UnionFind uf = UnionFind(V + 1);
    sort(graph.begin(), graph.end(), comp);
    for(auto edge : graph){
        auto [u, v, w] = edge;
        int root1 = uf.Find(u);
        int root2 = uf.Find(v);
        if(root1 != root2){
            MST.push_back(edge);
            MSTweight += w;
            uf.Union(root1, root2);
            if(MST.size() == V - 1) break;
        }
    }
    return MSTweight;
}

int main(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
        graph.push_back({v, u, w});
    }
    cout << Kruskal();
    return 0;
}