// Kosaraju's algorithm for finding the SCC
// Problem Link: https://www.codechef.com/problems/CHEFRRUN

#include<bits/stdc++.h>
using namespace std;

const int nodes = 1e6+5;
vector<int> graph[nodes], traverseGraph[nodes], order;
int isVisited[nodes]; 

void DFS(int node) {
	isVisited[node] = 1;

	for(int child: graph[node]) 
		if(isVisited[child] == 0) DFS(child);

	order.push_back(node);
}

void traverseDFS(int node, int *cnt) {
	isVisited[node] = 1;

	for(int child: traverseGraph[node])
		if(isVisited[child] == 0) traverseDFS(child, cnt);

	*cnt = *cnt+1;
}

void testCase() {
	int n; cin >> n;

	for(int i=1; i<=n; i++) {
		graph[i].clear();
		traverseGraph[i].clear();
		isVisited[i] = 0;	
	}
	order.clear();

	set<int> s;
	for(int i=1; i<=n; i++) {
		int dis; cin >> dis;

		int j = (dis+i+1)%n;
		if(j==0) j=n;

		if(i == j) { s.insert(i); continue; }
		
		graph[i].push_back(j);
		traverseGraph[j].push_back(i);
	}

	for(int i=1; i<=n; i++)
		if(isVisited[i] == 0) DFS(i);

	for(int i=1; i<=n; i++) isVisited[i] = 0;

	int ans = s.size();

	for(int i=n-1; i>=0; i--) {
		int cnt=0;
		if(isVisited[order[i]] == 0) {
			traverseDFS(order[i], &cnt);
		}
		
		if(cnt>1) ans += cnt;
	}

	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	while(t--) testCase();
}