#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPathUnweightedUndirected(int V, vector<vector<int>> &edges, int src)
{
    vector<vector<int>> graph(V);
    for (auto e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vector<int> dis(V, INT_MAX);
    dis[src] = 0;

    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : graph[node])
        {
            if (dis[child] > dis[node] + 1)
            {
                dis[child] = dis[node] + 1;
                q.push(child);
            }
        }
    }

    for (auto &d : dis)
    {
        if (d == INT_MAX)
            d = -1;
    }

    return dis;
}