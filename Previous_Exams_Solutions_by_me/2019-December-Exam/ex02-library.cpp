#include "ex02-library.h"
#include <iostream>

//Exercise 2 (a) Implement this function
string reverse(string s, int n){
	//put your code here
	if(n<0){
		return "";
	}
	else{
		return s[n] + reverse(s, n-1); //
	}
}

//Exercise 2 (b) Implement this function
bool isPalindrome(string s, int n1, int n2){
	//put your code here
	if(s.length() <= 1){
        return true;
    }
    else{
		if(s[0] == s[s.length()-1]){
			s = s.substr(1, s.length()-2);
        	return isPalindrome(s, n1, n2);
		}
		else{
			return false;
		}
	}
}

//Exercise 2 (c) Implement this function
//int cr = 0;
int distancePalindrome(string s, int n1, int n2){
	//put your code here
	//int cr = 0;
	if(s.length() <= 1){
        return n1;
    }
    else{
		if(s[0] == s[s.length()-1]){
			s = s.substr(1, s.length()-2);
        	return distancePalindrome(s, n1, n2);
		}
		else{
			//cr+=1;
			s = s.substr(1, s.length()-2);
			return distancePalindrome(s, n1+1, n2);
		}
	}
}