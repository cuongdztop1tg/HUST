#include <bits/stdc++.h>

using namespace std;

int totalSub = 0, totalERR = 0;
map<string, int> userERRCount;
map<string, int> totalUserPoints;
map<string, int> userSubTime;

int convertTime(string time){
    int convert = 3600*((time[0] - '0')*10 + (time[1] - '0')) + 60*((time[3] - '0')*10 + (time[4] - '0'))
                    + (time[6] - '0')*10 + (time[7] - '0');
    return convert;
}

int main(){
    string type;
    do{
        cin >> type;
        if(type == "#") continue;

        string user, problem, time, status;
        int point;
        cin >> user >> problem >> time >> status >> point;
        totalSub++;
        if(status == "ERR"){
            totalERR++;
            userERRCount[user]++;
        }
        totalUserPoints[user] += point;
        userSubTime[user] = convertTime(time);

    } while(type != "#");

    do{
        cin >> type;
        if(type == "#") continue;

        if(type == "?total_number_submissions"){
            cout << totalSub << endl;
        }
        else if(type == "?number_error_submision"){
            cout << totalERR << endl;
        }
        else if(type == "?number_error_submision_of_user"){
            string user;
            cin >> user;
            cout << userERRCount[user] << endl;
        }
        else if(type == "?total_point_of_user"){
            string user;
            cin >> user;
            cout << totalUserPoints[user] << endl;
        }
        else if(type == "?number_submission_period"){
            int Count = 0;
            string ftime, etime;
            cin >> ftime >> etime;
            int start = convertTime(ftime);
            int end = convertTime(etime);
            for(auto it = userSubTime.begin(); it != userSubTime.end(); it++){
                if(it->second >= start && it->second <= end) Count++;
            }
            cout << Count << endl;
        }

    } while(type != "#");
    return 0;
}