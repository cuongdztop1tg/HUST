#include <bits/stdc++.h>

using namespace std;

int n,k;
int c[1000][1000];
int visited[100000];
int f=0;
int fopt=99999;
int load=0;
int cmin=99999;
int x[100000];


int check(int v){
    if (visited[v]==1) return 0;
    if (v>n){
        if (visited[v-n]==0) return 0;
    }
    else{
        if (load+1>k) return 0;
    }
    return 1;
}

void updateBest(){
    if (f+c[x[2*n]][x[0]]<fopt){
        fopt = f+c[x[2*n]][x[0]];
    }
}
void Try(int k){
    for (int i=1;i<=2*n;i++){
        if (check(i)==1){
            if (i<=n) load++;
            else load--;
            x[k]=i;
            visited[i]=1;
            f+=c[x[k-1]][x[k]];
            if (k==2*n) updateBest();
            else{
                if (f+cmin*(2*n+1-k)<fopt) Try(k+1);
            }
            if (i<=n) load--;
            else load++;
            f-=c[x[k-1]][x[k]];
            visited[i]=0;
        }
    }
}

void input(){
    cin>>n>>k;
    for (int i=0;i<=2*n;i++)
        for (int j=0;j<=2*n;j++) {
            cin>>c[i][j];
            if (i != j && c[i][j] < cmin) 
                cmin = c[i][j];
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    x[0]=0;
    visited[0]=1;
    Try(1);
    cout<<fopt;
}