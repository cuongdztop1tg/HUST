#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
const int maxN = 1000001;
long int n, M, a[maxN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> M;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int L = 0, R = n - 1, count = 0;
    long int sum;
    while(L < R){
        sum = a[L] + a[R];
        if(sum < M) L++;
        if(sum > M) R--;
        if(sum == M){
            count++;
            L++, R--;
        }
    }
    cout << count;
    return 0;
}