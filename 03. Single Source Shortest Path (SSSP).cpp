// Single Source Shortest Path on trees (SSSP) using DFS
// Problem link: https://assessment.hackerearth.com/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/

#include<iostream>
#include<vector>
using namespace std;

const int nodes=1e3+5;
vector<int>graph[nodes+1];

void graph_represent(int edges) {
	for(int i=0; i<edges; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

int is_visited[nodes+1];
int nodes_distance[nodes+1];
void dfs(int node, int distance) {
	is_visited[node]=1;
	nodes_distance[node]=distance;
	
	for(int i=0; i<(int)graph[node].size(); i++) {
		int current_node=graph[node][i];
		if(is_visited[current_node] == 0)
			dfs(current_node, distance+1);
	}
}

int main() {
	int e; cin >> e;
	graph_represent(e-1);
	
	dfs(1, 0);
	
	int q; cin >> q; 
	int node; cin >> node; int min_index=node; 
	for(int i=2; i<=q; i++) {
		cin >> node;
		
		if(nodes_distance[min_index]>nodes_distance[node]
		|| (nodes_distance[min_index]==nodes_distance[node] && node<min_index))
			min_index=node;
	}
	
	cout << min_index << endl;
}
