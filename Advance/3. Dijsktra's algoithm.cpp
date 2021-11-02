// Dijsktra's algorithm
// To find the distance of one node to others.

#include<bits/stdc++.h>
using namespace std;

const int nodes = 100005;
const int INF = INT_MAX;

vector< pair<int, int> > w_graph[nodes];
vector<int> dist(nodes, INF);

void dijsktra() {
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> >> pq;

	pq.push({0, 1});
	dist[1] = 0;

	while(! pq.empty()) {
		int curr_node = pq.top().second;
		int curr_dist = pq.top().first;
		pq.pop();

		for(pair<int, int> edge: w_graph[curr_node]) {
			if(curr_dist + edge.first < dist[edge.second]) {
				dist[edge.second] = curr_dist + edge.first;
				pq.push({ dist[edge.second], edge.second });
			}
		}
	}
}

int main() {
	int n, m; cin >> n >> m;

	for(int i=0; i<m; i++) {
		int a, b, w; cin >> a >> b >> w;

		w_graph[a].push_back({w, b});
		w_graph[b].push_back({w, a});
	}

	dijsktra();

	for(int i=1; i<=n; i++) cout << i << " " << dist[i] << endl;
}


// Example test case:
// 6 9
// 1 2 4
// 1 6 2
// 2 6 1
// 2 3 5
// 6 3 8
// 6 5 10
// 3 5 3
// 3 4 6
// 5 4 5