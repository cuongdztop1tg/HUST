#include <bits/stdc++.h>

using namespace std;

int n, L;
int cnt = 0;
vector<pair<int, int>> coordinate;
int path[100];

int calDis(int i, int j){
    return (abs(coordinate[i].first - coordinate[j].first) + abs(coordinate[i].second - coordinate[j].second));
}

void Try(vector<bool>& visited, int curDis, int k){
    if(k == n && curDis + calDis(path[n - 1], path[0]) <= L){
        cnt++;
        return;
    }
    if(curDis > L){
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            path[k] = i;
            Try(visited, curDis + calDis(path[k], path[k - 1]), k + 1);
            visited[i] = false;
            path[k] = -1; //not necessary
        }
    }
}

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        coordinate.push_back({x, y});
    }
    cin >> L;
}

void solve(){
    vector<bool> visited(n + 1, false);
    //start at 0
    path[0] = 0;
    visited[0] = true;
    Try(visited, 0, 1);
    cout << cnt;
}

int main(){
    input();
    solve();
    return 0;
}