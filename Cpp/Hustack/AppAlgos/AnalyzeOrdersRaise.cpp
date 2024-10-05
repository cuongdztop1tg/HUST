#include <bits/stdc++.h>

using namespace std;

int convert(string Time){
    return 3600*((Time[0] - '0')*10 + (Time[1] - '0')) + 60*((Time[3] - '0')*10 + (Time[4] - '0'))
           + (Time[6] - '0')*10 + (Time[7] - '0');
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int totalOrders = 0;
    map<string, int> totalOrdersAtTime;
    vector<int> timeOrderRaised;
    while(1){
        string orderID, Time;
        cin >> orderID;
        if(orderID == "#") break;
        cin >> Time;
        totalOrders++;
        totalOrdersAtTime[Time]++;
        timeOrderRaised.push_back(convert(Time));
    }
    sort(timeOrderRaised.begin(), timeOrderRaised.end());
    string type;
    while(1){
        cin >> type;
        if(type == "###") break;

        if(type == "?number_orders"){
            cout << totalOrders << endl;
        }
        else if(type == "?number_orders_in_period"){
            string stime, etime;
            int Count = 0;
            cin >> stime >> etime;
            auto start = lower_bound(timeOrderRaised.begin(), timeOrderRaised.end(), convert(stime));
            auto end = upper_bound(timeOrderRaised.begin(), timeOrderRaised.end(), convert(etime));
            cout << end - start << endl;
        }
        else if(type == "?number_orders_at_time"){
            string Time;
            cin >> Time;
            cout << totalOrdersAtTime[Time] << endl;
        }
    }
    return 0;
}