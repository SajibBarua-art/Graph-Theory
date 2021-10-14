// Kahn's Algorithm to find the Topological Sort
// Time complexity: O(nodes + edges)

#include<bits/stdc++.h>
using namespace std;

const int mxNodes = 10000;
vector<int>graph[mxNodes];
vector<int>topSort;
int inDegree[mxNodes];

void kahn(int nodes) {
	queue<int>q;
	for(int i=1; i<=nodes; i++)
		if(inDegree[i] == 0) q.push(i);
	
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		topSort.push_back(current);
		
		for(int child: graph[current]) {
			inDegree[child]--;
			if(inDegree[child] == 0) q.push(child);
		}
	}
	
	cout << "TopSort is: ";
	for(int current: topSort)
		cout << current << " ";
	cout << endl;
}

int main() {
	int nodes, edges; cin >> nodes >> edges;
	for(int i=1; i<=edges; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b]++;
	}
	
	kahn(nodes);
}
