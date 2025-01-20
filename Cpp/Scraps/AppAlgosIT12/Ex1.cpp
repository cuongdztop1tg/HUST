#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, X, Y, count = 0;
    cin >> n >> X >> Y;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= X && a[i] <= Y) count++;
    }
    cout << count;
    return 0;
}