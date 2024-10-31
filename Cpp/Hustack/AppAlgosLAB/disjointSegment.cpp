#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
pair<int, int> a[N];

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.second < p2.second;
}

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
}

void solve(){
    int res = 0;
    int last = -1;
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        if(a[i].first > last){
            res++;
            last = a[i].second;
        }
    }
    cout << res;
}

int main(){
    input();
    solve();
    return 0;
}