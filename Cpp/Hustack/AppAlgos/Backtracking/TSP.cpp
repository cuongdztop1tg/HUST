#include <bits/stdc++.h>

using namespace std;

int n, opt = INT_MAX, cur = 0, minDistance = INT_MAX, total;
vector<vector<int>> d;
vector<bool> visited;
vector<int> city;
vector<int> path;

void TSP(int k){
    for(int i = 2; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            city[k] = i;
            cur += d[city[k - 1]][city[k]];
            if(k == n){
                total = cur + d[city[n]][city[1]];
                if(total < opt){
                    opt = total;
                    for(int i = 1; i <= n; i++){
                        path[i] = city[i];
                    }
                    cout << opt << endl;
                    for(int i = 1; i <= n; i++) cout << path[i] << " ";
                    cout << endl;
                }
            }
            else{
                if(cur + (n - k + 1)*minDistance < opt) TSP(k + 1);
            }
            cur -= d[city[k - 1]][city[k]];
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n;
    d.resize(n + 1, vector<int> (n + 1));
    visited.resize(n + 1, false);
    city.resize(n + 1);
    path.resize(n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> d[i][j];
            if(i != j && d[i][j] < minDistance) minDistance = d[i][j];
        }
    }
    city[1] = 1;
    TSP(2);
    // cout << opt << endl;
    // for(int i = 1; i <= n; i++) cout << path[i] << " ";
    return 0;
}