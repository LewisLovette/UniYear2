
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

//Words to check - global for ease of use
vector<string> personWords = {"Baxter", "Shila", "Igor"};
vector<string> actionWords = {"recognise", "eat", "sees", "pick"};
vector<string> positionWords = {"left", "right", "forwards", "backwards"};
vector<string> pronounWords = {"I", "you", "him", "we", "her"};
vector<string> thingWords = {"screwdriver", "diamond", "person", "boat", "ball", "dog", "apple"};
vector<string> valueWords = {"cheap", "expensive", "price-less"};

//<Person Word> <Action Word> <Thing Word>
void ruleOne(vector<string> inputWords){    //Checking order
    vector<string>::iterator temp;

    //Finding if words are in the correct place (searching array for specific positions)
    temp = find(personWords.begin(), personWords.end(), inputWords[0]);
    if(temp == personWords.end()){
        cout << "Doesn't fit personWords. for the order   <Person Word> <Action Word> <Thing Word>" << endl;
        return;
    }
    temp = find(actionWords.begin(), actionWords.end(), inputWords[1]);
    if(temp == actionWords.end()){
        cout << "Doesn't fit actionWords. for the order   <Person Word> <Action Word> <Thing Word>" << endl;
        return;
    }
    temp = find(thingWords.begin(), thingWords.end(), inputWords[2]);
    if(temp == thingWords.end()){
        cout << "Doesn't fit thingWords. for the order   <Person Word> <Action Word> <Thing Word>" << endl;
        return;
    }

    cout << "Fit's structure '<Person Word> <Action Word> <Thing Word>'." << endl;
}

//<Person Word> <Action Word> <Value Word> <Thing Word>
void ruleTwo(vector<string> inputWords){
    vector<string>::iterator temp;
    
    //Finding if words are in the correct place (searching array for specific positions)
    temp = find(personWords.begin(), personWords.end(), inputWords[0]);
    if(temp == personWords.end()){
        cout << "Doesn't fit personWords. for the order   <Person Word> <Action Word> <Value Word> <Thing Word>" << endl;
        return;
    }
    temp = find(actionWords.begin(), actionWords.end(), inputWords[1]);
    if(temp == actionWords.end()){
        cout << "Doesn't fit actionWords. for the order   <Person Word> <Action Word> <Value Word> <Thing Word>" << endl;
        return;
    }
    temp = find(valueWords.begin(), valueWords.end(), inputWords[2]);
    if(temp == valueWords.end()){
        cout << "Doesn't fit valueWords. for the order   <Person Word> <Action Word> <Value Word> <Thing Word>" << endl;
        return;
    }
    temp = find(thingWords.begin(), thingWords.end(), inputWords[3]);
    if(temp == thingWords.end()){
        cout << "Doesn't fit thingWords. for the order   <Person Word> <Action Word> <Value Word> <Thing Word>" << endl;
        return;
    }

    cout << "Fit's structure '<Person Word> <Action Word> <Value Word> <Thing Word>'." << endl;
}

//<Person> <Action> <Position>
void ruleThree(vector<string> inputWords){
    vector<string>::iterator temp;

    //Finding if words are in the correct place (searching array for specific positions)
    temp = find(personWords.begin(), personWords.end(), inputWords[0]);
    if(temp == personWords.end()){
        cout << "Doesn't fit personWords. for the order   <Person> <Action> <Position>" << endl;
        return;
    }
    temp = find(actionWords.begin(), actionWords.end(), inputWords[1]);
    if(temp == actionWords.end()){
        cout << "Doesn't fit actionWords. for the order   <Person> <Action> <Position>" << endl;
        return;
    }
    temp = find(positionWords.begin(), positionWords.end(), inputWords[2]);
    if(temp == positionWords.end()){
        cout << "Doesn't fit positionWords. for the order   <Person> <Action> <Position>" << endl;
        return;
    }

    cout << "Fit's structure '<Person> <Action> <Position>'." << endl;
}


//<Pronoun> <Action> <Thing Word>
void ruleFour(vector<string> inputWords){
    vector<string>::iterator temp;

    //Finding if words are in the correct place (searching array for specific positions)
    temp = find(pronounWords.begin(), pronounWords.end(), inputWords[0]);
    if(temp == pronounWords.end()){
        cout << "Doesn't fit pronounWords. for the order   <Pronoun> <Action> <Thing Word>" << endl;
        return;
    }
    temp = find(actionWords.begin(), actionWords.end(), inputWords[1]);
    if(temp == actionWords.end()){
        cout << "Doesn't fit actionWords. for the order   <Pronoun> <Action> <Thing Word>" << endl;
        return;
    }
    temp = find(thingWords.begin(), thingWords.end(), inputWords[2]);
    if(temp == thingWords.end()){
        cout << "Doesn't fit thingWords. for the order   <Pronoun> <Action> <Thing Word>" << endl;
        return;
    }

    cout << "Fit's structure '<Pronoun> <Action> <Thing Word>'." << endl;
}


//<Pronoun> <Action> <Position>
void ruleFive(vector<string> inputWords){
    vector<string>::iterator temp;

    //Finding if words are in the correct place (searching array for specific positions)
    temp = find(pronounWords.begin(), pronounWords.end(), inputWords[0]);
    if(temp == pronounWords.end()){
        cout << "Doesn't fit pronounWords. for the order   <Pronoun> <Action> <Position>" << endl;
        return;
    }
    temp = find(actionWords.begin(), actionWords.end(), inputWords[1]);
    if(temp == actionWords.end()){
        cout << "Doesn't fit actionWords. for the order   <Pronoun> <Action> <Position>" << endl;
        return;
    }
    temp = find(positionWords.begin(), positionWords.end(), inputWords[2]);
    if(temp == positionWords.end()){
        cout << "Doesn't fit positionWords. for the order   <Pronoun> <Action> <Position>" << endl;
        return;
    }

    cout << "Fit's structure '<Pronoun> <Action> <Position>'." << endl;
}

int main(){
    cout << "Choose 3 or 4 (size of scentence) and input the words" << endl;
    vector<string> inputWords;
    int numOfWords; //specify number of words
    string temp;

    cin >> numOfWords;

    for(int i = 0; i < numOfWords; i++){
        cin >> temp;
        inputWords.push_back(temp);
    }

    if(numOfWords == 4){
        ruleTwo(inputWords);
    }
    if(numOfWords == 3){
        ruleOne(inputWords);
        ruleThree(inputWords);
        ruleFour(inputWords);
        ruleFive(inputWords);
    }

    
    return 0;
} 