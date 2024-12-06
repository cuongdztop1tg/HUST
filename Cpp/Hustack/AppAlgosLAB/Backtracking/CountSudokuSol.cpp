#include <bits/stdc++.h>

using namespace std;

int board[10][10]; //1-indexing
int cnt = 0; 

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cin >> board[i][j];
        }
    }
}

//return true if the number is not used in the same row column or 3x3 box
bool check(int num, int row, int col){
    for(int i = 1; i <= 9; i++){
        if(board[row][i] == num) return false;
        if(board[i][col] == num) return false;
        if(board[((row-1) / 3) * 3 + (i-1) / 3 + 1][((col-1) / 3) * 3 + (i-1) % 3 + 1] == num) return false;
    }
    return true;
}

void Try(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(board[i][j] != 0) continue;
            for(int num = 1; num <= 9; num++){
                if(check(num, i, j)){
                    board[i][j] = num;
                    Try();
                    board[i][j] = 0;
                }
            }
            return;
        }
    }
    cnt++;
}

int main(){
    input();
    Try();
    cout << cnt;
    return 0;
}