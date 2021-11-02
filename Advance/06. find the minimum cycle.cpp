// find the cycle which have minimum number of nodes
// time complexity: O(nodes * (nodes+edges));
// problem link: https://lightoj.com/problems/category/bfs-dfs

#include <bits/stdc++.h>
using namespace std;

#define fl(st, en, i) for (int i = st; i < en; i++)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define count_one(a) __builtin_popcount(a) // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i) __builtin_parity(i)      // even parity 0 and odd parity 1
#define blz(a) __builtin_clz(a)            // Returns the number of leading zeroes in a number(a)
#define btz(a) __builtin_ctz(a)            // Returns the number of trailing zeroes in a number(a)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define Case(c) cout << "Case " << c << ": "
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define el "\n"
const int mod = 1e9 + 7;

const int nodes = 503;

vector<int>graph[nodes];

int bfs(int node) {
    queue<int> q;
    q.push(node);
    vector<int> dist(nodes, INT_MAX);
    vector<int> parent(nodes, -1);

    int mini = INT_MAX;

    dist[node] = 0;

    while(! q.empty()){
        int curr = q.front();
        q.pop();

        for(int child: graph[curr]) {
            if(dist[child] == INT_MAX) {
                dist[child] = dist[curr] + 1;
                parent[child] = curr;

                q.push(child);
            }

            else if(parent[curr] != child) {
                mini = min(mini, dist[child]+dist[curr]+1);
            }
        }
    }

    return mini;
}

void init(int n) {
    fl(0, n, i) graph[i].clear();
} 

int shortestCycle(int n) {
    int ans = INT_MAX;

    fl(0, n, i) {
        ans = min(ans, bfs(i));
    }

    return ans;
}

void testCase() {
    int n, m; cin >> n >> m;

    init(n);

    fl(0, m, i) {
        int a, b; cin >> a >> b;
        
        if(a == b) continue;

        graph[a].pb(b);
        graph[b].pb(a);
    }

    int mini = shortestCycle(n);

    if(mini == INT_MAX) cout << "impossible\n";
    else cout << mini << el;
}

int main()
{
    fio;
    int t;
    cin >> t;
    fl(1, t+1, i) {
        Case(i);

        testCase();
    }
}
