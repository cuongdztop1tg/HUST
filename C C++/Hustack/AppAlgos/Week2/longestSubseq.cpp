#include <bits/stdc++.h>

using namespace std;
const int maxN = 1000001;
int a[maxN], n, Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> Q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long int L = 0, res = 0, sum = 0;
    for(int R = 0; R < n; R++){
        sum += a[R];
        while(sum > Q){
            sum -= a[L];
            L++;
        }
        res = max(res, R - L + 1);
    }
    cout << res;
    return 0;
}