// Using path compression and union by rank
// Problem link: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/reunion-of-1s-1b5bd063/

#include<bits/stdc++.h>
using namespace std;
 
#define fl(st, en, i) for(int i = st; i < en; i++)
#define el "\n"

const int nodes = 1e5+5;

int parent[nodes], Rank[nodes];

int findParent(int node) {
    if(parent[node] == -1) return node;

    return parent[node] = findParent(parent[node]);
}

void Union(int a, int b) {
    if(Rank[a] > Rank[b]) {
        parent[b] = a;
        Rank[a] += Rank[b];
    }
    else {
        parent[a] = b;
        Rank[b] += Rank[a];
    }
}

void merge(int a, int b) {
    a = findParent(a); b = findParent(b);

    if(a != b) Union(a, b);
}

int main() {
    int n, k, mx = 0; cin >> n >> k;
    char str[nodes];

    fl(1, n+1, i) {
        cin >> str[i];

        if(str[i] == '1') {
            Rank[i] = 1;
            parent[i] = -1;

            if(i>1 && str[i-1] == '1') merge(i, i-1);

            int p = findParent(i);
            if(Rank[p] > mx) mx = Rank[p];
        }
    }

    fl(0, k, i) {
        int type; cin >> type;

        if(type == 1) cout << mx << el;
        else {
            int index; cin >> index;

            if(str[index] == '1') continue;

            str[index] = '1';
            Rank[index] = 1;
            parent[index] = -1;

            if(index > 1 && str[index-1] == '1') merge(index-1, index);
            if(index < n && str[index+1] == '1') merge(index, index+1);

            int p = findParent(index);
            if(mx < Rank[p]) mx = Rank[p];
        }
    }
}
