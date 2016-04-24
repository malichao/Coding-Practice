#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

template <typename T>
class Node{
public:
	T data;
	std::shared_ptr<Node<T> > next;
	Node():next(nullptr){}
	Node(T& d):data(d),next(nullptr){}

static bool less(const Node<T> &lhs,const Node<T> &rhs){
	return lhs.data<rhs.data;
}
};

template <typename T>
using node_ptr=std::shared_ptr<Node<T> >;

template<typename T>
void appendNode(node_ptr<T> &head,node_ptr<T> &tail,node_ptr<T> &node){
	//If head exist,append the node to the tail,otherwise let the node be the head
	head ? tail->next = node : head = node;
	tail = node;
}

template<typename T>
void appendAndAdvance(node_ptr<T> &head,node_ptr<T> &tail,node_ptr<T> &n){
	appendNode(head,tail,n);
	n=n->next;
}

template<typename T>
node_ptr<T> mergeSortedLinkedList(node_ptr<T> list1,node_ptr<T> list2){
	node_ptr<T> sortedHead=nullptr,tail=nullptr;
	while(list1&&list2){
		appendAndAdvance(sortedHead,tail,(list1->data < list2->data)?list1:list2);
	}

	if(list1)	//Append the remaining nodes in list1
		appendNode(sortedHead,tail,list1);
	if(list2)	//Append the remaining nodes in list2
		appendNode(sortedHead,tail,list2);
	return sortedHead;
}

void generateTestVector(vector<int> &v){
	for(auto &vv:v)
		vv=rand()%30;
	sort(v.begin(),v.end());
	//for(int i=0;i<v.size();i++)
	//	cout<<v[i]<<" ";
	//cout<<endl;
}

void generateTestLinkedList(vector<int> &v,node_ptr<int> &n){
	n->data=v[0];
	shared_ptr<Node<int> > temp(n);
	for(size_t i=1;i<v.size();i++){
		temp->next=std::make_shared<Node<int> >(v[i]);
		temp=temp->next;
	}
}

void printLinkedList(node_ptr<int> n){
	while(n){
		cout<<n->data<<"\t";
		n=n->next;
	}
	cout<<endl;
}

int main(){
	srand(time(NULL));
	int size=4;
	vector<int> v(size);

	node_ptr<int> list1(new Node<int>);
	generateTestVector(v);
	generateTestLinkedList(v,list1);
	printLinkedList(list1);

	node_ptr<int> list2(new Node<int>);
	generateTestVector(v);
	generateTestLinkedList(v,list2);
	printLinkedList(list2);

	printLinkedList(mergeSortedLinkedList(list1,list2));
}
