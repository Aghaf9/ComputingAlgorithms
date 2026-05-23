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
		



	}

};
