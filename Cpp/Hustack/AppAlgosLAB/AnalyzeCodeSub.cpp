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

    string type;
    int totalSub = 0, totalERR = 0;
    map<string, int> totalERRofUser;
    map<string, int> userTotalPoint;
    map<pair<string, string>, int> userMaxPointOfProblem;
    vector<int> totalSubAtTime;
    while(1){
        string userID, problemID, Time, status;
        int point;
        cin >> userID;
        if(userID == "#") break;
        cin >> problemID >> Time >> status >> point;
        ++totalSub;
        if(status == "ERR"){
            ++totalERR;
            totalERRofUser[userID]++;
        }
        else{
            if(userMaxPointOfProblem[{userID, problemID}] < point){
                userTotalPoint[userID] -= userMaxPointOfProblem[{userID, problemID}];
                userMaxPointOfProblem[{userID, problemID}] = point;
                userTotalPoint[userID] += userMaxPointOfProblem[{userID, problemID}];
            }
        }
        totalSubAtTime.push_back(convert(Time));
    }
    sort(totalSubAtTime.begin(), totalSubAtTime.end());
    while(1){
        cin >> type;
        if(type == "#") break;

        if(type == "?total_number_submissions"){
            cout << totalSub << endl;
        }
        else if(type == "?number_error_submision"){
            cout << totalERR << endl;
        }
        else if(type == "?number_error_submision_of_user"){
            string userID;
            cin >> userID;
            cout << totalERRofUser[userID] << endl;
        }
        else if(type == "?total_point_of_user"){
            string userID;
            cin >> userID;
            cout << userTotalPoint[userID] << endl;
        }
        else if(type == "?number_submission_period"){
            string stime, etime;
            int Count = 0;
            cin >> stime >> etime;
            auto start = lower_bound(totalSubAtTime.begin(), totalSubAtTime.end(), convert(stime));
            auto end = upper_bound(totalSubAtTime.begin(), totalSubAtTime.end(), convert(etime));
            cout << end - start << endl;
        }
    }
    //for(int i = 0; i < totalSubAtTime.size(); i++) cout << totalSubAtTime[i] << " ";
    return 0;
}