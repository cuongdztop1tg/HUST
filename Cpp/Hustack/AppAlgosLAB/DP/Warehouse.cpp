#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4 + 1;
int N, T, D;
int a[maxN], t[maxN];

void input(){
    cin >> N >> T >> D;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> t[i];
    }
}

void solve(){
    //dp[i][k]: the total amount can be picked up if we take goods from 
    //station 1 to i (i is taken) with total time = k
    vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));
    int res = 0;
    for(int i = 1; i <= N; i++){
        for(int k = 1; k <= T; k++){
            if(k < t[i]) dp[i][k] = 0;
            else{
                int m = 0;
                for(int j = i - D; j <= i - 1; j++){
                    if(j > 0) m = max(m, dp[j][k - t[i]]);
                }
                dp[i][k] = a[i] + m;
                res = max(res, dp[i][k]);
            }
        }
    }
    // for(int i = 1; i <= N; i++){
    //     for(int k = 1; k <= T; k++){
    //         cout << dp[i][k] << " ";
    //     }
    //     cout << endl;
    // }
    cout << res;
}

int main(){
    input();
    solve();
    return 0;
}