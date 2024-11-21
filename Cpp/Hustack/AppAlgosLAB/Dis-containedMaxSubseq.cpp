#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
int a[N], S[N];
int n, L1, L2, ans;

int main(){
    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; i++) cin >> a[i];
    deque<int> dq;
    ans = 0;
    for(int i = 1; i <= n; i++){
        while(!dq.empty() && dq.front() < i - L2) dq.pop_front();
        int j = i - L1;
        if(j >= 1){
            while(!dq.empty() && S[dq.back()] < S[j]) dq.pop_back();
            dq.push_back(j);
        }
        S[i] = a[i] + (dq.empty() ? 0 : S[dq.front()]);
        ans = max(ans, S[i]);
    }
    cout << ans;
    return 0;
}