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
            dp[i] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(a[i] > a[j] + 1) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        cout << *max_element(dp + 1, dp + n + 1) << endl;
    }
    return 0;
}