#include <bits/stdc++.h>

using namespace std;

vector<int> d;
int n, X, Count = 0;

bool comp(int &a, int &b){
    return a > b;
}

void solve(){
    sort(d.begin(), d.end(), comp);
    int cur = X;
    while(X > 0){
        for(int i = 0; i < d.size(); i++){
            if(cur - d[i] >= 0){
                cur -= d[i];
                Count++;
            }
        }
        if(X == cur){
            cout << -1;
            return;
        }
        else X = cur;
    }
    cout << Count;
}

int main(){
    cin >> n >> X;
    d.resize(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    solve();
    return 0;
}