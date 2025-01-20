#include <bits/stdc++.h>

using namespace std;
int n, LB, UB, Count = 0;
vector<int> a;

void Try(int index, int sum){
    if(sum >= LB && sum <= UB){
        Count++;
    }
    for(int i = index; i < n; i++){
        if(i != index && a[i] == a[i - 1]) continue;
        if(sum + a[i] > UB) continue;
        Try(i + 1, sum + a[i]);
    }
}
int main(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> LB >> UB;
    Try(0, 0);
    cout << Count;
    return 0;
}