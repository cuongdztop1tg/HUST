#include <bits/stdc++.h>

using namespace std;

int cnt;

bool comp(int *x, int n){
    if(x[1] == 0 || x[3] == 0) return false;
    int HUST = 1000*x[1] + 100*x[2] + 10*x[3] + x[4];
    int SOICT = 10000*x[3] + 1000*x[5] + 100*x[6] + 10*x[7] + x[4];
    return (HUST + SOICT == n);
}

void Try(int *x, int *chosen, int k, int n){
    for(int i = 0; i <= 9; i++){
        if(!chosen[i]){
            x[k] = i;
            chosen[i] = 1;
            if(k == 7){
                if(comp(x, n)) cnt++;
            }
            else Try(x, chosen, k + 1, n);
            chosen[i] = 0;
        }
    }
}

int main(){
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        cnt = 0;
        int x[8], chosen[10] = {0};
        Try(x, chosen, 1, n);
        cout << cnt << endl;
    }
    return 0;
}