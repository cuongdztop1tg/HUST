#include <bits/stdc++.h>

using namespace std;

int fibo(int n){
    if(n <= 1) return n;
    int i = 0, j = 1;
    for(int k = 2; k <= n; k++){
        int temp = j;
        j = j + i;
        i = temp;
    }
    return i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << fibo(n) << endl;
    }
    return 0;
}