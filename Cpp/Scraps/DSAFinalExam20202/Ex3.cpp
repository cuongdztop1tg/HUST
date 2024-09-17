#include <bits/stdc++.h>
#include <vector>

using namespace std;

//Linked list || 2D vector->2D vector

vector<vector<int>> cashiers(5, vector<int>(1));
int countCustomer = 0, countMaxCashier = 4, rr = 0;

class Tasks{
    public:
        void initCashierLine(){
            for(int i = 0; i < 5; i++){
                cashiers[i][0] = i;
            }
        }

        void enter(int customer){
            if(rr == countMaxCashier) rr = 0;
            rr++;
            while(cashiers[rr][0] == 0){
                rr++;
                if(rr > countMaxCashier) rr = 1;
            }
            cashiers[rr].push_back(customer);
        }

        void advancedEnter(int customer){
            int optLine;
            for(int i = 1; i <= countMaxCashier; i++){
                if(cashiers[i][0] != 0){
                    optLine = i;
                    break;
                }
            }
            for(int i = 1; i <= countMaxCashier; i++){
                if(cashiers[i].size() < cashiers[optLine].size() && cashiers[i][0] != 0) optLine = i;
            }
            cashiers[optLine].push_back(customer);
            cout << customer << " " << optLine << endl;
        }

        void checkout(int cashier_num){
        	if(cashiers[cashier_num].size() == 1) cout << "Error" << endl;
        	else{
	            cout << cashiers[cashier_num][1] << endl;
	            cashiers[cashier_num].erase(cashiers[cashier_num].begin() + 1);
	        }
        }

        void countNumberCustomerInLine(int line_num){
            if(cashiers[line_num][0] == 0) cout << "Error" << endl;
            else cout << cashiers[line_num].size() - 1 << endl;
        }

        void listCustomerInLine(int line_num){
            if(cashiers[line_num][0] == 0) cout << "Error" << endl;
            else{
                for(int i = 1; i < cashiers[line_num].size(); i++){
                    cout << cashiers[line_num][i] << "->";
                }
                cout << "end" << endl;
            }
        }

        void countNumberCustomerInAllLine(){
            int count = 0;
            for(int i = 1; i <= countMaxCashier; i++){
                if(cashiers[i][0] != 0){
                    count += (cashiers[i].size() - 1);
                }
            }
            cout << count << endl;
        }

        void openCashier(){
            cashiers.push_back({++countMaxCashier});
            cout << countMaxCashier << endl;
        }

        void closeCashier(int cashier_num){
            if(cashiers[cashier_num][0] == 0 || countMaxCashier <= 1) cout << "Error" << endl;
            else{
                for(int i = 1; i < cashiers[cashier_num].size(); i++){
                    enter(i);
                }
                cashiers.erase(cashiers.begin() + cashier_num);
                cout << "Closed" << endl;
            }
        }
};

int main(){
    string cmd;
    Tasks tasks;
    tasks.initCashierLine();
    while(1){
        cin >> cmd;
        if(cmd == "***") break;

        int cashier_num, line_num;
        if(cmd == "$Enter"){
            tasks.enter(++countCustomer);
            cout << countCustomer << " " << rr << endl;
        }

        if(cmd == "$AdvancedEnter"){
            tasks.advancedEnter(++countCustomer);
        }

        if(cmd == "$Checkout"){
            cin >> cashier_num;
            tasks.checkout(cashier_num);
        }

        if(cmd == "$CountNumberCustomerInLine"){
            cin >> line_num;
            tasks.countNumberCustomerInLine(line_num);
        }

        if(cmd == "$ListCustomerInLine"){
            cin >> line_num;
            tasks.listCustomerInLine(line_num);
        }

        if(cmd == "$CountNumberCustomerInAllLines"){
            tasks.countNumberCustomerInAllLine();
        }

        if(cmd == "$OpenCashier"){
            tasks.openCashier();
        }

        if(cmd == "$CloseCashier"){
            cin >> cashier_num;
            tasks.closeCashier(cashier_num);
        }
    }
    return 0;
}