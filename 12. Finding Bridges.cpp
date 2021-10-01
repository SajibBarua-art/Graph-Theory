// Find all the bridges of a graph

#include<iostream>
#include<vector>
using namespace std;

const int nodes=102;
vector<int>graph[nodes];
int in[nodes], low[nodes], isVisited[nodes];
int timer;

void dfs(int node, int parent) {
	isVisited[node]=1;
	in[node] = low[node] = timer;
	timer++;
	
	for(int child : graph[node]) {
		if(child == parent) continue;
		if(isVisited[child]) {
			// edge node- child is a back edge
			low[node] = min(low[node], in[child]);
		}
		else {
			// edge node- child is a forward edge
			dfs(child, node);
			if(low[child] > in[node]) 
				cout << node << " - " << child << " is a bridge.\n";
			
			low[node] = min(low[node], low[child]);
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	
	int x, y;
	while(m--)
		cin >> x >> y, graph[x].push_back(y), graph[y].push_back(x);
	
	dfs(1, -1);
		
	return 0;
}
