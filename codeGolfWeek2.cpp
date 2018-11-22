#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(){
    //To do
    //Step through, save positions in a pair list and after finished the step, change those positions
    //instead of changing them as you step through

    vector< pair<int, int>> healthyToInfected, infectedToFaded, fadedToHealthy;
    int generations;
    cin >> generations;

    //for input from text document
    char garden[5][5];
    ifstream file("C:\\Users\\lewis\\Documents\\GitHub\\UniYear2\\week2CG.txt");
    if (!file.is_open()){
        cout << "Error reading file" << endl;
        return 0;
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) file >> garden[i][j];
    }
    
    //char garden[5][5] = {{'h', 'h', 'h', 'h', 'h'},
    //                    {'h', 'h', 'h', 'h', 'h'},
    //                    {'h', 'f', 'i', 'f', 'h'},
    //                    {'h', 'h', 'h', 'h', 'h'},
    //                    {'h', 'h', 'h', 'h', 'h'}};
    //

    //printing generation
    cout << "Generation: 0" << endl;
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++) cout << garden[x][y] << " ";
        cout << endl;
    }
    cout << endl;


    for(int i = 1; i < generations+1; i++){   //generations

        for(int x = 0; x < 5; x++){
            for(int y = 0; y < 5; y++){
                if(garden[x][y] == 'i'){    //spreading infections
                    if((x > 0 and x < 4) and garden[x-1][y] == 'h'){    //north
                        healthyToInfected.push_back(make_pair(x-1, y));
                    }
                    if((y > 0 and y < 4) and garden[x][y-1] == 'h'){    //west
                        healthyToInfected.push_back(make_pair(x, y-1));
                    }
                    if((y > 0 and y < 4) and garden[x][y+1] == 'h'){    //east
                        healthyToInfected.push_back(make_pair(x, y+1));
                    }
                    if((x > 0 and x < 4) and garden[x+1][y] == 'h'){    //south
                        healthyToInfected.push_back(make_pair(x+1, y));
                    }

                    infectedToFaded.push_back(make_pair(x, y));
                }
                else if(garden[x][y] == 'f'){
                    fadedToHealthy.push_back(make_pair(x, y));
                }
            }
        }

        //Changing items for the current generation
        for(int x = 0; x < fadedToHealthy.size(); x++) garden[fadedToHealthy[x].first][fadedToHealthy[x].second] = 'h';
        for(int x = 0; x < healthyToInfected.size(); x++) garden[healthyToInfected[x].first][healthyToInfected[x].second] = 'i';
        for(int x = 0; x < infectedToFaded.size(); x++) garden[infectedToFaded[x].first][infectedToFaded[x].second] = 'f';

        //printing generation
        cout << "Generaion: " << i << endl;
        for(int x = 0; x < 5; x++){
            for(int y = 0; y < 5; y++) cout << garden[x][y] << " ";
            cout << endl;
        }
        cout << endl;
       
       //Clearing for next generation
        infectedToFaded.clear();
        healthyToInfected.clear();
        fadedToHealthy.clear();
    }
    

    return 0;
}