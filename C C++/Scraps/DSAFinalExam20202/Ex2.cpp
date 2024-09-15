#include <bits/stdc++.h>

using namespace std;

//Linked list

class Node{
    public:
        int coef;
        int exp;
        Node *next;
};

Node *heads[5];

class Linked_list{
    public:
        Node *makeNode(int coef, int exp){
            Node *newNode = new Node;
            if(newNode == NULL) return NULL;
            newNode->coef = coef;
            newNode->exp = exp;
            newNode->next = NULL;
            return newNode;
        }

        Node *insertAtHead(Node *ID, int coef, int exp){
            Node *newNode = makeNode(coef, exp);
            newNode->next = ID;
            return newNode;
        }

        Node *searchByExp(Node *ID, int exp){
            if(ID == NULL) return NULL;
            Node *cur = ID;
            while(cur != NULL){
                if(cur->exp == exp) return cur;
                cur = cur->next;
            }
            return NULL;
        }

        void print(Node *ID){
            Node *cur = ID;
            while(cur != NULL){
                if(cur->coef > 0 && cur != ID) cout << "+";
                cout << cur->coef << "x^" << cur->exp << " ";
                cur = cur->next;
            }
            cout << endl;
        }

        void swap(Node *&prev_a, Node *a, Node *&prev_b, Node *b){
            if (a == b) return;

            if (prev_a != NULL) prev_a->next = b;
            if (prev_b != NULL) prev_b->next = a;

            Node *temp = b->next;
            b->next = a->next;
            a->next = temp;
        }
};

class Tasks : public Linked_list{
    public:
        void insert(int ID, int coef, int exp){
            Node *find = searchByExp(heads[ID], exp);
            if(find == NULL) heads[ID] = insertAtHead(heads[ID], coef, exp);
            else find->coef += coef;
        }

        void display(int ID){
            print(heads[ID]);
        }

        void sort(int ID){ //Bubble sort
            if (!heads[ID]) return;
            
            bool swapped;
            do {
                swapped = false;
                Node *cur = heads[ID], *prev = NULL;
                while (cur && cur->next) {
                    if (cur->exp < cur->next->exp) {
                        Node *next = cur->next;
                        swap(prev, cur, cur, next);
                        if (prev == NULL) heads[ID] = next;
                        swapped = true;
                    }
                    prev = cur;
                    cur = cur->next;
                }
            } while (swapped);
            
            display(ID);
        }

        void add(){ //Add 2 poly 1 & 2 to become poly 3->sort->display
            Node *cur1 = heads[1], *cur2 = heads[2];
            while(cur1 != NULL){
                insert(3, cur1->coef, cur1->exp);
                cur1  = cur1->next;
            }
            while(cur2 != NULL){
                insert(3, cur2->coef, cur2->exp);
                cur2  = cur2->next;
            }
            sort(3);
        }

        void multiply(){
            Node *cur1 = heads[1];
            while(cur1 != NULL){
                Node *cur2 = heads[2];
                while(cur2 != NULL){
                    int newCoef = cur1->coef * cur2->coef;
                    int newExp = cur1->exp + cur2->exp;
                    insert(4, newCoef, newExp);
                    cur2 = cur2->next;
                }
                cur1 = cur1->next;
            }
            sort(4);
        }

        void space(int ID){
            int length = 0;
            Node *cur = heads[ID];
            while(cur != NULL){
                length++;
                cur = cur->next;
            }
            cout << length * sizeof(Node) << endl;
        }

        void reset(int ID){
            Node *temp;
            while(heads[ID] != NULL){
                temp = heads[ID];
                heads[ID] = heads[ID]->next;
                delete temp;
            }
        }
};

int main(){
    string cmd;
    Tasks tasks;
    while(1){
        cin >> cmd;
        if(cmd == "***") break;

        int ID, coef, exp;
        if(cmd == "insert"){
            cin >> ID >> coef >> exp;
            tasks.insert(ID, coef, exp);
        }

        if(cmd == "display"){
            cin >> ID;
            tasks.display(ID);
        }

        if(cmd == "sort"){
            cin >> ID;
            tasks.sort(ID);
        }

        if(cmd == "add"){
            tasks.add();
        }

        if(cmd == "multiply"){
            tasks.multiply();
        }

        if(cmd == "space"){
            cin >> ID;
            tasks.space(ID);
        }

        if(cmd == "reset"){
            cin >> ID;
            tasks.reset(ID);
        }
    }
    return 0;
}
