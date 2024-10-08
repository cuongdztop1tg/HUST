#include <bits/stdc++.h>

using namespace std; 

const int N = 50;
int near[N], d[N];
int V, E, weight = 0;
bool MST[N] = {false};
vector<pair<int, int>> T;
int c[5][5] = {{INT_MAX, 2, INT_MAX, 6, INT_MAX},
               {2, INT_MAX, 3, 8, 5},
               {INT_MAX, 3, INT_MAX, INT_MAX, 7},
               {6, 8, INT_MAX, INT_MAX, 9},
               {INT_MAX, 5, 7, 9, INT_MAX}};


int findMin(){
    int minD = INT_MAX, index = -1;
    for(int v = 1; v <= V; v++){
        if(!MST[v] && d[v] < minD){
            minD = d[v]; 
            index = v;
        }
    }
    return index;
}

void Prim(){
    MST[1] = true;
    for(int v = 1; v <= V; v++){
        d[v] = c[1][v];
        near[v] = 1;
    }
    d[1] = 0;

    for(int k = 1; k < V; k++){
        int v = findMin();
        if (v == -1) break;
        MST[v] = true;
        T.push_back({near[v], v});
        weight += c[near[v]][v];
        for(int u = 1; u <= V; u++){
            if(!MST[u] && c[v][u] < d[u]){
                d[u] = c[v][u];
                near[u] = v;
            }
        }
    }
}

int main(){
    cin >> V >> E;
    for(int i = 1; i <= V; i++)
        for(int j = 1; j <= V; j++)
            c[i][j] = INT_MAX;

    // for(int i = 0; i < E; i++){
    //     int x, y, w;
    //     cin >> x >> y >> w;
    //     c[x][y] = w;
    //     c[y][x] = w;
    // }
    
    Prim();

    cout << "Total weight of MST: " << weight << endl;
    cout << "Edges in the MST:\n";
    for(auto edge : T){
        cout << edge.first << " - " << edge.second << " : " << c[edge.first][edge.second] << endl;
    }

    return 0;
}