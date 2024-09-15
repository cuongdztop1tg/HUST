#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7, maxN = 1e6 + 7;
int n, a[maxN], minVal[4 * maxN];

class segmentTree{
    public:
        void buildSegmentTree(int id, int l, int r){
            if(l == r){
                minVal[id] = a[l];
                return;
            }
            buildSegmentTree(id * 2, l, (l + r) / 2);
            buildSegmentTree(id * 2 + 1, (l + r) / 2 + 1, r);
            minVal[id] = min(minVal[id * 2], minVal[id * 2 + 1]);
        }

        void update(int id, int l, int r, int i, int val){
            if(l > i || r < i) return;
            if(l == r){
                minVal[id] = val;
                return;
            }
            update(id * 2, l, (l + r) / 2, i, val);
            update(id * 2 + 1, (l + r) / 2 + 1, r, i, val);
            minVal[id] = min(minVal[id * 2], minVal[id * 2 + 1]);
        }

        int getMin(int id, int l, int r, int u, int v){
            if(l > v || r < u) return inf;
            if(l >= u && r <= v){
                return minVal[id];
            }
            return min(getMin(id * 2, l, (l + r) / 2, u, v) , getMin(id * 2 + 1, (l + r) / 2 + 1, r, u, v));
        }
};

int main(){
    cin >> n;
    segmentTree tree;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    tree.buildSegmentTree(1, 1, n);
    long long sum = 0;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        sum += tree.getMin(1, 1, n, u + 1, v + 1);
    }
    cout << sum;
    return 0;
}