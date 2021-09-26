// Cycle Detection in a tree
// There is also an another solution:
// There will be no cycle if: number of edges < number of nodes
// otherwise there will exist a cycle in the graph.

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
bool dfs(int node, int parent) {
	is_visited[node]=1;
	
	for(int child: graph[node]) {
		if(is_visited[child] == 0) {
			if(dfs(child, node) == true)
				return true;
		}
		else if(parent != child) return true;
	}
	
	return false;
}

int main() {
	int edges; cin >> edges;
	
	graph_represent(edges);
	
	// If return true then there exist cycle
	// otherwise, there exist no cycle
	if(dfs(1, 0)) cout << "There exist cycle\n";
	else cout << "There exist no cycle\n";
	
	return 0;
}
