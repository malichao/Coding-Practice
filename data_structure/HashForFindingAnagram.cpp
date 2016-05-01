/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 30,2016
Version		: v0.1
Built		: GCC 5.3.0, -std=c++11
Description :
	A practice of using hash map to find the anagrams
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

void findAnagrams(const vector<string> &dict){
	//Get the sorted string and then insert into hash table
	std::unordered_map<string,vector<string>> hash;
	for(const string &s:dict){
		string sortedStr(s);
		//Use sorted string as the hash code
		std::sort(sortedStr.begin(),sortedStr.end());
		hash[sortedStr].emplace_back(s);
	}

	for(const std::pair<string,vector<string>> &p:hash){
		//Multiple strings with the same hash code are anagrams
		if(p.second.size()>=2){
			//Output all strings
			std::copy(	p.second.begin(),p.second.end(),
						std::ostream_iterator<string>(cout," "));
			cout<<endl;
		}
	}
}


int main () {
	vector<string> dict={"carets","caters","cake","cratered","retrace","terraced",
						 "ester","reset","treez"};
	findAnagrams(dict);
}
