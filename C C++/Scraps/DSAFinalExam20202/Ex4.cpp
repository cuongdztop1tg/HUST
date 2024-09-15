#include <bits/stdc++.h>

using namespace std;

class Tasks{
    public:
        void add(string dishType, string dishName, int price, int time){

        }

        void price(string dishName){

        }

        void order(int hour, int minute, string dishName1, string dishName2){

        }

        void wait(int hour, int minute){

        }

        void count(string dishName){

        }
};

int main(){
    string cmd;
    Tasks tasks;
    while(1){
        cin >> cmd;
        if(cmd == "***") break;

        int hour, min, price, time;
        string dishName1, dishName2, dishType;

        if(cmd == "$ADD"){
            cin >> dishType >> dishName1 >> price >> time;
            tasks.add(dishType, dishName1, price, time);
        }

        if(cmd == "$PRICE"){
            cin >> dishName1;
            tasks.price(dishName1);
        }

        if(cmd == "$ORDER"){
            cin >> hour >> min >> dishName1 >> dishName2;
            tasks.order(hour, min, dishName1, dishName2);
        }

        if(cmd == "$WAIT"){
            cin >> hour >> min;
            tasks.wait(hour, min);
        }

        if(cmd == "$COUNT"){
            cin >> dishName1;
            tasks.count(dishName1);
        }
    }
    return 0;
}