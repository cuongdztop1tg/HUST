#include <bits/stdc++.h>

using namespace std;

int V, m, MSTweight = 0;
int coordinate[750][2];
vector<pair<int, pair<int, int>>> graph, MST;   //{u, {v, weight}}

//Union Find
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
//custom comp function for sorting
//compare the weight
bool comp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b){
    return a.second.second < b.second.second;
}

int calWeight(int Ax, int Bx, int Ay, int By){
    return (Ax - Bx)*(Ax - Bx) - (Ay - By)*(Ay - By);
}

void Kruskal(){
    sort(graph.begin(), graph.end(), comp); //sort edges in ascending order by their weights
    //Iterate through all the edges
    for(auto edge : graph){
        //check if the 2 vertices belongs to the same set
        //If true, adding the edge creates a cycle
        int rootU = Find(edge.first);
        int rootV = Find(edge.second.first);
        //Else, add the edge to T
        if(rootU != rootV){
            MST.push_back(edge);
            MSTweight += edge.second.second;
            Union(rootU, rootV);
            if(MST.size() == V - 1){
                cout << MSTweight << endl;
            }
        }
    }
}
//kruskal
int main(){
    makeSet();
    cin >> V;
    //coordinate
    for(int i = 1; i <= V; i++){
        int x, y;
        cin >> x >> y;
        coordinate[i][0] = x;
        coordinate[i][1] = y;
    }
    //build edge
    for(int i = 1; i <= V; i++){
        for(int j = i + 1; j <= V; j++){
            int w = calWeight(coordinate[i][0], coordinate[i][1], coordinate[j][0], coordinate[j][1]);
            graph.push_back({i, {w, j}});
            graph.push_back({j, {w, i}});
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }
    Kruskal();
    return 0;
}