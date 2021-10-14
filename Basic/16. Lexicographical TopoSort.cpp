// Topological sort but in the lexicographically minimum order
// Problem link: https://www.spoj.com/problems/TOPOSORT/

#include<bits/stdc++.h>
using namespace std;

const int mxNodes = 10000;
vector<int>graph[mxNodes];
int inDegree[mxNodes];
vector<int>topoSort;

bool kahn(int nodes) {
	priority_queue<int, vector<int>, greater<int>> min_q;
	
	for(int i=1; i<=nodes; i++) {
		if(inDegree[i] == 0) min_q.push(i);
	}
	
	while(!min_q.empty()) {
		int current = min_q.top();
		topoSort.push_back(current);
		min_q.pop();
		
		for(int child: graph[current]) {
			inDegree[child]--;
			if(inDegree[child] == 0) min_q.push(child);
		}
	}
	
	return nodes==(int)topoSort.size();
}

int main() {
	int nodes, edges; cin >> nodes >> edges;
	for(int i=1; i<=edges; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b]++;
	}
	
	if(kahn(nodes)) {
		for(int node: topoSort) cout << node << " ";
	}
	else cout << "Sandro fails.";
	cout << endl;
}
