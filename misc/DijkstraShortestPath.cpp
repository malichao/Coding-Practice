/******************************************************************************
Author		: Lichao Ma
Date  		: May 3,2016
Version		: v0.1
Built		: GCC 5.3.0, -std=c++11
Description :
	A practice of using Dijkstra's algorithm to find the shortest path.In this
	case,both minimal distance and number of edges are considered.
*****************************************************************************/
#include <iostream>

#include <vector>
#include <queue>
#include <set>

#include <utility>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;

template<typename T>
class GraphVertex{
public:
	int id;									//stores the id of this vertex
	vector<pair<GraphVertex<T>*,T>> edges;	//stores (vertex,dis) pair

	pair<T,int> distance;					//stores (dis,#edges) pair
	GraphVertex *pred;						//stores the predecessor in the shortest path
	bool visited;

	GraphVertex():	id(0),
					distance(std::numeric_limits<T>::max(),0),
					pred(nullptr),
					visited(false){}
};

template <typename T>
class Comp{
public:
	const bool operator()(const GraphVertex<T>* lhs,const GraphVertex<T>* rhs)const{
		return  (lhs->distance.first) < (rhs->distance.first)||
				((lhs->distance.first) == (rhs->distance.first)&&
				 (lhs->distance.second) < (rhs->distance.second));
	}
};

template<typename T>
void outputShortestPath(GraphVertex<T>* &v){
	if(v){
		outputShortestPath(v->pred);
		cout<<v->id<<"->";
	}
}

template<typename T>
void DijkstraShortestPath(  vector<GraphVertex<T>> &graph,
							GraphVertex<T>* start,
							GraphVertex<T>* target){
	//Initialize the distance of the starting point
	start->distance={0,0};
	std::set<GraphVertex<T>*,Comp<T>> nodeSet;
	nodeSet.emplace(start);

	do{
		GraphVertex<T>* cur=nullptr;
		//Extract the minimum distance vertex from heap
		while(nodeSet.empty()==false){
			cur=*nodeSet.cbegin();
			nodeSet.erase(nodeSet.cbegin());
			if(cur->visited==false){//found an unvisited node
				break;
			}
		}

		if(cur){	//cur is a valid vertex
			cur->visited=true;
			//Relax neighboring vertices of cur
			for(const auto &neighbor:cur->edges){
				T vDistance=cur->distance.first+neighbor.second;
				int vNumEdges =cur->distance.second+1;
				if( neighbor.first->distance.first>vDistance||
					(neighbor.first->distance.first==vDistance&&
					 neighbor.first->distance.second>vNumEdges)) {

					nodeSet.erase(neighbor.first);
					neighbor.first->pred=cur;
					neighbor.first->distance={vDistance,vNumEdges};
					nodeSet.emplace(neighbor.first);
				}
			}
		}else{	//cur is not a valid vertex
			break;
		}
	}while(target->visited==false);

	outputShortestPath(target);
	cout<<"\tdistance= "<<target->distance.first<<
			" ,# of edges= "<<target->distance.second<<endl;
}

template<typename T>
void createGraph(vector<GraphVertex<T>> &graph,size_t size){
	graph.resize(size);
	for(size_t i=0;i<graph.size();i++)
		graph[i].id=i;
}

template<typename T>
void addEdge(vector<GraphVertex<T>> &graph,size_t src,size_t des,size_t dis){
	graph[src].edges.emplace_back(&graph[des],dis);
}


void test(size_t start,size_t target){
	vector<GraphVertex<int>> graph;
	createGraph(graph,15);
	addEdge(graph, 0, 1, 4);
	addEdge(graph, 0, 7, 8);
	addEdge(graph, 1, 2, 8);
	addEdge(graph, 1, 7, 11);
	addEdge(graph, 2, 3, 7);
	addEdge(graph, 2, 8, 2);
	addEdge(graph, 2, 5, 4);
	addEdge(graph, 3, 4, 9);
	addEdge(graph, 3, 5, 14);
	addEdge(graph, 4, 5, 10);
	addEdge(graph, 5, 6, 2);
	addEdge(graph, 6, 7, 1);
	addEdge(graph, 6, 8, 6);
	addEdge(graph, 7, 8, 7);

	DijkstraShortestPath(graph,&graph[start],&graph[target]);
}

/*
0->				distance= 0  ,# of edges= 0
0->1->			distance= 4  ,# of edges= 1
0->1->2->		distance= 12 ,# of edges= 2
0->1->2->3->	distance= 19 ,# of edges= 3
0->1->2->3->4->	distance= 28 ,# of edges= 4
0->1->2->5->	distance= 16 ,# of edges= 3
0->1->2->5->6->	distance= 18 ,# of edges= 4
0->7->			distance= 8  ,# of edges= 1
0->1->2->8->	distance= 14 ,# of edges= 3
 */
int main () {
	for(size_t i=0;i<9;i++)
		test(0,i);
}



