#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

template<typename T>
class BinaryTree{
public:
	T data;
	shared_ptr<BinaryTree<T>> left,right;
};

template<typename T>
using btree_ptr=shared_ptr<BinaryTree<T>>;

template<typename T>
btree_ptr<T> construct( const vector<T> &pre, const int &pre_s, const int &pre_e,
						const vector<T> &in, const int &in_s, const int &in_e) {
	if (pre_e > pre_s && in_e > in_s) {
		auto it = find(in.cbegin() + in_s, in.cbegin() + in_e, pre[pre_s]);
		int leftTreeSize = it - (in.cbegin() + in_s);

		btree_ptr<T> left(construct(pre, pre_s + 1, pre_s + 1 + leftTreeSize,
									in, in_s, it - in.cbegin()));
		btree_ptr<T> right(construct(pre, pre_s + 1+ leftTreeSize, pre_e,
									 in,it - in.cbegin() + 1, in_e));

		return btree_ptr<T>(new BinaryTree<T> { pre[pre_s],left,right});
	}

	return nullptr;
}


void printTree(const btree_ptr<char> &tree){
	if(!tree)
		return;
	std::queue<btree_ptr<char>> q;
	btree_ptr<char> nullchar(new BinaryTree<char> {'_',nullptr,nullptr});
	btree_ptr<char> separator(new BinaryTree<char> {'|',nullptr,nullptr});
	q.push(tree);
	while(!q.empty()){
		int size=q.size();
		while(size--){
			btree_ptr<char> temp=q.front();
			q.pop();
			if(temp){
				cout<<temp->data<<" ";
				if(temp->data=='_'||temp->data=='|')
					continue;
				if(temp->left)
					q.push(temp->left);
				else
					q.push(nullchar);
				if(temp->right)
					q.push(temp->right);
				else
					q.push(nullchar);
				q.push(separator);
			}
		}
		cout<<endl;
	}
}

/*
         A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F
*/
void test1(){
	vector<char> inOrder={'D','B','E','A','F','C'};
	vector<char> preOrder={'A','B','D','E','C','F'};
	btree_ptr<char> root=construct(preOrder,0,preOrder.size(),inOrder,0,inOrder.size());
	cout<<"constructed result:\n";
	printTree(root);
}


int main(){
	test1();
}
