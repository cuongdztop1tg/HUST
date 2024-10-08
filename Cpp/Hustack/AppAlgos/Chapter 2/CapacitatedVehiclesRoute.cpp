#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;
int n, K, Q, y[MAX], x[MAX], segments = 0, nbR = 0, c[MAX][MAX], f = 0, fopt = INT_MAX;
int visited[MAX] = {0}, d[MAX], load[MAX] = {0}, cmin = INT_MAX;

bool check(int v, int k){
    if(v == 0) return true;
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

void TryX(int s, int k){
    
}

void TryY(int k){
    int s;
    if(y[k - 1] > 0) s = y[k - 1] + 1;
    else s = 0;
    for(int v = s; v <= n; v++){
        if(check(v, k)){
            y[k] = v;
            if(v > 0){
                visited[v] = 1;
                f += c[0][v];
                load[k] += d[v];
                segments++;
            }
            if(k == K){
                nbR = segments;
            }
            else TryY(k + 1);
            if(v > 0){
                visited[v] = 0;
                f -= c[0][v];
                load[k] -= d[v];
                segments--;
            }
        }
    }
}

int main(){
    cin >> n >> k >> Q;
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cin >> c[i][j];
            if(c[i][j] < cmin) cmin = c[i][j];
        }
    }
    Try(1);
    return 0;
}