// Topic: Bipartite graph
// Problem link: https://www.spoj.com/problems/BUGLIFE/

#include<iostream>
#include<vector>
using namespace std;

const int nodes=2e3+7;
vector<int>graph[nodes+1];

void graph_represent(int edges) {
	for(int i=0; i<edges; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

bool is_visited[nodes+1];
bool colors[nodes];
bool dfs(int node, int color) {
	is_visited[node]=1;
	colors[node] = color;
	
	for(int child: graph[node]) {
		if(is_visited[child] == 0) {
			// If the answer is somehow return false, then dfs() must return false
			if(dfs(child, color^1) == false)
				return false;
		}
		// In Bipartite graph, node and the child of the node's color must be opposite
		else if(colors[node] == colors[child]) {
			return false;
		}
	}
	
	return true;
}

void testCase(int t) {
	int vertices, edges; cin >> vertices >> edges;
	
	// clear all the previous test case value
	for(int i=1; i<=vertices; i++) graph[i].clear(), is_visited[i]=0;
	
	// To take input the all edges
	graph_represent(edges);
	
	// To check for the every vertex
	for(int i=1; i<=vertices; i++) {
		if(is_visited[i] == false && dfs(i, 0) == false) {
			cout << "Scenario #" << t << ":\nSuspicious bugs found!\n";
			return;
		}
	}
	cout << "Scenario #" << t << ":\nNo suspicious bugs found!\n";
}

int main() {
	int t; cin >> t;
	for(int i=1; i<=t; i++) {
		testCase(i);
	}
	
	return 0;
}
