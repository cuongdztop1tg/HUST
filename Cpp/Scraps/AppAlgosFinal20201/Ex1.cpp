#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m, count = 0;
        unordered_set<long> a;
        unordered_set<long> b;
        cin >> n;
        long x;
        while(n--){
            cin >> x;
            a.insert(x);
        }
        cin >> m;
        while(m--){
            cin >> x;
            b.insert(x);
        }
        for(auto i : a){
            if(b.find(i) != b.end()) count++;
        }
        cout << count << endl;
    }
    return 0;
}