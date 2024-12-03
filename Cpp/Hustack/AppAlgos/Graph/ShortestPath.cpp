#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> edge;
int V, E;
vector<vector<edge>> graph; //w, v

int Dijkstra(int source, int destination){
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    vector<int> dis(V + 1, INT_MAX);

    dis[source] = 0;
    pq.push({0, source});
    while(!pq.empty()){
        int curDis = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(curNode == destination) return dis[curNode];
        if(curDis > dis[curNode]) continue;
        for(auto& e : graph[curNode]){
            int w = e.first;
            int neighbour = e.second;
            if(dis[neighbour] > dis[curNode] + w){
                dis[neighbour] = dis[curNode] + w;
                pq.push({dis[neighbour], neighbour});
            }
        }
    }
    return -1;
}

int main(){
    cin >> V >> E;
    graph.resize(V + 1);
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    int s, t;
    cin >> s >> t;
    cout << Dijkstra(s, t);
    return 0;
}