#include <bits/stdc++.h>

using namespace std;

int X[1000];
int n;
int ans = 0;

int main(){
    ios_base :: sync_with_stdio(0); 
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>X[i];
    int low = 1;
    int high = n;
    while (low < high){
        int mid = (low + high) / 2;
        if (X[mid]==0) low = mid+1;
        else high = mid;
    }
    if (low == high && X[low]==0) cout<<-1; 
    else cout<<high;
}