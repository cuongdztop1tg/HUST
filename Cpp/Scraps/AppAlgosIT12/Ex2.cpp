#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, X, Y, m;
    cin >> n >> X >> Y;
    vector<int> a(n + 1);
    vector<int> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }
    cin >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        int sum = prefix[j] - prefix[i - 1];
        if(sum >= X && sum <= Y) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}