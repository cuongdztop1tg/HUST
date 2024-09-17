#include <bits/stdc++.h>

using namespace std;
const long int maxN = 1000001;
long int n;
int a[maxN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long int prefixSum[maxN];
    prefixSum[0] = 0;
    for(int i = 1; i <= n; i++){
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    int Q;
    cin >> Q;
    for(int k = 0; k < Q; k++){
        int i, j;
        cin >> i >> j;
        cout << prefixSum[j] - prefixSum[i - 1] << endl;
    }
    return 0;
}