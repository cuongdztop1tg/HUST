#include <bits/stdc++.h>
#include <vector>

using namespace std;
const int maxN = 1000;
void BFS(vector<vector<int>>graph, int s, int size){
    queue<int> q;
    vector<bool> visited(size, false);

    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        cout << u << " ";
        q.pop();
        for(int i = 0; i < size; i++){
            if(graph[u][i] == 1 && !visited[i]){
                visited[i] == true;
                q.push(i);
            }
        }
    }
}

int main(){
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
    return 0;
}