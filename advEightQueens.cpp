#include<bits/stdc++.h>
#include<algorithm>

using namespace std;


int x[8] = {0};


//used to check across the 8 directions of a queen to see other queens
bool queenInteract(int board[8][8], int x, int y){
    //if true, interaction has happened

    int xC, yC;

    //verticle
    for(int i = 0; i < 8; i++){
        if(board[i][y] == 1) return true;
    }
    //horizontal
    for(int i = 0; i < 8; i++){
        if(board[x][i] == 1) return true;
    }

    //up left
    xC = x, yC = y; //xCopy, yCopy
    while(xC >= 0 and yC >= 0){ //set to 8 as max possible moves
        if(board[xC][yC] == 1) return true;
        xC -= 1;
        yC -= 1;
    }
    //down right
    xC = x, yC = y; //xCopy, yCopy
    while(xC <= 7 and yC <= 7){ //set to 8 as max possible moves
        if(board[xC][yC] == 1) return true;
        xC += 1;
        yC += 1;
    }

    //up right
    xC = x, yC = y; //xCopy, yCopy
    while(xC >= 0 and yC <= 7){ //set to 8 as max possible moves
        if(board[xC][yC] == 1) return true;
        xC -= 1;
        yC += 1;
    }
    //down left
    xC = x, yC = y; //xCopy, yCopy
    while(xC <= 7 and yC >= 0){ //set to 8 as max possible moves
        if(board[xC][yC] == 1) return true;
        xC += 1;
        yC -= 1;
    }

    return false;
}

void backTracker(int k, int n){
    for(int i = 0; i < n; i++){
        if(!queenInteract(k, i)){

        }
    }
}

int main(){
    int board[8][8] = {0}; //initialize board positions to 0
    //board[0][0] = 1;
    //vector<int> columnFull;
    bool temp = false;

    //placing queens
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            //if(find(columnFUll.begin(), columnFull.end(), y) != columnFull.end()) continue;   //this column has a queen in it
            temp = queenInteract(board, i, j);
            if(temp == false){   //if no interaction then place queen and move to next line
                board[i][j] = 1;
                //columnFull.push_back(y);  //column has a queen in it
                //break; //as can't do more on this row
            }
            for(int x = 0; x < 8; x++){
                for(int y = 0; y < 8; y++) cout << board[x][y] << " ";
                cout << endl;
            }
            cout << endl;
        }
    }

    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++) cout << board[x][y] << " ";
        cout << endl;
    }

    return 0;
}