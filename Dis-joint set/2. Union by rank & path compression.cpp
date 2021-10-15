// Using union by rank and Path compression together
// The combined time complexity is almost constant. O(1)

#include<bits/stdc++.h>
using namespace std;

const int nodes = 1e5+5;

int ar[nodes], Rank[nodes];

int findParent(int node) {
	if(ar[node]<0) return node;

	// using path compression
	return ar[node] = findParent(ar[node]);
}

void merge(int a, int b) {
	a = findParent(a); b = findParent(b);

	// using union by rank
	if(a != b) {
		if(Rank[a] > Rank[b]) {
			// a would be parent
			Rank[b] = a;
			Rank[a] += Rank[b];
		}
		else {
			// b would be parent
			Rank[a] = b;
			Rank[a] += Rank[b];
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	
	for(int i=1; i<=n; i++) ar[i] = -i, Rank[i] = 1;

	for(int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;

		merge(a, b);
	}
}