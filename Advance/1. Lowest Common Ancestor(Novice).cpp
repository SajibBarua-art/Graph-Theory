// Lowest Common ancestor in Naive approach

#include<bits/stdc++.h>
using namespace std;

const int nodes = 1e4+5;
int level[nodes], parent[nodes];
vector<int> graph[nodes];

int LCA(int a, int b) {
    if(level[a] > level[b]) swap(a, b);
    int d = level[b]-level[a];

    while(d>0) {
        b = parent[b];
        d--;
    }

    if(a == b) return a;

    while(parent[a] != parent[b]) {
        a = parent[a];
        b = parent[b];
    }

    return parent[a];
}

void dfs(int node, int lev = 0) {
    level[node] = lev;

    for(int child: graph[node]) {
        dfs(child, lev+1);
    }
}

int main() {
    int n, m; cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        
        // graph is pointing from a to b node
        graph[a].push_back(b);

        parent[b] = a;
    }

    dfs(1);

    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        
        cout << LCA(a, b) << endl;
    }
}