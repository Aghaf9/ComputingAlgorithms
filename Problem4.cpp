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
	//storing roads (neighbour, weight)
	list<pair<int, int>> *adjacency;

	//storing tolls for each intersection
	vector<int> tolls;


public:
	//constructor
	Graph(int V){
		//number of verticles
		Vertices = V;
		//creating ajacency list array
		adjacency = new list<pair<int, int>>[V];
		

		//initially all tolls are 0
		tolls.resize(V, 0);
	}

	//setting toll toll for a vertex (intersection)
	void setToll(int vertex, int toll){
		tolls[vertex] = toll;
	}



	//function to add edges
	//weight is the distance
	void addEdges(int v1, int v2, int weight){
		//adding edges from v1 to v2
		//stroing destinations vertex and weight
		adjacency[v1].push_back(make_pair(v2, weight));
	}

	//dijkstra shortest path func
	void shortestPath(int start, int end, starting mode, int &finalDestination, int &finalToll){
		//setting used like a priority queue
		//stroing (distances, vertex)
		set<pair<int, int>> queue;

		//vector storing shortest distances
		//all distances inittially star as infinities
		vector<int> distances(Vertices, INF);


		//storing cost depending on the mode
		vector<int> weight(Vertices, INF);


		//storing tolls paid
		vector<int> tollCost(Vertices, INF);


		//storing prev vertex to find the path
		vector<int> parent(Vertices, -1);


		//starting vals
		cost[start] = 0;
		weight[start] = 0;
		tollCost[start] = 0;

		queue.insert(make_pair(0, start));



		
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



					int newDistance = weight[currentVertex] + roadDistance;
					int newToll = tollCost[currentVertex] + tolls[nextVertex];


					int newCost;


					if (mode == "shoretest") {
						newCost = newDistance
					}
					else if (mode == "cheapest"){
						newCost = newToll;
					}
					else {
						newCost = newDistance + newToll;
					}


					if(newCost < cost[newVertex]) {
						}

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


		//saving final distance
		finalDistance = distance[end];

		//saving final toll
		finalToll = tollCost[end];

		//storing final path
		vector<int> path;

		//starting from end node
		int current = end;


		//following parents backwards
		while (current != -1) {
			path.push_back(current);
			current = parent[current];
		}

		//reversing path so it goes from start to end
		reverse(path.begin(), path.end());

		return path;

	
	}
	//printing route
	void printRoute(string name, vector<int> path, int distance, int toll){
		cout << name << endl;

		cout << "Path: ";

		//printing each node as the alphabet (A, B, C, D,...)
		for (inti = 0; i < path.size(); i++){
			cout << char('A' + path[i]);

			if (i != path.size() - 1){
				cout<<" -> ";
			}
		}
	}


	cout<< endl;
	cout << "Distance: " << distance<<endl;
	cout << "Tolls: " << toll << endl;
	cout << "Balanced cost: " << distance + toll << endl;
	cout << endl;
		}
	//checking if route a is worse than b
	bool isBadRoute(int distanceA, int tollA, int distanceB, tollB) {
		return distanceA > distanceB && tollA > tollB;
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
