#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, MOD = 1e9 + 7;
int n;
int a[N], ta[N];

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

int countMerge(int L, int M, int R){
    int i = L, j = M + 1, k = L, count = 0;
    while(i <= M && j <= R){
        if(a[i] <= a[j]) ta[k++] = a[i++];
        else{
            ta[k++] = a[j++];
            count = (count + (M - i + 1)) % MOD;
        }
    }
    while(i <= M) ta[k++] = a[i++];
    while(j <= R) ta[k++] = a[j++];
    for(int i = L; i <= R; i++) a[i] = ta[i];
    return count;
}

int countInv(int L, int R){
    int count = 0, M;
    if(L < R){
        M = (L + R) / 2;
        count = (count + countInv(L, M)) % MOD;
        count = (count + countInv(M + 1, R)) % MOD;
        count = (count + countMerge(L, M, R)) % MOD;
    }
    return count;
}


int main(){
    input();
    cout << countInv(1, n);
    return 0;
}