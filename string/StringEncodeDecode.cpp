#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

string encode(const string &words){
	if(words.empty())
		return words;
	size_t count=1;
	string result;
	for(size_t i=1;i<words.size();i++){
		if(words[i]==words[i-1])
			count++;
		else{
			if(count==1)
				result+=words[i-1];
			else
				result+=words[i-1]+to_string(count);
			count=1;
		}

	}
	if(count==1)
		result+=words.back();
	else
		result+=words.back()+to_string(count);
	return result;
}

string decode(const string &s){
	int count=0;
	char letter;
	string result;
	if(s.empty())
		return s;

	letter=s.front();
	for(size_t i=1;i<s.size();i++){
		if(isdigit(s[i]))
			count=count*10+s[i]-'0';
		else{
			if(count==0)
				result+=letter;
			else
				result.append(count,letter);
			count=0;
			letter=s[i];
		}
	}

	if(count==0)
		result+=letter;
	else
		result.append(count,letter);

	return result;
}

int main(){
	cout<<encode("abc")<<endl;
	cout<<encode("aaaabbcccabc")<<endl;
	cout<<encode("aaaaaaaaaaaaa")<<endl;
	cout<<encode("ababababababab")<<endl;
	cout<<encode("abcabcabcabc")<<endl;
	cout<<decode(encode("abcabcabcabc"))<<endl;
	cout<<decode(encode("abcabcabcabccc"))<<endl;
}
