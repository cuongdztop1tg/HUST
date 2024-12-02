#include <bits/stdc++.h>
using namespace std;
 
int mod=1e9+7;
 
int f[1000006];
 
int main() {
    int n,s; cin >> n >> s;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    f[0]=0;
    for(int i=1;i<=s;i++){
        f[i]=1e9;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=s; j++){
            if(j>=a[i]) f[j]=min(f[j],f[j-a[i]]+1);
            f[j]%=mod;
        }
    }
    if(f[s]==1e9) cout << "-1" << endl;
    else cout << f[s] << endl;
 
 
}