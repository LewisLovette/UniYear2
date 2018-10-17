#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<fstream>
#include<string>

using namespace std;

int main(){

    ifstream matrix;
    matrix.open("C:\\Users\\lewis\\Documents\\GitHub\\UniYear2\\matrix.txt");
    
    if (!matrix) {  //error checking
        cerr << "Unable to open file matrix.txt, check path.";
        exit(1);   // call system to stop
    }
    else{
        cout << "No Error" << endl;
    }

    //create matrix
    vector<int, vector<string>> charMatrix;
    string line;

    while(getline(matrix, line)){
        istringstream iss(line);
        for(string s; iss >> s;) charMatrix[0].push_back(s);  //placeholder number for matrix
    }

    matrix.close();

    return 0;
}
