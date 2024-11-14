#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<float>& a, int n){
    bool swapped;
    for(int i = 0; i < n - 1; i++){
        swapped = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                swapped = 1;
            }
        }
        if(swapped == 0) break;
    }
}

int main(){
    vector<float> a = {9.6, 2.5, 4.7, 5.9, 1.9};
    bubbleSort(a, a.size());
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    return 0;
}