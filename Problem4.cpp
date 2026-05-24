#include<iostream>
#include<vector>
#include<list>//linked list
#include<set> 
#include<utility>
#include<string>
#include<algorithm>

//a large value representing infinity but is not infinity 
#define INF 1000000
using namespace std;


class Graph {

private:
	int Vertices;
	//storing roads (neighbour, distance)
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
	//distance is the distance
	void addEdges(int v1, int v2, int distance){
		//adding edges from v1 to v2
		//stroing destinations vertex and distance
		adjacency[v1].push_back(make_pair(v2, distance));
		adjacency[v2].push_back(make_pair(v1, distance));
	}

	//dijkstra shortest path func
	vector<int> shortestPath(int start, int end, string mode, int &finalDistance, int &finalToll){
		//setting used like a priority queue
		//stroing (distances, vertex)
		set<pair<int, int>> queue;

		//vector storing shortest distances
		//all distances inittially star as infinities
		vector<int> cost(Vertices, INF);


		//storing cost depending on the mode
		vector<int> distance(Vertices, INF);


		//storing tolls paid
		vector<int> tollCost(Vertices, INF);


		//storing prev vertex to find the path
		vector<int> parent(Vertices, -1);


		//starting vals
		cost[start] = 0;
		distance[start] = 0;
		tollCost[start] = tolls[start];

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

					//getting edge distances
					int roadDistance = edge->second;



					int newDistance = distance[currentVertex] + roadDistance;
					int newToll = tollCost[currentVertex] + tolls[nextVertex];


					int newCost;


					if (mode == "shortest") {
						newCost = newDistance;
					}
					else if (mode == "cheapest"){
						newCost = newToll;
					}
					else {
						newCost = newDistance + newToll;
					}



					//checking if shorter path exist
					if(newCost < cost[nextVertex]) {
						
						//remvoing old distances from set
						queue.erase(make_pair(cost[nextVertex], nextVertex));
						
						cost[nextVertex] = newCost;

						distance[nextVertex] = newDistance;

						tollCost[nextVertex] = newToll;


						parent[nextVertex] = currentVertex;


						//inserting updated distances
						queue.insert(make_pair(cost[nextVertex], nextVertex));
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
		for (int i = 0; i < path.size(); i++){
			cout << char('A' + path[i]);

			if (i != path.size() - 1){
				cout<<" -> ";
			}
		}

	cout << endl;
	cout << "Distance: " << distance<<endl;
	cout << "Tolls: " << toll << endl;
	cout << "Balanced cost: " << distance + toll << endl;
	cout << endl;
	}
	//checking if route a is worse than b
	bool isBadRoute(int distanceA, int tollA, int distanceB, int tollB) {
		return distanceA > distanceB && tollA > tollB;
	}
};

int main(){

    //graph with 5 vertices: A, B, C, D, E
    Graph g(5);

    //set tolls
    g.setToll(0, 0); //A
    g.setToll(1, 2); //B
    g.setToll(2, 3); //C
    g.setToll(3, 2); //D
    g.setToll(4, 5); //E

    //add edges / roads
    g.addEdges(0, 1, 4); //A-B
    g.addEdges(0, 2, 8); //A-C
    g.addEdges(1, 2, 2); //B-C
    g.addEdges(1, 3, 5); //B-D
    g.addEdges(2, 3, 3); //C-D
    g.addEdges(2, 4, 6); //C-E
    g.addEdges(3, 4, 2); //D-E

    int d1, t1;
    int d2, t2;
    int d3, t3;

    vector<int> route1 = g.shortestPath(0, 4, "shortest", d1, t1);
    vector<int> route2 = g.shortestPath(0, 4, "cheapest", d2, t2);
    vector<int> route3 = g.shortestPath(0, 4, "balanced", d3, t3);

    g.printRoute("Shortest route", route1, d1, t1);
    g.printRoute("Cheapest route", route2, d2, t2);
    g.printRoute("Balanced route", route3, d3, t3);

    return 0;
}
