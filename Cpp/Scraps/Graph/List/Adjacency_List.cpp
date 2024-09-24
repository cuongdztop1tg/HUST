#include <bits/stdc++.h>
#include <vector>
using namespace std;

void addEdgeUndirectedGraph(vector<vector<int>>& graph, int initial, int terminal){
    if(initial >= graph.size()) graph.resize(initial + 1);
    if(terminal >= graph.size()) graph.resize(terminal + 1);
    graph[initial].push_back(terminal);
    graph[terminal].push_back(initial);
}

void addEdgeDirectedGraph(vector<vector<int>>& graph, int initial, int terminal){
    if(initial >= graph.size()) graph.resize(initial + 1);
    if(terminal >= graph.size()) graph.resize(terminal + 1);
    graph[initial].push_back(terminal);
}

void BFS(vector<vector<int>>& graph, int s){
    queue<int> queue;
    vector<bool> visited(graph.size(), false);

    visited[s] = true;
    queue.push(s);

    while(!queue.empty()){
        int u = queue.front();
        cout << char(u + 97) << " ";
        queue.pop();
        for(auto i : graph[u]){
            if(!visited[i]){
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

void DFS(vector<vector<int>>& graph, int s){
    stack<int> stack;
    vector<bool> visited(graph.size(), false);

    visited[s] = true;
    stack.push(s);

    while(!stack.empty()){
        int u = stack.top();
        cout << char(u + 97) << " ";
        stack.pop();
        for(auto i : graph[u]){
            if(!visited[i]){
                visited[i] = true;
                stack.push(i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}