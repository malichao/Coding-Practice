#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

template <typename T>
class Node{
public:
	T data;
	std::shared_ptr<Node<T> > next;

static bool less(const Node<T> &lhs,const Node<T> &rhs){
	return lhs.data<rhs.data;
}
};

template <typename T>
using node_ptr=std::shared_ptr<Node<T> >;

template<typename T>
void appendNode(node_ptr<T> &head,node_ptr<T> &tail,node_ptr<T> &n){
	head ? tail->next = n : head = n;
	tail = n;
}

template<typename T>
void appendNodeAndAdvance(node_ptr<T> &head,node_ptr<T> &tail,node_ptr<T> &n){
	appendNode(head,tail,n);
	n=n->next;
}

template<typename T>
node_ptr<T> mergeSortedLinkedList(node_ptr<T> F,node_ptr<T> L){
	node_ptr<T> sortedHead=nullptr,tail=nullptr;
	while(F&&L){
		appendNodeAndAdvance(sortedHead,tail,F->data<L->data?F:L);
	}

	if(F)
		appendNode(sortedHead,tail,F);
	if(L)
		appendNode(sortedHead,tail,L);
	return sortedHead;
}

int main(){
	srand(time(NULL));
	std::vector<Node<int> > nodes1(10),nodes2(10);
	for(size_t i=0;i<nodes1.size()-1;i++){
		nodes1[i].data=rand()%20;
		nodes2[i].data=rand()%20;
	}
	std::sort(nodes1.begin(),nodes1.end(),Node<int>::less);
	std::sort(nodes2.begin(),nodes2.end(),Node<int>::less);


	nodes1.back().next=nullptr;
	nodes1.back().next=nullptr;

	std::cout<<"Node List1: ";
	for(auto n:nodes1)
		std::cout<<n.data<<" ";
	std::cout<<"\nNode List2: ";
	for(auto n:nodes2)
		std::cout<<n.data<<" ";
	std::cout<<"\nMerged List: ";
	//for(auto n:nodes2)
	//	std::cout<<n.data<<" ";
}
