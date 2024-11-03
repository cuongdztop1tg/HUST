#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int a[N];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        long res = 0;
        int k = 1;
        int size = n;
        while(size > 0){
            int time = 0;
            int step = 2 * k;
            for(int i = 0; i < n; i += step){
                if(k + i > n) break;
                a[i] += a[k + i];
                if(a[i] > time) time = a[i];
                size--;
            }
            res += time;
            k *= 2;
        }
        cout << res << endl;
    }
    return 0;
}