#include <bits/stdc++.h>
#include <map>
#include <list>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N, M, element;
        cin >> N >> M;
        map<int, int> m1, m2;
        list<int> list1, list2;
        //Input
        for(int j = 0; j < N; j++){
            cin >> element;
            list1.push_back(element);
            auto it = m1.find(element);
            if(it == m1.end()) m1.insert({element, 1});
            else it->second++;
        }
        for(int j = 0; j < M; j++){
            cin >> element;
            list2.push_back(element);
            auto it = m2.find(element);
            if(it == m2.end()) m2.insert({element, 1});
            else it->second++;
        }
        //Solve
        int res = 0;
        // for(map<int, int>::iterator it1 = m1.begin(); it1 != m1.end(); it1++){
        // 	cout << it1->first << " " << it1->second << endl;
		// }
		// cout << endl;
		// for(map<int, int>::iterator it2 = m2.begin(); it2 != m2.end(); it2++){
		// 	cout << it2->first << " " << it2->second << endl;
		// }
		// cout << endl;
        for(map<int, int>::iterator it1 = m1.begin(); it1 != m1.end(); it1++){
            map<int, int>::iterator it2 = m2.find(it1->first);
            if(it2 == m2.end()) res += it1->second;
            else res += abs(it1->second - it2->second);
        }
        for(map<int, int>::iterator it2 = m2.begin(); it2 != m2.end(); it2++){
            map<int, int>::iterator it1 = m1.find(it2->first);
            if(it1 == m1.end()) res += it2->second;
        }
        cout << res << endl;
    }
    return 0;
}