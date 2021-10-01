// Given 2 nodes, we have to check these 2 nodes is the part of a subtree or not.
// Tutorial link: https://www.youtube.com/watch?v=G0N7j-x3YT4&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=12

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
int in_timer[nodes+1];
int out_timer[nodes+1];
int timer=1;
void dfs(int node) {
	is_visited[node]=1;
	
	in_timer[node]=timer++;
	
	for(int child: graph[node]) {
		if(is_visited[child] == 0) {
			dfs(child);
		}
	}
	
	out_timer[node]=timer++;
}

int main() {
	int edges; cin >> edges;
	
	graph_represent(edges);
	
	dfs(1);
	
	int t; cin >> t;
	for(int i=0; i<t; i++) {
		int node1, node2; cin >> node1 >> node2;
		
		// node2 is deffinitely bigger than the node1
		if(node1>node2) swap(node1, node2);
		
		if(in_timer[node1]<in_timer[node2] && out_timer[node1]>out_timer[node2]) {
			cout << "Node: " << node1 << " and Node: " << node2 << " are the subtree of each other.\n";
		} else {
			cout << "Node: " << node1 << " and Node: " << node2 << " are not the subtree of each other.\n";
		}
	}
	
	return 0;
}
