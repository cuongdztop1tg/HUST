#include <bits/stdc++.h>
#include <vector>

using namespace std;

void BFS(vector<vector<int>> graph, int s, int size){
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

void DFS(vector<vector<int>> graph, int s, int size){
    stack<int> stack;
    vector<bool> visited(size, false);

    stack.push(s);
    visited[s] = true;

    while(!stack.empty()){
        int u = stack.top();
        cout << char(u + 97) << " ";
        stack.pop();
        for(int i = 0; i < size; i++){
            if(graph[i][u] == 1 & !visited[i]){
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
    //a, b, c, d, e, f, g, h-> 0->7
    int size, s;
    cin >> size;
    vector<vector<int>> graph(size, vector<int> (size));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cin >> graph[i][j];
        }
    }
    cin >> s;
    BFS(graph, s, size);
    DFS(graph, s, size);
    return 0;
}