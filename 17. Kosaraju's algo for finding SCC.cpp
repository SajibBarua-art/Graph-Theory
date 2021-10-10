#include <bits/stdc++.h>
using namespace std;

const int nodes = 1e3 + 4;
vector<int> graph[nodes], traverseGraph[nodes];
int isVisited[nodes];
vector<int> order;
vector<int> scc;

void dfs(int node)
{
    isVisited[node] = 1;

    for (int child : graph[node])
    {
        if (isVisited[child] == 0)
            dfs(child);
    }

    order.push_back(node);
}

void traverseDFS(int node)
{
    isVisited[node] = 1;

    for (int child : traverseGraph[node])
    {
        if (isVisited[child] == 0)
            traverseDFS(child);
    }

    scc.push_back(node);
}

void testCase()
{
    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        isVisited[i] = 0;
        graph[i].clear();
        traverseGraph[i].clear();
    }
    order.clear();

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        traverseGraph[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        if (isVisited[i] == 0)
            dfs(i);

    for (int i = 1; i <= n; i++)
        isVisited[i] = 0;

    for (int i = n-1; i >= 0; i--)
    {
        if (isVisited[order[i]] == 0)
        {
            scc.clear();

            traverseDFS(order[i]);

            cout<<"traverseDFS() called from "<<order[i]<<" and printing SCC"<<endl;
            for (int node : scc)
                cout << node << " ";
            cout << "\n";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        testCase();
    }
}