#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    //ROW, COLUMN - SO SIMPLE...
    int n, i, j, playGround[n][n];

    ifstream file("C:\\Users\\lewis\\Documents\\GitHub\\UniYear2\\week3CG.txt");
    if (!file.is_open()){
        cout << "Error reading file" << endl;
        return 0;
    }
    file >> n >> i >> j;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++) file >> playGround[x][y];
    }
    
    

    return 0;
}