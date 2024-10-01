#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set<int> a;
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        a.insert(value);
    }
    string cmd;
    while(1){
        cin >> cmd;
        int k;
        if(cmd == "#") break;
        else if(cmd == "min_greater_equal"){
            cin >> k;
            auto it = a.lower_bound(k);
            if(it == a.end()) cout << "NULL" << endl;
            else cout << *it << endl;
        }
        else if(cmd == "min_greater"){
            cin >> k;
            auto it = a.upper_bound(k);
            if(it == a.end()) cout << "NULL" << endl;
            else cout << *it << endl;
        }
        else if(cmd == "insert"){
            cin >> k;
            a.insert(k);
        }
        else if(cmd == "remove"){
            cin >> k;
            a.erase(k);
        }
    }
    return 0;
}