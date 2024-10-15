#include <bits/stdc++.h>

using namespace std;

vector<int> d;
int n, X, Count = 0;

bool comp(int &a, int &b){
    return a > b;
}

bool exchange(){
    for(int i = 0; i < d.size(); i++){
        if(X - d[i] >= 0){
            X -= d[i];
            return true;
        }
    }
    return false;
}

void solve(){
    sort(d.begin(), d.end(), comp);
    while(X > 0){
        if(exchange()) Count++;
        else{
            cout << -1;
            return;
        }
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