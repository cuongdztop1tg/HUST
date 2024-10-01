#include <bits/stdc++.h>

using namespace std;

int n, k, opt = INT_MAX, cur = 0, load = 0;
vector<bool> visited;
vector<int> des;
vector<vector<int>> c;

void BUS(int k){
    for(int i = 1; i <= 2*n; i++){
        if(!visited[i]){
            if(i <= n) load++;
            else load--;
            visited[i] = true;
            des[k] = i;
            cur += des[des[k - 1]][i];
            if(k == 2*n){
                
            }
        }
    }
}

int main(){
    cin >> n >> k;

    return 0;
}