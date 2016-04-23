#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

//Use BFS to find the least steps of transformation
int transformString(unordered_set<string> D, const string &s, const string &t) {
	queue<pair<string, int> > q;
	D.erase(s);		//Mark s as visited by erasing it in D
	q.emplace(s, 0);
	while (!q.empty()) {
		pair<string, int> f(q.front());
		//Return if we find a match
		if (f.first == t) {
			return f.second;	//number of steps reaches t
		}

		//Try all possible transformations of f.first
		string str = f.first;
		for (size_t i = 0; i < str.size(); i++) {
			for (int j = 0; j < 26; j++) {	//Iterates through 'a' - 'z'
				str[i] = 'a' + j;		//Change the (i+1)-th char of str
				auto it(D.find(str));
				if (it != D.end()) {
					D.erase(it);		//Mark str as visited by erasing it
					q.emplace(str, f.second + 1);
				}
			}
			str[i] = f.first[i];		//Revert the change of str
		}
		q.pop();
	}
	return -1;		//Cannot find a solution
}

int main(){
	unordered_set<string> Dict={"abcd","abce","abde","acde","abdk","zbdk"};
	cout<<"Transform result: "<<transformString(Dict,"abcd","acde")<<endl;	//should be 3
	cout<<"Transform result: "<<transformString(Dict,"abcd","zbdk")<<endl;	//should be 4
	cout<<"Transform result: "<<transformString(Dict,"aaaa","zbck")<<endl;	//should be -1

}
