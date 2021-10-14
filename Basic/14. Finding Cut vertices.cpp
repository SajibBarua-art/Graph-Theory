// Finding the number of cut vertices
// Problem link: https://www.spoj.com/problems/SUBMERGE/

#include<bits/stdc++.h>
using namespace std;

const int nodes = 1e4+5;

vector<int> graph[nodes];
int isVisited[nodes], in[nodes], low[nodes], timer;
set<int> cut_vertices;

void dfs(int node, int parent=-1) {
	isVisited[node] = 1;
	in[node] = low[node] = timer++;
	
	int children=0;
	for(int child:graph[node]) {
		if(parent == child) continue;
		
		if(isVisited[child]) {
			low[node] = min(in[child], low[node]);
		}
		else {
			dfs(child, node);
			
			low[node] = min(low[node], low[child]);
			if(low[child] >= in[node] && parent != -1) 
				cut_vertices.insert(node);
			children++;
		}
	}
	
	if(parent == -1 && children>1) cut_vertices.insert(node);
}

void testCase(int edges) {
	for(int i=0; i<edges; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	dfs(1);
	cout << cut_vertices.size() << endl;
}

int main() {
	// When we get n=0 and m=0 then the program will be terminated
	while(1) {
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		
		for(int i=1; i<=n; i++) graph[i].clear(), isVisited[i]=0;
		cut_vertices.clear();
		
		testCase(m);
	}
}
