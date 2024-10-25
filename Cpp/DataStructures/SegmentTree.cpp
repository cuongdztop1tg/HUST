#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6, inf = 1e9;
int TreeNode[maxN], a[maxN];

class SegmentTree {
    void Build(int id, int l, int r){
        if(l == r){
            TreeNode[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        Build(id, l, mid);
        Build(id, mid + 1, r);
        TreeNode[id] = min(TreeNode[2 * id], TreeNode[2 * id + 1]);
    }
    void Update(int id, int l, int r, int i, int val){
        if(i < l || i > r) return;
        if(l == r){
            TreeNode[id] = val;
            return;
        }
        int mid = (l + r) / 2;
        Update(id, l, mid, i, val);
        Update(id, mid + 1, r, i, val);
        TreeNode[id] = min(TreeNode[2 * id], TreeNode[2 * id + 1]);
    }
    int Query(int id, int l, int r, int u, int v){
        if(l > u || r < v) return inf;
        if(l >= u && v <= r){
            return TreeNode[id];
        }
        int mid = (l + r) / 2;
        int leftChild = Query(2 * id, l, mid, u, v);
        int rightChild = Query(2 * id + 1, mid + 1, r, u, v);
        return min(leftChild, rightChild);
    }
};

int main(){
    return 0;
}