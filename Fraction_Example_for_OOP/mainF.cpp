#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "fraction.h"
using namespace std;
/*
typedef enum action {adds, mults, divs} action;

// translation of strings into actions
action str2action(string s){
	if (s=="+") return adds;
    if (s=="*") return mults;
    if (s=="div") return divs;
}
*/
vector<string> createVectorStr(){
    vector<string> v;
    return v;
}
void addItemStr(vector<string> &v, string word){
    v.push_back(word);
}
void printVector(const vector<string> &vec){
    for(int i=0; i<vec.size()-1; i++){
        cout << vec[i] << " ";
    }
}
void exWithOOP(vector<string> &v_str);

int main(){
    vector<string> v_str = createVectorStr();
    string word;
    while (true) {
        cin >> word;
        //cout << "Word is:" << word << endl;
        addItemStr(v_str, word);
        if (cin.fail()) {
            break;
        }
    }

    exWithOOP(v_str);

    return 0;
}


void exWithOOP(vector<string> &v_str){
    int counter = 0;

    fraction fr1(stoi(v_str[counter]), stoi(v_str[counter+2]));
    fraction fr2(stoi(v_str[counter+4]), stoi(v_str[counter+6]));
    fraction fr3(stoi(v_str[counter+7]), stoi(v_str[counter+9]));
    fraction fr4(stoi(v_str[counter+11]), stoi(v_str[counter+13]));
    fraction fr5(stoi(v_str[counter+14]), stoi(v_str[counter+16]));
    fraction fr6(stoi(v_str[counter+18]), stoi(v_str[counter+20]));

    if(v_str[counter+3] == "+"){
        fr1.add(fr2);
        fr1.display();
    }else if(v_str[counter+3] == "*"){
        fr1.mult(fr2);
        fr1.display();
    }
    else if(v_str[counter+3] == "div"){
        fr1.div(fr2);
        fr1.display();
    }
        if(v_str[counter+10] == "+"){
        fr3.add(fr4);
        fr3.display();
    }else if(v_str[counter+10] == "*"){
        fr3.mult(fr4);
        fr3.display();
    }
    else if(v_str[counter+10] == "div"){
        fr3.div(fr4);
        fr3.display();
    }
    if(v_str[counter+17] == "+"){
        fr5.add(fr6);
        fr5.display();
    }else if(v_str[counter+17] == "*"){
        fr5.mult(fr6);
        fr5.display();
    }
    else if(v_str[counter+17] == "div"){
        fr5.div(fr6);
        fr5.display();
    }
}
