#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool> &visited, vector<int> &order, vector<vector<int>> &adj)
{
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v])
            dfs(v, visited, order, adj);
    }
    order.push_back(u);
}

int kosaraju(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto it : edges)
        adj[it[0]].push_back(it[1]);

    vector<int> order;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, visited, order, adj);
    }

    vector<vector<int>> rev(V);
    for (auto it : edges)
        rev[it[1]].push_back(it[0]);

    reverse(order.begin(), order.end());

    int scc = 0;
    vector<bool> vis2(V, false);

    for (auto node : order)
    {
        if (!vis2[node])
        {
            vector<int> temp;
            dfs(node, vis2, temp, rev);
            scc++;
        }
    }
    return scc;
}