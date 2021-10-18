// Calculating Lowest Common Ancestor in Binary Lifting
// Time & Space complexity: O(nlog n)

#include<bits/stdc++.h>
using namespace std;

const int nodes = 1e4+5, maxN = log2(nodes);
vector<int> graph[nodes];
int LCA[nodes][maxN], level[nodes];
int n, m, logN;

void dfs(int node, int parent = -1, int height = 0) {
	LCA[node][0] = parent;
	level[node] = height;

	for(int child: graph[node]) 
		dfs(child, node, height+1);
}

void init() {
	for(int i=1; i<=n; i++) 
		for(int j=0; j<=logN; j++)
			LCA[i][j] = -1;

	dfs(1);

	// getting ready the sparse table
	for(int j=1; j<=logN; j++) {
		for(int i=1; i<=n; i++) {
			if(LCA[i][j-1] != -1) {
				int parent = LCA[i][j-1];
				LCA[i][j] = LCA[parent][j-1];
			}
		}
	}
}

int calc_LCA(int a, int b) {
	if(level[a] > level[b]) swap(a, b);

	int distance = level[b] - level[a];

	while(distance > 0) {
		int j = log2(distance);
		b = LCA[b][j];
		distance -= (1 << j);
	}

	if(a == b) return a;

	for(int i = logN; i>=0; i--) {
		if(LCA[a][i] != -1 && LCA[a][i] != LCA[b][i]) {
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}

	return LCA[a][0];
}

int main() {
	cin >> n >> m; 
	logN = log2(n);

	for(int i=0; i<m; i++) {
		int a, b; cin >> a >> b;

		// from node 'a' to node 'b'
		graph[a].push_back(b);
	}

	init();

	int q; cin >> q;
	while(q--) {
		int a, b; cin >> a >> b;
		
		cout << calc_LCA(a, b) << endl;
	}
}