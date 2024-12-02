#include <bits/stdc++.h>

using namespace std;

int n, m, load = 0, opt = INT_MAX, minDistance = INT_MAX, cur = 0;
int destination[1000], c[1000][1000];
bool visited[1000];

bool check(int i){
    if(visited[i]) return false;
    if(i > n){
        if(!visited[i - n]) return false;
    }
    else{
        if(load + 1 > m) return false;
    }
    return true;
}

void updateBest(){
    int total = cur + c[destination[2 * n]][destination[0]];
    if(total < opt) opt = total;
}

void BUS(int k){
    for(int i = 1; i <= 2 * n; i++){
        if(check(i)){
            if(i <= n) load++;
            else load--;

            destination[k] = i;
            visited[i] = true;
            cur += c[destination[k - 1]][destination[k]];

            if(k == 2 * n) updateBest();
            else{
                if(cur + (2 * n - k + 1)*minDistance < opt) BUS(k + 1);
            }

            if(i <= n) load--;
            else load++;
            visited[i] = false;
            cur -= c[destination[k - 1]][destination[k]];
        }
    }
}

void input(){
    cin >> n >> m;
    for(int i = 0; i <= 2 * n; i++){
        for(int j = 0; j <= 2 * n; j++){
            cin >> c[i][j];
            if(i != j && c[i][j] < minDistance) minDistance = c[i][j];
        }
    }
    destination[0] = 0;
}

int main(){
    input();
    BUS(1);
    cout << opt;
    return 0;
}