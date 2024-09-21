#include <bits/stdc++.h>
#include <vector>

using namespace std;

void addEdgeUndirectedGraph(vector<vector<int>>& graph, int initial, int terminal, int size){
    graph[initial][terminal] = 1;
    graph[terminal][initial] = 1;
}

void addEdgeDirectedGraph(vector<vector<int>>& graph, int initial, int terminal, int size){
    graph[initial][terminal] = 1;
}

void BFS(vector<vector<int>>& graph, int s, int size){
    queue<int> queue;
    vector<bool> visited(size, false);

    visited[s] = true;
    queue.push(s);

    while(!queue.empty()){
        int u = queue.front();
        cout << char(u + 97) << " ";
        queue.pop();
        for(int i = 0; i < size; i++){
            if(graph[u][i] == 1 && !visited[i]){
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

void DFS(vector<vector<int>>& graph, int s, int size){
    stack<int> stack;
    vector<bool> visited(size, false);

    stack.push(s);
    visited[s] = true;

    while(!stack.empty()){
        int u = stack.top();
        cout << char(u + 97) << " ";
        stack.pop();
        for(int i = 0; i < size; i++){
            if(graph[u][i] == 1 & !visited[i]){
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
    int size;
    cin >> size;
    vector<vector<int>> graph(size, vector<int> (size));
    return 0;
}