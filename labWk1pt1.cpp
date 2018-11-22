#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

//template <typename T>   //template so rerturn a vector is actually easy :)
vector<int> addPolynomials(vector<int> a, vector<int> b){
    vector<int> sum;
    //setting 0s so it can adding is easy.
    int sizeA = a.size(), sizeB = b.size(), diff;

    (a > b) ? diff = sizeA-sizeB : diff = sizeB-sizeA;

    for(int i = 0; i < diff; i++){
        if(sizeA > sizeB){
            b.insert(b.begin(), 0);
        }
        else{
            a.insert(a.begin(), 0);
        }
    }
    
    //adding
    for(int i = 0; i < a.size(); i++){
        sum.push_back(a[i]+b[i]);
    }

    //print test
    for(int i = 0; i < sum.size(); i++) cout << sum[i] << " ";
    cout << endl;


    return sum;
}

int main(){
    int x, y, temp;
    vector<int> a, b, sum;

    //getting size of arrays for input
    cin >> x >> y;

    for(int i = 0; i < x; i++){
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i < y; i++){
        cin >> temp;
        b.push_back(temp);
    }

    sum = addPolynomials(a, b);

    return 0;
}
