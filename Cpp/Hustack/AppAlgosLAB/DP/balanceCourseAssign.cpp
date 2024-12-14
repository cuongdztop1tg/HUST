#include <bits/stdc++.h>

using namespace std;

int n, m;
int load[100];
int x[100];
int res = INT_MAX;
bool conflict[100][100];
vector<int> T[100];

void input(){
    cin >> m >> n;
    for(int t = 1; t <= m; t++){
        int k;
        cin >> k;
        for(int i = 1; i <= k; i++){
            int c;
            cin >> c;
            T[c].push_back(t);
        }
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        conflict[x][y] = true;
        conflict[y][x] = true;
    }
}

bool check(int t, int k){
    for(int i = 1; i <= k - 1; i++){
        if(conflict[k][i] && x[i] == t) return false;
    }
    return true;
}

void update(){
    int maxLoad = 0;
    for(int i = 1; i <= m; i++){
        maxLoad = max(maxLoad, load[i]);
    }
    if(maxLoad < res) res = maxLoad;
}

void Try(int k){
    for(int i = 0; i < T[k].size(); i++){
        int t = T[k][i];
        if(check(t, k)){
            x[k] = t;
            load[t]++;
            if(k == n) update();
            else{
                if(load[t] < res) Try(k + 1);
            }
            load[t]--;
        }
    }
}

int main(){
    input();
    for(int i = 1; i <= m; i++) load[i] = 0;
    Try(1);
    cout << res;
    return 0;
}