#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

template <typename T>
class Graph {

	unordered_map<T, list<T> > adjList;

public:

	void addEdge(T u, T v, bool bidir = true) {
		adjList[u].push_back(v);

		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	void display() {

		for (auto node : adjList) {

			auto u = node.first;
			cout << u << "->";
			for (T val : node.second) {
				cout << val << " ,";
			}
			cout << endl;
		}
		cout << "**********************" << endl;
	}

	void bfs(T src) {
		queue<T> q;
		unordered_map <T, bool> visited;

		visited[src] = true;
		q.push(src);

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << " ,";

			for (T neighbor : adjList[node]) {
				if (visited.count(neighbor) == 0) {
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}

		cout << endl;
	}

	void dfsHelper(T node, unordered_map<T, bool> &visited) {

		cout << node << " ";
		visited[node] = true;

		for (T neighbor : adjList[node]) {
			if (visited.count(neighbor) == 0) {
				dfsHelper(neighbor, visited);
			}
		}
	}

	void dfs(T src) {

		unordered_map<T, bool> visited;

		dfsHelper(src, visited);

		cout << endl;
	}

	void allComponents() {
		unordered_map<T, bool> visited;

		int component = 0;

		for (auto node : adjList) {

			T val = node.first;

			if (visited.count(val) == 0) {
				dfsHelper(val, visited);
				component++;
				cout << endl;
			}
		}

		cout << "Number of components " << component << endl;
	}

	void journeyToMoonHelper(T node, unordered_map<T, bool> &visited, int &countrySize) {
		countrySize++;
		visited[node] = true;

		for (T neighbor : adjList[node]) {
			if (visited.count(neighbor) == 0) {
				journeyToMoonHelper(neighbor, visited, countrySize);
			}
		}
	}

	int journeyToMoon(int n) {

		int total = n * (n - 1) / 2;

		unordered_map<T, bool> visited;

		int countrySize = 0;

		for (auto node : adjList) {

			T val = node.first;

			if (visited.count(val) == 0) {
				journeyToMoonHelper(val, visited, countrySize);
				int count = countrySize * (countrySize - 1) / 2;
				total = total - count;
				countrySize = 0;
			}
		}

		return total;
	}

	bool isCycle(T src) {
		queue<T> q;
		unordered_map<T, bool> visited;
		unordered_map<T, T> parent;

		q.push(src);
		visited[src] = true;
		// parent[src] = src;

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			for (T neighbor : adjList[node]) {
				if (visited.count(neighbor) and neighbor != parent[node]) {
					return true;
				} else if (visited.count(neighbor) == 0) {
					q.push(neighbor);
					parent[neighbor] = node;
					visited[neighbor] = true;
				}
			}
		}

		return false;
	}

	void topologicalSort() {

		unordered_map<T, int> indegree;
		queue<T> q;

		for (auto node : adjList) {
			indegree[node.first] = 0;
		}

		for (auto node : adjList) {

			for (T neighbor : node.second) {
				indegree[neighbor]++;
			}
		}

		for (auto node : indegree) {
			T val = node.first;

			int count = node.second;

			if (count == 0) {
				q.push(val);
			}
		}

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << "->";

			for (T neighbor : adjList[node]) {
				indegree[neighbor]--;

				if (indegree[neighbor] == 0) {
					q.push(neighbor);
				}
			}
		}

		cout << endl;
	}

	void bfsShortesPath(T src) {
		queue<T> q;
		unordered_map<T, int> dist;

		for (auto node : adjList) {

			T val = node.first;

			dist[val] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			for (T neighbor : adjList[node]) {
				if (dist[neighbor] == INT_MAX) {
					dist[neighbor] = 1 + dist[node];
					q.push(neighbor);
				}
			}
		}

		for (auto val : dist) {
			cout << val.first << " -> " << val.second << endl;
		}
	}

	int snakesAndLadder(T src,T dest){

		queue<T> q;
		unordered_map<T,int> dist;

		for(auto node:AdjList){
			dist[node.first] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while(!q.empty()){

			T node = q.front();
			q.pop();

			for(T neighbor:AdjList[node]){

				if(dist[neighbor]==INT_MAX){
					dist[neighbor] = dist[node] + 1;
					q.push(neighbor);
				}

			}
		}

		return dist[dest];
	}

};

int main() {

	Graph<int> g;

	// g.addEdge(1, 2);
	// g.addEdge(3, 2);
	// g.addEdge(1, 4);
	// g.addEdge(4, 3);
	// g.addEdge(3, 5);
	// g.addEdge(5, 4);
	// g.addEdge(5, 6);

	// g.bfsShortesPath(1);

	// g.addEdge(1, 2);
	// g.addEdge(1, 4);
	// g.addEdge(3, 2);
	// g.addEdge(4, 3);
	// g.addEdge(3, 5);
	// g.addEdge(4, 5);

	// g.addEdge(6, 7);

	// g.addEdge(9, 10);
	// g.addEdge(8, 9);

	// g.allComponents();

	// cout << g.journeyToMoon(10) << endl;

	// g.display();

	// g.bfs(5);

	// g.dfs(1);

	// g.addEdge(0, 4);
	// g.addEdge(2, 3);
	// g.addEdge(0, 1);

	// cout << g.journeyToMoon(5) << endl;

	// Graph<string> g;

	// g.addEdge("English", "Programming", false);
	// g.addEdge("Maths", "Programming", false);
	// g.addEdge("Programming", "Java", false);
	// g.addEdge("Programming", "Python", false);
	// g.addEdge("Java", "Web", false);
	// g.addEdge("Python", "Web", false);

	// g.topologicalSort();

	Graph<int> g;

	int board[50] = {0};

	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for(int i=0;i<=36;i++){
		for(int dice = 1;dice<=6;dice++){

			int u = i;
			int v = u + dice + board[u+dice];
			g.addEdge(u,v,false);
		}
	}

	cout<<g.snakesAndLadder(0,36)<<endl;

	return 0;
}