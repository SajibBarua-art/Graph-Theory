// Using path compression and union by rank
// Problem link: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/reunion-of-1s-1b5bd063/

#include<bits/stdc++.h>
using namespace std;
 
#define fl(st, en, i) for(int i = st; i < en; i++)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)   __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)   __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)   __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define Case cout << "Case " << c << ": "
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define el "\n"
const int mod = 1e9+7;

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
