#include <bits/stdc++.h>

using namespace std;

int V, E;
int D[100][100];
int P[100][100];

void print(int k){
    cout << "D(" << k << ")" << endl;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    cout << "P(" << k << ")" << endl;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cout << P[i][j] << " ";
        }
        cout << endl;
    }
}

void FloydWarshall(){
    for(int k = 1; k <= V; k++){
        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
        }
        //Print D and P
        //print(k);
    }
}

int main(){
    cin >> V >> E;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            D[i][j] = 999;
            P[i][j] = -1;
        }
    }
    for(int i = 0; i < E; i++){
        int x, y, w;
        cin >> x >> y >> w;
        D[x][y] = w;
        P[x][y] = x;
    }
    for(int i = 1; i <= V; i++){
        D[i][i] = 0;
    }
    //print(0);
    FloydWarshall();
    int source, destination;
    cin >> source >> destination;
    int tracking = destination;
    vector<int> path;
    bool pathFound = true;
    while(1){
        if(P[source][tracking] == -1){ 
            pathFound = false;
            break;
        }
        path.push_back(tracking);
        tracking = P[source][tracking];
        if(P[source][tracking] == source){
            path.push_back(tracking);
            path.push_back(source);
            break;
        }
    }
    if(pathFound){
        for(int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
        cout << endl;
        cout << "Path length: " << D[source][destination];
    }
    return 0;
}