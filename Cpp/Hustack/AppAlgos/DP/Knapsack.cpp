#include <bits/stdc++.h>

using namespace std;

//Sum of the maximum profit of the items selected among k items and total weight <= S
//--> the solution is Value[n, k];
/*
- Base case:
    + Value[k, 0] = 0 for every k = 1, n
    + Value[0, S] = 0 for every S = 1, L
- S >= w[i]: can put item k into the bag
    + NOT put k into the bag -> Value[k - 1, S]
    + put k into the bag -> v[k] + Value[k - 1, S - w[k]];
    --> max(Value[k - 1, S], v[k] + Value[k - 1, S - w[k]];)
- S < w[i]; cannot put item k into the bag 
    --> Value[k - 1, S]
*/

int n, L;

int main() {
    int n, L;
    cin >> n >> L;

    vector<int> v(n + 1); // Values of items
    vector<int> w(n + 1); // Weights of items

    for (int i = 1; i <= n; i++) {
        cout << "Item " << i << ": ";
        cin >> v[i] >> w[i];
    }

    // Create a 2D vector for storing the maximum value with dimensions (n+1) x (L+1)
    vector<vector<int>> Value(n + 1, vector<int>(L + 1, 0));

    // Fill the DP table
    for (int k = 1; k <= n; k++) {
        for (int S = 0; S <= L; S++) {
            if (S < w[k]) {
                // Cannot put item k into the bag
                Value[k][S] = Value[k - 1][S];
            } else {
                // Maximize by choosing or not choosing the item k
                Value[k][S] = max(Value[k - 1][S], v[k] + Value[k - 1][S - w[k]]);
            }
        }
    }

    // Output the maximum profit for knapsack capacity L with n items
    cout << Value[n][L] << endl;

    return 0;
}