#include <bits/stdc++.h>
using namespace std;

// Function to add two large numbers represented as strings
string add(string a, string b) {
    string res;
    int carry = 0;
    int n1 = a.size(), n2 = b.size();
    
    // Pad the shorter string with zeros
    if (n1 < n2) swap(a, b);
    n1 = a.size();
    n2 = b.size();
    for (int i = 0; i < n1 - n2; i++) {
        b = '0' + b;
    }
    
    // Add digit by digit
    for (int i = n1 - 1; i >= 0; i--) {
        int last1 = a[i] - '0';
        int last2 = b[i] - '0';
        int sum = last1 + last2 + carry;
        carry = sum / 10;
        res.push_back('0' + (sum % 10));
    }
    
    if (carry != 0) res.push_back('0' + carry);
    reverse(res.begin(), res.end());
    return res;
}

// Optimized multiplication function using an integer array
string multipli(string a, string b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> result(n1 + n2, 0); // Array to store intermediate results

    // Perform digit-by-digit multiplication
    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int num1 = a[i] - '0';
        for (int j = n2 - 1; j >= 0; j--) {
            int num2 = b[j] - '0';
            int sum = num1 * num2 + result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        result[i] += carry;
    }

    // Convert the result array into a string
    string res;
    bool leadingZero = true;
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == 0 && leadingZero) continue; // Skip leading zeros
        leadingZero = false;
        res.push_back('0' + result[i]);
    }

    return res.empty() ? "0" : res;
}

int main() {
    string a, b;
    cin >> a >> b;

    // Multiply and output the result
    if (a.size() >= b.size()) {
        cout << multipli(a, b) << endl;
    } else {
        cout << multipli(b, a) << endl;
    }

    return 0;
}
