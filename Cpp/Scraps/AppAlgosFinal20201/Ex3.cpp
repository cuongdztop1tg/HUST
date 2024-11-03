#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        long res = 0;
        int k = 1;
        int size = a.size();
        while(size > 0){
            int time = 0;
            int step = 2 * k;
            for(int i = 0; i < a.size(); i += step){
                a[i] += a[k + i];
                if(a[i] > time) time = a[i];
                size--;
            }
            for(int i = 0; i < a.size(); i++){
                cout << a[i] << " ";
            }
            cout << endl;
            res += time;
            k++;
        }
        cout << res << endl;
    }
    return 0;
}