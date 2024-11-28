#include <bits/stdc++.h>

using namespace std;

int main(){
    int V, E;
    cin >> V >> E;
    vector<int> deg(V + 1);
    for(int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
    }
    for(int i = 1; i <= V; i++){
        if(i % 2 != 0) cout << deg[i] << " ";
    }
    return 0;
}