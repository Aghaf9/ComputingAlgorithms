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
		Vertices = V;
		//creating ajacency list array
		adjacency = new list<pair<int, int>>[V];
	}
	//function to add edges
	void addEdges(int v1, int v2, int weight){
		//adding edges from v1 to v2
		//stroing destinations vertex and weight
		adjacency[v1].push_back(make_pair(v2, weight));
	}
	//dijkstra shortest path func
	void shortestPath(int start){
		//setting used like a priority queue
		//stroing (distances, vertex)
		set<pair<int, int>> queue;

		//vector storing shortest distances
		//all distances inittially star as infinities
		vector<int> distances(Vertices, INF);

		//insert starting node into queue
		queue.insert(make_pair(0, start));

		//the distances to starting node is 0
		distances[start] = 0;

		
		//continue while queue is not empty
		while(!queue.empty()){
			//getting smallest distances element
			pair<int, int> current = *(queue.begin());

			//removing it from queue
			queue.erase(queue.begin());

			//getting current index
			int currentVertex = current.second;


			//looping through adjacencylist
			for(auto edge = adjacency[currentVertex].begin();
					edge!= adjacency[currentVertex].end();
					edge++){
					


					//getting neibouring vertex values
					int nextVertex = edge->first;

					//getting edge weights
					int weight = edge->second;

					//checking if shorter path exist
					if(distances[nextVertex] > distances[currentVertex] + weight) {
						
						//remvoing old distances from set
						queue.erase(make_pair(distances[nextVertex], nextVertex));
						
						//updating shortest distances
						distances[nextVertex] = distances[currentVertex] + weight;
						
						//inserting updated distances
						queue.insert(make_pair(distances[nextVertex], nextVertex));
			
						

				}
			}

		}
		//displaying results
		cout<<"Shortest distances from vertex: "<< start << endl;
		//printing all shortest distances
		for(int i = 0; i < Vertices; i++) {
			cout<< "Vertex: "
			<< i
			<< "\tDistance: "
			<< distances[i]
			<< endl;
		}

	}

};

int main(){

//graph with 5 vertices
	Graph g(5);

	//add edges
	g.addEdges(0, 1, 4);
	g.addEdges(0, 2, 8);
	g.addEdges(1, 2, 2);
	g.addEdges(1, 3, 5);
	g.addEdges(2, 3, 3);
	g.addEdges(3, 4, 2);


	//dijkstras algo starting with  vertex 0
	g.shortestPath(0);

	return 0;
}
