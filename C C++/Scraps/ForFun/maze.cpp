//Given a 2D square matrix named maze[][] which represents a maze
//where: maze[i][j] = 0->can go or = 1->cannot go
//input: your place in the maze (row, col) and the destination (row, col)
//output: fastest way to get to the destination, print the path and the length of the path
//path represented by: R (right), L(left), U (up), D (down)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int sizeOfMaze;
vector<vector<int>> maze;

int yourPlaceRow, yourPlaceCol, desRow, desCol;

void printMaze(){
    cout << "    ";
    for(int i = 0; i < maze.size(); i++){
        cout << i << " ";
    }
    cout << endl << "   ";
    for(int i = 0; i < maze.size(); i++){
        cout << "--";
    }
    cout << endl;
    for(int i = 0; i < maze.size(); i++){
        cout << i << " | ";
        for(int j = 0; j < maze[i].size(); j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void readInput(){
	cout << "Enter maze size: ";
    cin >> sizeOfMaze;
    maze.resize(sizeOfMaze, vector<int> (sizeOfMaze));
	cout << "Create your maze: " << endl;
    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){
            cin >> maze[i][j];
        }
    }
    cout << endl;
    printMaze();
    cout << "Enter your coordinate: " << endl << "- Row: ";
    cin >> yourPlaceRow;
    cout << "- Column: ";
    cin >> yourPlaceCol;
    cout << "Enter destination coordinate: " << endl << "- Row: ";
    cin >> desRow;
    cout << "- Column: ";
    cin >> desCol;
    cout << endl;
}

//BFS -> queue
//Create a graph from the maze matrix

typedef struct tracking{
    int row, col;
    string path;
} tracking;

bool isValid(int i, int j){
    return (i >= 0 && j >= 0 && i < sizeOfMaze && j < sizeOfMaze && maze[i][j] == 0);
}

void findShortestPath(){
	if(yourPlaceRow == desRow && yourPlaceCol == desCol){
		cout << "Stay right there, don't go anywhere !!!!" << endl;
		return;
	}
    queue<tracking> q;
    vector<vector<bool>> visited(sizeOfMaze, vector<bool> (sizeOfMaze, false));

    q.push({yourPlaceRow, yourPlaceCol, ""});
    visited[yourPlaceRow][yourPlaceCol] = true;

    int rowIndex[4] = {-1, 1, 0, 0};
    int colIndex[4] = {0, 0, -1, 1};
    char direction[] = {'U', 'D', 'L', 'R'};

    while(!q.empty()){
        tracking cur = q.front();
        q.pop();

        if(cur.row == desRow && cur.col == desCol){
            int countSpace = 0;
            for(int i = 0; i < cur.path.length(); i++){
                if(cur.path[i] == ' ') countSpace++;
            }
            cout << "Shortest path: " << cur.path << endl;
            cout << "Length of the shortest path is: " << cur.path.length() - countSpace << endl;
            return;
        }

        for(int i = 0; i < 4; i++){
            int newRow = cur.row + rowIndex[i];
            int newCol = cur.col + colIndex[i];
            while(isValid(newRow, newCol) && !visited[newRow][newCol]){
                visited[newRow][newCol] = true;
                q.push({newRow, newCol, cur.path + direction[i] + " "});
            }
        }
    }
    cout << "No way home." << endl;
}

int main(){
    readInput();
    findShortestPath();
    return 0;
}
