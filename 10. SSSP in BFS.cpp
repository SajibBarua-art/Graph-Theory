// Single Source Shortest Path by Breadth First Search(BFS)
// Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
// To calculate all the distance of one to others 

#include<iostream>
#include<vector>
#include<queue>
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

int dist[nodes+1], is_visited[nodes+1];
void BFS(int source) {
	is_visited[source] = 1;
	dist[source] = 0;
	queue<int> q;
	q.push(source);
	
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		
		for(int child: graph[current]) {
			if(is_visited[child] == 0) {
				q.push(child);
				dist[child] = dist[current] + 1;
				is_visited[child] = 1;
			}
		}
	}
}

void testCase() {
	int n, m; cin >> n >> m;
	
	for(int i=1; i<=n; i++) graph[i].clear(), is_visited[i]=0;
	
	graph_represent(m);
	
	BFS(1);
	
	cout << dist[n] << endl;
}

int main() {
	int t; cin >> t;
	
	while(t--) testCase();
	
	return 0;
}
