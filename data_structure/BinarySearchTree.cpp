/******************************************************************************
Author		: Lichao Ma
Date  		: May 3,2016
Version		: v0.1
Built		: GCC 5.3.0, -std=c++11
Description :
	A practice of inserting and erasing a key in a Binary Search Tree.
*****************************************************************************/
#include <iostream>

#include <vector>

#include <utility>
#include <memory>
#include <algorithm>
#include <time.h>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;

namespace bst{

template<typename T>
class TreeNode{
public:
	T data;
	std::shared_ptr<TreeNode> left,right;
};

template<typename T>
using node_ptr=std::shared_ptr<TreeNode<T>>;

template<typename T>
class BinarySearchTree{
private:
	void clear(node_ptr<T> &n){
		//Recursively delete a tree
		if(n){
			clear(n->left);
			clear(n->right);
			n=nullptr;
		}
	}

	//Replace parent's child with a new Node
	void replace(node_ptr<T> parent,node_ptr<T> target,node_ptr<T> newNode){
		if(!parent)
			return;

		if(parent->left==target){
			parent->left=newNode;
		}else{
			parent->right=newNode;
		}
	}

	node_ptr<T> root;

public:
	BinarySearchTree():root(nullptr){}
	~BinarySearchTree(){clear();}

	const bool empty()const{ return !root;}
	void clear(){ clear(root);}

	//If the root is empty then the key becomes the root
	//If the key is a duplicate,simply return
	//If the key is smaller than the root,insert into left subtree
	//If the key is larger then the root,insert into right subtree
	const bool insert(const T& key){
		node_ptr<T> t(new TreeNode<T>{key,nullptr,nullptr});
		node_ptr<T> parent=nullptr;

		if(empty()){
			root=t;
		}else{
			node_ptr<T> current;
			current=root;
			while(current){
				parent=current;
				if(t->data==current->data){
					t=nullptr;		//Delete the pointer
					return false;	//Don't insert duplicate key
				}else if(t->data<current->data){
					current=current->left;
				}else{
					current=current->right;
				}
			}

			//Insert key according to key and parent
			if (t->data < parent->data) {
				parent->left = t;
			} else {
				parent->right = t;
			}
		}
		return true;
	}

	const bool erase(const T& key){
		//First,find the node with key
		node_ptr<T> target=root,parent=nullptr;
		while(target&&target->data!=key){
			parent=target;
			target=key<target->data?target->left:target->right;
		}

		//No node with key in this binary tree
		if(!target){
			return false;
		}

		//The key exists,it will be replaced by right subtree
		if(target->right){
			//Find the minimum of the right subtree
			node_ptr<T> minNode=target->right,minNodeParent=target;
			while(minNode->left){
				minNodeParent=minNode;
				minNode=minNode->left;
			}

			//Move links to erase the node
			replace(parent,target,minNode);
			replace(target,minNode,minNode->right);

			//Update root link if needed
			if(root==target){
				root=minNode;
			}
		}else{
			//Update root link if needed
			if(root==target){
				root=target->left;
			}
			replaceParentChildLink(parent,target,target->left);
		}
		target=nullptr;
		return true;
	}
};

}



int main () {
	bst::BinarySearchTree<int> tree;
	tree.insert(5);
	tree.insert(1);
	tree.insert(2);
	tree.insert(6);
}



