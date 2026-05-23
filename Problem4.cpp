#include<iostream>
#include<vector>
#include<list>//linked list
#include<set> 
#include<utility>

//a large value representing infinity but is not infinity 
#define INF 1000000
using namespace std;


class Graph {

private:
	int Vertices;
	//stores (neighbour, weight)
	list<pair<int, int>> *adjacency;



public:
	//constructor
	Graph(int V){
		//number of verticles
		Vertices = V
		//creating ajacency list array
		adjacency = new list<pair<int, int>>[V];
	}
	//function to add edges
	void addEdges(int v1, int v2, int weight){
		//adding edges from v1 to v2
		//stroing destinations vertex and weight
		adj[v1].push_back(make_pair(v2, weight));
	}
	//dijkstra shortest path func
	void sortestPath(int start){
		//setting used like a priority queue
		//stroing (distance, vertex)
		set<pair<int, int>> queue;

		//vector storing shortest distance
		//all distances inittially star as infinities
		vector<int> distances(V, INF)

		//insert starting node into queue
		queue.insert(make_pair(0, start));

		//the distance to starting node is 0
		distance[start] = 0;

		
		//
		

	}

};
