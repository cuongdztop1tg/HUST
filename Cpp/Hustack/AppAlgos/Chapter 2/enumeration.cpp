#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> solution;
vector<int> check;

void print(){
    for(int i = 1; i < solution.size(); i++){
        cout << solution[i] << " ";
    }
    cout << endl;
}

void Try(int k){
    for(int i = 1; i <= n; i++){
        if(check[i] == 0){
            solution[k] = i;
            check[i] = 1;
            if(k == n) print();
            else Try(k + 1);
            check[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    solution.resize(n + 1);
    check.resize(n + 1, 0);
    Try(1);
    return 0;
}