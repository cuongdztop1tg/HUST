#include <bits/stdc++.h>

using namespace std;
const int N = 21;
int n, Q;
int a[N], d[N][N], route[N], visited[N], res[N];
int load = 0, dis = 0, minDis = INT_MAX, dmin = INT_MAX;

void input(){
    cin >> n >> Q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        visited[i] = 0;
    }
    route[0] = 0;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            cin >> d[i][j];
            if (i != j && d[i][j] < dmin) dmin = d[i][j];
        }
    }
}

void update(){
    for(int i = 1; i <= n; i++){
        res[i] = route[i];
    }
}

void Try(int k){
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            route[k] = i;
            load += a[i];
            dis += d[route[k - 1]][route[k]];
            visited[i] = 1;
            if(load >= Q){
                int totalDis = dis + d[route[k]][route[0]];
                if(totalDis < minDis){
                    minDis = totalDis;
                    update();
                }
            }
            else{
                int bound = dis + dmin;
                if(bound <= minDis) Try(k + 1);
            }
            visited[i] = 0;
            load -= a[i];
            dis -= d[route[k - 1]][route[k]];
        }
    }
}
int main(){
    input();
    Try(1);
    cout << minDis << endl;
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(res[i]) count++;
    }
    cout << count << endl;
    for(int i = 1; i <= n; i++){
        if(res[i]) cout << res[i] << " ";
    }
    return 0;
}