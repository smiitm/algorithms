#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int,int>>> &graph, vector<bool>& visited, stack<int>& topo, int node) {
        visited[node] = true;
        for (auto &it : graph[node]) {
            int v = it.first;
            if (!visited[v]) {
                dfs(graph, visited, topo, v);
            }
        }
        topo.push(node);
    }

    vector<int> shortestPathDAG(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
        }

        vector<bool> visited(V, false);
        stack<int> topo;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(graph, visited, topo, i);
            }
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        while (!topo.empty()) {
            int node = topo.top();
            topo.pop();

            if (dist[node] != INT_MAX) {
                for (auto &it : graph[node]) {
                    int v = it.first;
                    int w = it.second;

                    if (dist[node] + w < dist[v]) {
                        dist[v] = dist[node] + w;
                    }
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }