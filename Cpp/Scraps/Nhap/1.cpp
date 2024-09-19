#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    long int n, value;
    set<long int> a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        a.insert(value);
    }
    string cmd;
    while(1){
        cin >> cmd;
        if(cmd == "#") break;
        long int k;
        if(cmd == "min_greater_or_equal"){
            cin >> k;
            auto it = a.lower_bound(k);
            if(it == a.end()) cout << "NULL" << endl;
            else cout << *it << endl;
        }
        if(cmd == "min_greater"){
            cin >> k;
            auto it = a.upper_bound(k);
            if(it == a.end()) cout << "NULL" << endl;
            else cout << *it << endl;
        }
        if(cmd == "insert"){
            cin >> k;
            a.insert(k);
        }
        if(cmd == "remove"){
            cin >> k;
            a.erase(k);
        }
    }
    return 0;
}