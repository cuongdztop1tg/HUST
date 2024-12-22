#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> visited;
int res[100];
int cnt = 0;

void Try(int k){
    if(k == n + 1){
        cnt++;
        return;
    }
    if()
    for(int i = 1; i <= n; i++){
        if(!visited[i] && (k == 1 || (res[k - 1] + 1 != i && res[k - 1] - 1 != i))){
            res[k] = i;
            visited[i] = true;
            Try(k + 1);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    visited.resize(n + 1, false);
    Try(1);
    cout << cnt;
    return 0;
}