#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

//used to check across the 8 directions of a queen to see other queens
bool queenInteract(vector<vector<int>> board, int x, int y){
    //if true, interaction has happened

    //Nasty method :)

    //horizontal    - this one is redundant
    for(int i = 0; i < 8; i++){
        if(board[x][i] == 1 and i != y) return true;
    }
    //vertical      - can make this one redundant after too
    for(int i = 0; i < 8; i++){
        if(board[i][y] == 1 and i != x) return true;
    }

    //diag up-left
    for(int xCopy = x-1; xCopy < 8; xCopy++){
        int yCopy = y-1;
        if(xCopy < 0 or yCopy < 0) break;
        if(board[xCopy][yCopy] == 1) return true;
    }
    //diag down-right
    for(int xCopy = x+1; xCopy < 8; xCopy++){
        int yCopy = y+1;
        if(xCopy > 8 or yCopy > 8) break;
        if(board[xCopy][yCopy] == 1) return true;
    }

    //diag up-right
    for(int xCopy = x-1; xCopy < 8; xCopy++){
        int yCopy = y+1;
        if(xCopy < 0 or yCopy > 8) break;
        if(board[xCopy][yCopy] == 1) return true;
    }
    //diag down-left
    for(int xCopy = x+1; xCopy < 8; xCopy++){
        int yCopy = y-1;
        if(xCopy > 8 or yCopy < 0) break;
        if(board[xCopy][yCopy] == 1) return true;
    }

    return false;
}


int main(){

    vector<vector<int>> board, boardCopy;
    bool temp = false;

    //initialize board positions to 0
    for(int i = 0; i < 8; i++){
        for(int x = 0; x < 8; x++){
            board[i][x] = 0;  
        }
    }

    //placing queens
    for(int x = 0; x < 8; x++){
        boardCopy = board;
        for(int y = 0; y < 8; y++){
            boardCopy[x][y] = 1;
            temp = queenInteract(boardCopy, x, y);
            if(temp = false){   //if no interaction then place queen and move to next line
                board = boardCopy;
                break;
            }
            else{   //else set position to 0 and try next
                boardCopy[x][y] = 0;
            }
        }
    }

    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++) cout << board[x][y] << " ";
        cout << endl;
    }

    return 0;
}