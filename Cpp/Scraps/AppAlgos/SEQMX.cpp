#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    float maxSum, curSum = 0.0;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i < k) curSum += a[i];
    }
    maxSum = curSum;
    //Sliding window
    for(int i = 1; i < n - k + 1; i++){
        curSum = curSum - a[i - 1] + a[i + k - 1];
        maxSum = max(maxSum, curSum);
    }
    cout << setprecision(6) << maxSum / k;
    return 0;
}