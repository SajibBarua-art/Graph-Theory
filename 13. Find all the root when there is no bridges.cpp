// If there is no bridges then find the one-directional root
// to travel all nodes to others
// Problem Link: https://codeforces.com/contest/118/problem/E

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

const int nodes=2e5+5;
vector<int>graph[nodes];
int in[nodes], low[nodes], isVisited[nodes];
int timer;
vector<pair<int, int>> edgeList;

int dfs(int node, int parent) {
	isVisited[node]=1;
	in[node] = low[node] = timer;
	timer++;
	
	for(int child : graph[node]) {
		if(child == parent) continue;
		if(isVisited[child]) {
			// edge node- child is a back edge
			low[node] = min(low[node], in[child]);
			
			// otherwise visited will be counted more then one
			if(in[node]>in[child])
			edgeList.push_back({node, child});
		}
		else {
			// edge node- child is a forward edge
			if(dfs(child, node) == 0) return 0;
			if(low[child] > in[node]) return 0;
			
			low[node] = min(low[node], low[child]);
			
			edgeList.push_back({node, child});
		}
	}
	
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	
	int x, y;
	for(int i=0; i<m; i++)
		cin >> x >> y, graph[x].push_back(y), graph[y].push_back(x);
	
	if(dfs(1, -1) == 0) cout << 0 << endl;
	else {
		for(pair<int,int> e: edgeList) {
			cout << e.first << " " << e.second << endl;
		}
	}
		
	return 0;
}
