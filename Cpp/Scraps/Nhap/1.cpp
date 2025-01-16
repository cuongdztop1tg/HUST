#include <bits/stdc++.h>

using namespace std;

int res = 0;
int bin[7];

void Try(int k, int n){
    if(k == n){
        res++;
        return;
    }
    for(int i = 0; i <= 1; i++){
        if(k >= 2 && bin[k - 1] == 0 && bin[k - 2] == 0 && i == 0) continue;
        bin[k] = i;
        Try(k + 1, n);
        bin[k] = -1;
    }
}

int main(){
    Try(0, 6);
    cout << res;
    return 0;
}