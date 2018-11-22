#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int linearSearch(vector<int> rArray, int position, int search){
    cout << "Position: " << position << " = [" << rArray[position] << "] " << endl;
    if(position < 0){
        return -1;
    }
    else if(rArray[position] == search){
        return 0;
    }

    return linearSearch(rArray, position-1, search);
}

int main(){
    vector<int> rArray = {5, 4, 3, 2, 1, 0};
    int search;
    cin >> search;

    int temp; 
    temp = linearSearch(rArray, rArray.size()-1, search);

    if(temp == 0){
        cout << "Found";
    }
    else{
        cout << "Not Found";
    }

    return 0;
}