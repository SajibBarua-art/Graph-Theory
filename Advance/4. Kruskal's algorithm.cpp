// Kruskal's Algorithm for finding the MST

#include<iostream>
#include<algorithm>
using namespace std;

struct edge {
    int a, b, w;
};

const int totalEdge = 1e5+3, totalNodes = 1e4+3;
edge graph[totalEdge];
int parent[totalNodes];
int Rank[totalNodes];

bool comp(edge a, edge b) {
    if(a.w < b.w) return true;

    return false;
}

int find(int a) {
    if(parent[a] < 0) return a;

    // path compression
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    // union by rank
    if(Rank[a] > Rank[b]) {
        Rank[a] += Rank[b];
        parent[b] = a;
    }
    else {
        Rank[b] += Rank[a];
        parent[a] = b;
    }
}

int main() {
    int n, m, a, b, w; cin >> n >> m;

    for(int i=1; i<=n; i++) {
        parent[i] = -1;
        Rank[i] = 1;
    }

    for(int i=0; i<m; i++) {
        cin >> graph[i].a >> graph[i].b >> graph[i].w;
    }

    sort(graph, graph+m, comp);

    int sum = 0;

    for(int i=0; i<m; i++) {
        a = find(graph[i].a);
        b = find(graph[i].b);

        if(a != b) {
            sum += graph[i].w;
            Union(a, b);
        }
    }

    cout << sum << endl; 
}