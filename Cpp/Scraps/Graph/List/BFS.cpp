#include <bits/stdc++.h>

using namespace std;

int V;
vector<vector<int>> graph;

void BFS(int s){
    queue<int> queue;
    vector<bool> visited(V, false);

    visited[s] = true;
    queue.push(s);

    while(!queue.empty()){
        int u = queue.front();
        cout << u << " ";
        queue.pop();
        for(auto i : graph[u]){
            if(!visited[i]){
                visited[i] = true;
                queue.push(i);
            }
        }
    }
    cout << endl;
}

int main(){
    cin >> V;
    graph.resize(V);
    while(1){
        int initial, terminal;
        cin >> initial;
        if(initial == -1) break;
        cin >> terminal;
        graph[initial].push_back(terminal);
        //graph[terminal].push_back(initial);
    }
    int s;
    cin >> s;
    BFS(s);
    return 0;
}