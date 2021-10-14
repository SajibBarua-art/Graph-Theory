// Is this graph is a tree or not?
// Problem link: https://www.spoj.com/problems/PT07Y/

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

int is_visited[nodes+1];
void dfs(int node) {
	is_visited[node]=1;
	
	for(int i=0; i<(int)graph[node].size(); i++) {
		int current_node=graph[node][i];
		if(is_visited[current_node] == 0)
			dfs(current_node);
	}
}

int main() {
	int n, e; cin >> n >> e;
	
	// In a tree, the number of node is strictly greater than the number of edge
	if(n<=e) {
		cout << "NO\n";
		return 0;
	}
	
	graph_represent(e);
	
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(is_visited[i]==0) 
		{
			cnt++;
			dfs(i);
		}
		
		// The number of connected graph for a tree is must be 1
		if(cnt>1) {
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";
	return 0;
}
