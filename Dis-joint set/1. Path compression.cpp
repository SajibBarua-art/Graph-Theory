// Disjoint set: Path compression
// Problem Link: https://assessment.hackerearth.com/challenges/college/codemania-20/algorithm/owl-fight/

#include<bits/stdc++.h>
using namespace std;

int ar[10004];

int findParent(int node) {
	if(ar[node] < 0) return node;

	return ar[node] = findParent(ar[node]);
}

void Union(int a, int b) {
	ar[a] = min(ar[a], ar[b]);
	ar[b] = a;
}

int main() {
	int n, m; cin >> n >> m;
	
	// first initialize all node is a parent node
	for(int i=1; i<=n; i++) ar[i] = -i;

	for(int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;

		a = findParent(a);
		b = findParent(b);

		if(a != b) Union(a, b);
	}

	int q; cin >> q;
	for(int i=1; i<=q; i++) {
		int a, b; cin >> a >> b;

		int x = findParent(a); int y = findParent(b);

		if(x == y) cout << "TIE\n";
		else{
			if(ar[x] < ar[y]) cout << a << endl;
			else cout << b << endl;
		}
	}
}