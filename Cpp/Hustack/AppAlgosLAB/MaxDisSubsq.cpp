#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int t, n, c, a[N];

bool check(int D){
    int s1 = 1;
    int i = 1, j = 2;
    while(i < n){
        while(j <= n && a[j] - a[i] < D) j++;
        if(j <= n) s1++;
        if(s1 >= c) return true;
        i = j;
        j++;
    }
    return false;
}

int solve(){
    int l = 0, r = a[n] - a[1];
    while(l <= r){
        int D = (l + r) / 2;
        if(check(D)) l = D + 1;
        else r = D;
    }
    return r;
}
int main(){
    cin >> t;
    while(t--){
        cin >> n >> c;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        cout << solve() << endl;
    }
    return 0;
}