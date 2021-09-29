// Calculating subtree size for the every node of a tree.
// Time complexity: O(n_node)

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
int subtree_size[nodes+1];
int dfs(int node) {
	is_visited[node]=1;
	
	int current_size = 1;
	for(int child: graph[node]) {
		if(is_visited[child] == 0) {
			current_size += dfs(child);
		}
	}
	
	subtree_size[node] = current_size;
	return current_size;
}

int main() {
	int n_node; cin >> n_node;
	
	graph_represent(n_node-1);
	
	dfs(1);
	
	for(int i=1; i<=n_node; i++) 
		cout << subtree_size[i] << " ";
	cout << endl;
}
