#include <bits/stdc++.h>

using namespace std;

int n, M, Count = 0, f = 0;
int x[10000];
int t[10000];
int a[10000];

void initT(){
    t[1] = a[1];
    for(int i = 2; i <= n; i++){
        t[i] = t[i - 1] + a[i];
    }
}

void Try(int k){
    for(int i = 1; i <= (M - f - (t[n] - t[k])) / a[k]; i++){
        x[k] = i;
        f += x[k]*a[k];
        if(k == n){
            if(f == M) Count++;
        }
        else Try(k + 1);
        f -= x[k]*a[k];
    }
}

int main(){
    cin >> n >> M;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    initT();
    Try(1);
    cout << Count;
    return 0;
}