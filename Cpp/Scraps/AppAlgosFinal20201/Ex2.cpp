#include <bits/stdc++.h>

using namespace std;

int LIS(vector<long>& a){
    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<long> a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cout << LIS(a) << endl;
    }
    return 0;
}