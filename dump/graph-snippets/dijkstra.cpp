#include <bits/stdc++.h>
using namespace std;

// List of edges as input
// Dijkstra's algorithm for shortest path in a graph with non-negative weights
// Time Complexity: O(E log V)
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{

    vector<vector<pair<int, int>>> graph(V);
    for (auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans(V, INT_MAX);

    ans[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();
        if (d > ans[node])
            continue;

        for (auto &[v, w] : graph[node])
        {
            if (ans[v] > ans[node] + w)
            {
                ans[v] = ans[node] + w;
                pq.push({ans[v], v});
            }
        }
    }

    return ans;
}

