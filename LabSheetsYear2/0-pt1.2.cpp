#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int size, temp, pos = 0;
    cin >> size;
    vector<int> rList;

    for(int i = 0; i < size; i++){
        cin >> temp;
        if(temp > 0){
            rList.push_back(temp);
            pos++;
        }
    }

    for(int i = 0; i < rList.size(); i++){
        cout << rList[i] << " ";
    }

    cout << endl;

    return 0;
}

vector<int> ConvertToBinary(vector<int> a){
    int rArr[15] = {}


}