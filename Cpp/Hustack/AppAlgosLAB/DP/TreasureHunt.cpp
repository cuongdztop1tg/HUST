#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> dp;
vector<tuple<int, int, long long>> treasures; //{x, y, value};

bool comp(const tuple<int, int, long long>& a, const tuple<int, int, long long>& b){
    //sort prioritze: y
    //if y1 == y1, priortize x
    if(get<1>(a) < get<1>(b)) return true;
    if(get<1>(a) == get<1>(b) && get<0>(a) < get<0>(b)) return true;
    return false;
}

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        long long value;
        cin >> x >> y >> value;
        treasures.push_back({x, y, value});
    }
    treasures.push_back({0, 0, 0});
    sort(treasures.begin(), treasures.end(), comp);
    // cout << endl;
    // for(auto i : treasures){
    //     cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    // }
    dp.resize(n + 1);
}

void solve(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < i; j++){
            //if x of treasure[j] < x of treasures[i]
            if(get<0>(treasures[j]) <= get<0>(treasures[i]))
                dp[i] = max(dp[i], dp[j] + get<2>(treasures[i]));
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}

int main(){
    input();
    solve();
    return 0;
}