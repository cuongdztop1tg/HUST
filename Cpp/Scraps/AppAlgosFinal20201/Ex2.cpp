#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        long a[N], dp[N];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            dp[a[i]] = 0;
        }
        int maxLIS = 0;
        for(int i = 1; i <= n; i++){
            dp[a[i]] = 1 + dp[a[i] - 1];
        }
        cout << *max_element(dp + 1, dp + n + 1) << endl;
    }
    return 0;
}