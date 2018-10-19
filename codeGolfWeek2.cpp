#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(){

    int generations;
    cin >> generations;

    char garden[5][5] = {{'h', 'h', 'h', 'h', 'h'},
                        {'f', 'h', 'h', 'h', 'h'},
                        {'h', 'f', 'i', 'f', 'h'},
                        {'h', 'h', 'h', 'h', 'h'},
                        {'h', 'h', 'h', 'h', 'h'}};
    
    //printing generation
    cout << "First Gen" << endl;
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++) cout << garden[x][y] << " ";
        cout << endl;
    }
    cout << endl;


    for(int i = 0; i < generations; i++){   //generations

        for(int x = 0; x < 5; x++){
            for(int y = 0; y < 5; y++){
                if(garden[x][y] == 'i'){    //spreading infections
                    if((x > 0 and x < 4) and garden[x-1][y] == 'h'){    //north
                        garden[x-1][y] = 'i';
                    }
                    if((y > 0 and y < 4) and garden[x][y-1] == 'h'){    //west
                        garden[x][y-1] = 'i';
                    }
                    if((y > 0 and y < 4) and garden[x][y+1] == 'h'){    //east
                        garden[x][y+1] = 'i';
                    }
                    //if((x > 0 and x < 4) and garden[x+1][y] == 'h'){    //south
                    //    garden[x+1][y] = 'i';
                    //}

                    garden[x][y] = 'f';
                }
                else if(garden[x][y] == 'f'){
                    garden[x][y] = 'h';
                }
            }
        }

        //printing generation
        for(int x = 0; x < 5; x++){
            for(int y = 0; y < 5; y++) cout << garden[x][y] << " ";
            cout << endl;
        }
        cout << endl;
       
    }
    

    return 0;
}