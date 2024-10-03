#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int red[N][N];
int n, m;
long long h[N];
int R[N];
int L[N];
int ans;
vector<int> s;


void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> red[i][j];
        }
    }
}

long long compute(){
    h[0] = -1;
    h[m + 1] = -1;
    s.clear();
    for(int j = 1; j <= m + 1; j++){
        while(!s.empty() && h[j] < h[s[s.size() - 1]]){
            R[s[s.size() - 1]] = j;
            s.pop_back();
        }
        s.push_back(j);
    }

    for(int j = m; j >= 0; j--){
        while(!s.empty() && h[j] < h[s[s.size() - 1]]){
            L[s[s.size() - 1]] = j;
            s.pop_back();
        }
        s.push_back(j);
    }

    unsigned long long ans = 0;
    for(int i = 0; i <= m; i++){
        unsigned long long c = (R[i] - L[i] - 1)*h[i];
        ans = ans < c ? c : ans;
    }
    return ans;
}

void solve(){
    long long ans = 0;
    for(int i = 1; i <= m; i++) h[i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(red[i][j] == 1) h[j]++;
            else h[j] = 0;
        }
        long long t = compute();
        if(t > ans) ans = t;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    return 0;
}