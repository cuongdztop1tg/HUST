#include <bits/stdc++.h>

using namespace std;

int n, X;
vector<int> d;

int main(){
    cin >> n >> X;
    d.resize(n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    vector<int> dp(X + 1, X + 1);
    dp[0] = 0;
    for(int i = 1; i <= X; i++){
        for(int j = 0; j < n; j++){
            if(i - d[j] >= 0){
                dp[i] = min(dp[i], 1 + dp[i - d[j]]);
            }
        }
    }
    if(dp[X] == X + 1) cout << -1;
    else cout << dp[X];
    return 0;
}