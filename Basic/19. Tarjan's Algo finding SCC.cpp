// Tarjan's Algorithm for finding SCC
// It is almost the same principle for finding bridges in a graph

#include <bits/stdc++.h>
using namespace std;

const int nodes = 1e3 + 4;
vector<int> graph[nodes];
bool isVisited[nodes], onStack[nodes];
stack<int> st;

int in[nodes], low[nodes];
int timer=1, SCC=0;

void dfs(int node) {
    isVisited[node] = 1;
    st.push(node);
    onStack[node] = 1;
    in[node] = low[node] = timer++;

    for(int child: graph[node]) {
        if(isVisited[child] == 1 && onStack[child]) {
            low[node] = min(low[node], in[child]);
        }
        else if(isVisited[child] == 0) {
            dfs(child);

            if(onStack[child])
                low[node] = min(low[child], low[node]);
        }
    }

    if(in[node] == low[node]) {
        SCC++;
        cout << "SCC #" << SCC << endl;

        while(1) {
            int current = st.top();
            st.pop();
            onStack[current] = false;
            cout << current << ' ';

            if(node == current) break;
        }

        cout << endl;
    }
}

int main()
{
    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    for(int i=1; i<=n; i++) 
        if(isVisited[i] == 0) dfs(i);
}