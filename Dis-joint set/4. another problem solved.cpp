// Path compression + Union by rank
// Problem link: https://cses.fi/problemset/task/1676/

#include<bits/stdc++.h>
using namespace std;

const int nodes = 1e5+5;
int parent[nodes], Rank[nodes];

int Union(int a, int b) {
    // value of Rank[a] is bigger always
    if(Rank[a] < Rank[b]) swap(a, b);

    Rank[a] += Rank[b];
    parent[b] = a;
    return Rank[a];
}

int findParent(int node) {
    if(parent[node] == -1) return node;

    return parent[node] = findParent(parent[node]);
}

int main() {
    int n, m; cin >> n >> m;

    for(int i=1; i<=n; i++) parent[i] = -1, Rank[i] = 1;

    int mx=1, cc=n;
    while(m--) {
        int a, b; cin >> a >> b;

        int a_parent = findParent(a);
        int b_parent = findParent(b);

        if(a_parent != b_parent) {
            mx = max(mx, Union(a_parent, b_parent));
            cc--;
        }

        cout << cc << " " << mx << endl;
    }
}