/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 30,2016
Version		: v0.1
Built		: GCC 5.3.0, -std=c++11
Description :
	A practice of using heap to find k smallest values in n values.
	In this scenario,there are thousands of stars in the galaxy and we want to
	find the closest k stars to the earth,which is at the original point. A
	max heap is used to record the k closest stars with the top value being the
	farthest one among the closest ones. The heap is updated when there's a
	closer star incoming. Time complexity O(NlogK),space complexity O(K).
*****************************************************************************/
#include <iostream>
#include <sstream>
#include <string>

#include <vector>
#include <queue>
#include <array>

#include <utility>
#include <algorithm>
#include <time.h>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::string;

class Star{
public:
	int ID;
	double x,y,z;

	//The distance between this star to the earth
	const double distance() const{
		return sqrt(x*x+y*y+z*z);
	}

	const bool operator< (const Star &s) const{
		return distance()<s.distance();
	}
};

vector<Star> findClosestKStar(std::istringstream &sin, const size_t &k) {
	//Use maxHeap to find the closest k start
	priority_queue<Star, vector<Star>> maxHeap;
	string line;

	//Record the first k stars
	while (std::getline(sin, line)) {
		//First parse the line
		std::stringstream line_stream(line);
		string buf;
		std::getline(line_stream, buf, '\t');
		int ID = stoi(buf);
		std::array<double, 3> data;	//stores x,y,z
		for (int i = 0; i < 3; i++) {
			std::getline(line_stream, buf, '\t');
			data[i] = stod(buf);
		}
		Star s { ID, data[0], data[1], data[2] };

		//Then the incoming start with the max heap,which is the max value
		//of the K minimal distance
		if (maxHeap.size() == k) {
			Star farStar = maxHeap.top();
			if (s < farStar) {
				maxHeap.pop();
				maxHeap.emplace(s);
			}
		} else {
			maxHeap.emplace(s);
		}
	}

	//Store the closest k stars
	vector<Star> closestStars;
	while (!maxHeap.empty()) {
		closestStars.emplace_back(maxHeap.top());
		maxHeap.pop();
	}

	return closestStars;
}

void generateTestCases(std::ostringstream &sout,const size_t n){
	srand(time(NULL));

	for(size_t i=1;i<=n;i++){
		double x,y,z;
		x=rand()%100/10.0;
		y=rand()%100/10.0;
		z=rand()%100/10.0;
		sout<<i<<'\t'<<x<<'\t'<<y<<'\t'<<z<<'\t'<<sqrt(x*x+y*y+z*z)<<'\n';
	}
}

int main(){
	//Test case for finding k closest start in n stars
	size_t n=20;
	size_t k=5;

	std::ostringstream testFile;
	generateTestCases(testFile,n);
	cout<<"ID\tX\tY\tZ\n";
	cout<<testFile.str();

	std::istringstream inputFile(testFile.str());
	cout<<"The "<<k<<" closest stars are:\n";
	vector<Star> star=findClosestKStar(inputFile,k);

	for(auto &s:star)
		cout<<s.ID<<"\t"<<s.x<<"\t"<<s.y<<"\t"<<s.z<<"\t"<<s.distance()<<'\n';
}
