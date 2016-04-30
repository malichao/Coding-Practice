/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 30,2016
Version		: v0.1
Built		: GCC 5.3.0, -std=c++11
Description :
	A practice of merging K sorted files into a single file using heap sort.
	We repeatedly insert and extract the minimal element in the heap until all
	the elements are all sorted.Insert and extract takes O(logK) and for N
	files it takes O(NlogK).
*****************************************************************************/
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::pair;

//Define a pair to store the elements.The second is for recoding the extracted
//index of the original files
template<typename T>
using heap_type = pair<T,size_t> ;

template <typename T>
class Compare{
public:
	const bool operator()(const heap_type<T> &lhs,const heap_type<T> &rhs) const{
		return lhs.first>rhs.first;
	}
};

template<typename T>
vector<T> merge_arrays(const vector<vector<T>> &files) {
	//Priority queue in STL is implemented as heap so we use it
	priority_queue<heap_type<T>, vector<heap_type<T>>, Compare <T>> minHeap;
	vector<size_t> fileIndex(files.size(), 0);

	//Every array in s puts its smallest element in heap
	for (size_t i = 0; i < files.size(); i++) {
		if (files[i].size() > 0) {
			minHeap.emplace(files[i][0], i);
			fileIndex[i] = 1;
		}
	}

	vector<T> ret;
	while (!minHeap.empty()) {
		pair<T, int> p = minHeap.top();
		ret.emplace_back(p.first);
		//Add the smallest element into heap if possible
		if (fileIndex[p.second] < files[p.second].size()) {
			minHeap.emplace(files[p.second][fileIndex[p.second]++], p.second);
		}
		minHeap.pop();
	}
	return ret;
}

int main(){
	vector<vector<int>> array={ {1,3,4,5},
								{2,4,7,9},
								{1,6,7,9},
								{3,7,8,9},
								{2,6,7,9}};
	vector<int> result=merge_arrays(array);
	for(auto r:result)
		cout<<r<<" ";
}
