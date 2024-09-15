#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7, maxN = 1e6 + 7;
long int n, a[maxN], minVal[4 * maxN];

class segmentTree{
    public:
        void buildSegmentTree(int id, int l, int r){
            if(l == r){
                minVal[id] = a[l];
                return;
            }
            long int mid = (l + r) / 2;
            buildSegmentTree(id * 2, l, mid);
            buildSegmentTree(id * 2 + 1, mid + 1, r);
            minVal[id] = min(minVal[id * 2], minVal[id * 2 + 1]);
        }

        void update(int id, int l, int r, int i, int val){
            if(l > i || r < i) return;
            if(l == r){
                minVal[id] = val;
                return;
            }
            long int mid = (l + r) / 2;
            update(id * 2, l, mid, i, val);
            update(id * 2 + 1, mid + 1, r, i, val);
            minVal[id] = min(minVal[id * 2], minVal[id * 2 + 1]);
        }

        int query(int id, int l, int r, int u, int v){
            if(l > v || r < u) return inf;
            if(l >= u && r <= v){
                return minVal[id];
            }
            long int mid = (l + r) / 2;
            long int leftChild = query(id * 2, l, mid, u, v);
            long int rightChild = query(id * 2 + 1, mid + 1, r, u, v);
            return min(leftChild, rightChild);
        }
};

int main(){
    // I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);     

    cin >> n;
    segmentTree tree;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    tree.buildSegmentTree(1, 1, n);
    long long sum = 0;
    long int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        long int u, v;
        cin >> u >> v;
        sum += tree.query(1, 1, n, u + 1, v + 1);
    }
    cout << sum;
    return 0;
}