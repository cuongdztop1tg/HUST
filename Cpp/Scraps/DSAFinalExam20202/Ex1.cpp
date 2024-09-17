#include <bits/stdc++.h>

using namespace std;

//BST

class TreeNode{
    public:
        string regionCode;
        int numOfPatients;
        TreeNode *left, *right;
};

TreeNode *roots[32];

class BST{
    public:
        TreeNode *makeNode(string regionCode, int numOfPatients){
            TreeNode *newNode = new TreeNode;
            if(newNode == NULL) return NULL;
            newNode->numOfPatients = numOfPatients;
            newNode->regionCode = regionCode;
            newNode->right = NULL;
            newNode->left = NULL;
            return newNode;
        }

        TreeNode *insert(TreeNode *root, string regionCode, int numOfPatients){
            if(root == NULL){
                root = makeNode(regionCode, numOfPatients);
                return root;
            }
            if(regionCode < root->regionCode) root->left = insert(root->left, regionCode, numOfPatients); 
            if(regionCode > root->regionCode) root->right = insert(root->right, regionCode, numOfPatients); 
            return root;
        }

        int traverseAndCountPatients(TreeNode *root){
            int sum = 0;
            if(root ==  NULL) return 0;
            sum += root->numOfPatients;
            sum += traverseAndCountPatients(root->left);
            sum += traverseAndCountPatients(root->right);
            return sum;
        }

        int searchByRegion(TreeNode *root, string regionCode){
            if(root == NULL) return 0;
            if(root->regionCode == regionCode) return root->numOfPatients;
            else if(root->regionCode > regionCode) return searchByRegion(root->left, regionCode);
            else return searchByRegion(root->right, regionCode);
        }
};

class Tasks : public BST{
    public:
        void update(string regionCode, int day, int numOfPatients){
            roots[day] = insert(roots[day], regionCode, numOfPatients);
        }

        void countTotalPatients(){
            int sum = 0;
            for(int i = 1; i < 32; i++){
                sum += traverseAndCountPatients(roots[i]);
            }
            cout << sum << endl;
        }

        void findNumOfPatients(string regionCode, int day){
            cout << searchByRegion(roots[day], regionCode) << endl;
        }

        void countNumOfPatientsOfPeriod(int startDay, int endDay){
            int sum = 0;
            for(int i = startDay; i <= endDay; i++){
                sum += traverseAndCountPatients(roots[i]);
            }
            cout << sum << endl;
        }

        void countNumOfPatientsOfRegion(string regionCode){
            int sum = 0;
            for(int i = 1; i < 32; i++){
                sum += searchByRegion(roots[i], regionCode);
            }
            cout << sum << endl;
        }
};

int main(){
    string cmd;
    Tasks tasks;
    while(1){
        cin >> cmd;
        if(cmd == "***") break;

        int day, numOfPatients, startDay, endDay;
        string regionCode;

        if(cmd == "$Update"){
            cin >> regionCode >> day >> numOfPatients;
            tasks.update(regionCode, day, numOfPatients);
        }

        if(cmd == "$CountTotalPatients"){
            tasks.countTotalPatients();
        }

        if(cmd == "$FindNumberPatients"){
            cin >> regionCode >> day;
            tasks.findNumOfPatients(regionCode, day);
        }

        if(cmd == "$CountNumberPatientsOfPeriod"){
            cin >> startDay >> endDay;
            tasks.countNumOfPatientsOfPeriod(startDay, endDay);
        }

        if(cmd == "$CountNumberPatientsOfRegion"){
            cin >> regionCode;
            tasks.countNumOfPatientsOfRegion(regionCode);
        }
    }
    return 0;
}