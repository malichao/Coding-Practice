/******************************************************************************
Author		: Lichao Ma
Date  		: May 1,2016
Version		: v0.1
Built		: GCC 5.3.0, -std=c++11
Description :
	Write a program to see if an anonymous letter could be written by using
	the letters from a magazine.
*****************************************************************************/
#include <iostream>
#include <string>

#include <vector>
#include <unordered_map>

#include <utility>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool anonymousLetter(const string &letter,const string magazine){
	std::unordered_map<char,int> hash;
	//Insert all chars in letter into hash table
	std::for_each(letter.begin(),letter.end(),[&hash](const char &c){++hash[c];});

	//Check chars in magazine that could cover chars in a hash table
	for(const char &c:magazine){
		auto it=hash.find(c);
		if(it!=hash.cend()){
			if(--it->second==0){
				hash.erase(it);
				if(hash.empty())
					return true;
			}
		}
	}

	//No entry in hash means the letter can be covered by magazine
	return hash.empty();
}


int main () {
	string letter="Howdy y'all!";
	string magazine="Texan says Howdy to y'all!";
	string magazine1="What is Howdy?";
	cout<<anonymousLetter(letter,magazine)<<endl;
	cout<<anonymousLetter(letter,magazine1)<<endl;
}