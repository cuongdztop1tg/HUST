#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
int n, m, r, c;

class pos{
    public:
        int row, col;
        string path;
};

bool isValid(int row, int col){
    return (a[row][col] == 0 && row < n && row >= 0 && col < m && col >= 0);
}

void solve(){
    queue<pos> q;
    vector<vector<bool>> visited(n + 1, vector<bool> (m + 1, false));

    q.push({r, c, ""});
    visited[r][c] = true;

    while(!q.empty()){
        pos u = q.front();
        q.pop();

        if(u.row == 0 || u.row == n - 1 || u.col == 0 || u.col == m - 1){
            cout << u.path.length() + 1 << endl;
            //cout << u.path;
            return;
        }

        int moveR[4] = {-1, 1, 0, 0};
        int moveC[4] = {0, 0, -1, 1};
        char direction[] = {'U', 'D', 'L', 'R'};

        for(int i = 0; i < 4; i++){
            int newR = u.row + moveR[i];
            int newC = u.col + moveC[i];
            if(isValid(newR, newC) && !visited[newR][newC]){
                visited[newR][newC] = true;
                q.push({newR, newC, u.path + direction[i]});
            }
        }
    }
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> r >> c;
    r--; c--;
    a.resize(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    solve();
    return 0;
}