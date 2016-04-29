#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::unordered_map;
using std::unordered_set;
using std::string;

class Trie{
private:
	class TrieNode{
	public:
		bool isString;
		unordered_map<char,shared_ptr<TrieNode>> l;
	};

	shared_ptr<TrieNode> root;

public:
	using trieNode_ptr=shared_ptr<TrieNode>;

	Trie(): root(trieNode_ptr(new TrieNode{false})){}

	bool insert(const string &s){
		trieNode_ptr p=root;
		for(const char &c:s){
			if(p->l.find(c)==p->l.cend()){
				p->l[c]=trieNode_ptr(new TrieNode{false});
			}
			p=p->l[c];
		}

		//s already existed in this trie
		if(p->isString ==true){
			return false;
		}else{	//p->isString == false
			p->isString =true;	//insert s into this trie
			return true;
		}
	}

	string getShortestUniquePrefix(const string &s){
		trieNode_ptr p=root;
		string prefix;
		for(const char &c:s){
			prefix+=c;
			if(p->l.find(c)==p->l.cend()){
				return prefix;
			}
			p=p->l[c];
		}
		return {};
	}

	string findShortestPrefix(const string &s,const unordered_set<string> &D){
		//Build a trie according to given dictionary D
		Trie T;
		for(const string &word:D){
			T.insert(word);
		}
		return T.getShortestUniquePrefix(s);
	}
};


int main(){
	unordered_set<string> dict={"dog","be","cut","car"};
	string s="cat";
	Trie t;
	cout<<"result ="<<t.findShortestPrefix(s,dict);

}
