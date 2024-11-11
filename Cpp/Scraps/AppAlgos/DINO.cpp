#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    stack<int> C;
    queue<int> H;
    string cmd;
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for(int i = n; i >= 1; i--){
        C.push(p[i]);
    }
    cin >> cmd;
    for(auto c : cmd){
        int dino;
        if(c == 'C' && !C.empty()){
            dino = C.top();
            C.pop();
            H.push(dino);
            continue;
        }
        if(c == 'H' && !H.empty()){
            dino = H.front();
            H.pop();
            C.push(dino);
        }
    }
    while(!C.empty()){
        cout << C.top() << " ";
        C.pop();
    }
    return 0;
}