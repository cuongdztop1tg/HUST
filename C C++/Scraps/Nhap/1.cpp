#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1] = {0};
    long int Q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cout << endl;
    long int prefixSum[n + 1][m + 1];
    for(int i = 0; i <= n; i++){
    	prefixSum[i][0] = 0;
	}
	for(int i = 0; i <= m; i++){
    	prefixSum[0][i] = 0;
	}
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + a[i][j];
        }
    }
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << prefixSum[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << prefixSum[r2][c2] - prefixSum[r1 - 1][c2] - prefixSum[r2][c1 - 1] + prefixSum[r1 - 1][c1 - 1] << endl;
    }
    return 0;
}