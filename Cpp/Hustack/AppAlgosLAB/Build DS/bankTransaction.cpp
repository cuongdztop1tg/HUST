#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> graph;
map<string, int> visited;

bool cycleDetect(string s, int k, int depth, string start) {
    visited[s] = 1;

    for (auto i : graph[s]) {
        if (visited[i] == 1) { // If revisiting a node already in the current path
            if (i == start && depth == k) {  // Check if it's the starting node and cycle length is k
                return true;  // Cycle detected
            }
        } else if (visited[i] == 0) {  // Unvisited node, continue DFS
            if (cycleDetect(i, k, depth + 1, start)) {
                return true;
            }
        }
    }

    visited[s] = 0;  // Mark node as unvisited for other paths
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int totalTransaction = 0;
    long long totalMoney = 0;
    set<string> account;
    map<string, long long> totalMoneyFromAccount;
    while(1){
        string from, to, Time, atm;
        long long money;
        cin >> from;
        if(from == "#") break;
        cin >> to >> money >> Time >> atm;
        totalTransaction++;
        totalMoney += money;
        account.insert(from);
        account.insert(to);
        totalMoneyFromAccount[from] += money;
        graph[from].push_back(to);
    }
    string type;
    while(1){
        cin >> type;
        if(type == "#") break;

        if(type == "?number_transactions"){
            cout << totalTransaction << endl;
        }
        else if(type == "?total_money_transaction"){
            cout << totalMoney << endl;
        }
        else if(type == "?list_sorted_accounts"){
            for(auto i : account) cout << i << " ";
            cout << endl;
        }
        else if(type == "?total_money_transaction_from"){
            string acc;
            cin >> acc;
            cout << totalMoneyFromAccount[acc] << endl;
        }
        else if(type == "?inspect_cycle"){
            for(auto& i : graph){
                visited[i.first] = 0;
            }
            string acc;
            int k;
            cin >> acc >> k;
            if(cycleDetect(acc, k, 1 ,acc)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}