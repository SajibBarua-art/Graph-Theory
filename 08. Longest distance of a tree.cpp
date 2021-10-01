// To calculate the longest distance of a tree
// Problem Link: https://www.spoj.com/problems/PT07Z/

#include<iostream>
#include<vector>
using namespace std;

const int nodes=1e4+7;
vector<int>graph[nodes+1];

void graph_represent(int edges) {
	for(int i=0; i<edges; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

bool is_visited[nodes+1];
int last_node=0;
int max_distance=0;
void dfs(int node, int current) {
	is_visited[node]=1;
	
	if(current > max_distance) {
		max_distance = current;
		last_node = node;
	}
	
	for(int child: graph[node]) {
		if(is_visited[child] == 0) {
			dfs(child, current+1);
		}
	}
}

int main() {
	int n_node; cin >> n_node;
	
	graph_represent(n_node-1);
	
	// To find the longest distance of a tree,
	// we only have to run the dfs for the 2 times.
	// After the execute of first dfs() function we got a last node.
	// We declare the last node as a root for the next dfs() function.
	dfs(1, 0);
	for(int i=1; i<=n_node; i++) is_visited[i]=0;
	dfs(last_node, 0);
	
	cout << max_distance << endl;
}
