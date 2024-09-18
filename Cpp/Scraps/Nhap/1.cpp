#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

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
        long int k;
        if(cmd == "min_greater_or_equal"){
            cin >> k;
            auto it = lower_bound(a.begin(), a.end(), k);
            if(it == a.end()) cout << "NULL" << endl;
            else cout << *it << endl;
        }
        if(cmd == "min_greater"){
            cin >> k;
            auto it = upper_bound(a.begin(), a.end(), k);
            if(it == a.end()) cout << "NULL" << endl;
            else cout << *it << endl;
        }
        if(cmd == "insert"){
            cin >> k;
            auto it = lower_bound(a.begin(), a.end(), k);
            a.insert(it, k);
        }
        if(cmd == "remove"){
            cin >> k;
            auto it = lower_bound(a.begin(), a.end(), k);
            if(it != a.end() && *it == k){
                a.erase(it);
            }
        }
    }
    return 0;
}