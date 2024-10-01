#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long int n;
    cin >> n;
    vector<long int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    string cmd;
    while(1){
        cin >> cmd;
        if(cmd == "#") break;
        if(cmd == "next"){
            int k;
            cin >> k;
            auto it = upper_bound(a.begin(), a.end(), k);
            if(it == a.end()) cout << -1 << endl;
            else cout << a[it - a.begin()] << endl;
        }
    }
    return 0;
}
