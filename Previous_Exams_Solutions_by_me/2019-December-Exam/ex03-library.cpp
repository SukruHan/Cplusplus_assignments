#include "ex03-library.h"
#include <iostream>

//Do not modify
WordsList::WordsList(){
	allWords.push_back("121");
	wordsToPalindromeDistance["121"]=0;
	allWords.push_back("122");
	wordsToPalindromeDistance["122"]=1;
}

//Exercise 3 (a) implement this method
void WordsList::print(){
	//put your code here
	int numberOfWords = 0;
	vector<string>::iterator it_fi;
    for(it_fi=allWords.begin(); it_fi!= allWords.end(); it_fi++){
		numberOfWords +=1;
    }
	cout << numberOfWords << " words:";
	map<string, int>::iterator it_sec;
	for (it_sec = wordsToPalindromeDistance.begin(); it_sec != wordsToPalindromeDistance.end(); it_sec++ ){
    	cout << it_sec->first  <<  " (" <<  it_sec->second << ") ";
	}
	cout << "\n";
}

//Exercise 3 (b) implement this method
int WordsList::distancePalindrome(string s){
	int counter = 0;
	int n_loop = s.length();
	for(unsigned int i=0; i<n_loop/2; i++){
		if(s[i] == s[n_loop-i-1]){
			continue;
		}else{
		counter += 1;
		if(s[i]<s[n_loop-i-1])  
            s[n_loop-i-1]= s[i] ; 
        else
            s[i]= s[n_loop-i-1] ; 
		}
	}
	return counter;
}

//Exercise 3 (c) implement this method
void WordsList::addWord(string word){
	//put your code here
	int count_pal = distancePalindrome(word);
	//wordsToPalindromeDistance.insert(pair<string, int>(word, count_pal));
	wordsToPalindromeDistance[word] = count_pal;
	allWords.push_back(word);

}

//Exercise 3 (d) implement this method
int WordsList::palindromeWords(){
	int counter  = 0;
	map<string, int>::iterator it;
	for (it = wordsToPalindromeDistance.begin(); it != wordsToPalindromeDistance.end(); it++ ){
		if(it->second == 0){
			counter += 1;
		}
	}
	return counter;
}