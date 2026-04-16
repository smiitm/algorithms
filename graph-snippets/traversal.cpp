#include<bits/stdc++.h>
using namespace std;

// O(V + E) time complexity
vector<int> BFS(vector<vector<int>> adjList)
{
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<int> bfs;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(int neighbour : adjList[node])
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }
    }
    return bfs;
}

// O(V + E) time complexity
vector<int> DFS(vector<vector<int>> adjList)
{
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<int> dfs;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            stack<int> s;
            s.push(i);
            visited[i] = true;
            while(!s.empty())
            {
                int node = s.top();
                s.pop();
                dfs.push_back(node);
                for(int neighbour : adjList[node])
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        s.push(neighbour);
                    }
                }
            }
        }
    }
    return dfs;
}

// its just BFS
int countComponents(vector<vector<int>> adjList)
{
    int n = adjList.size();
    vector<bool> visited(n, false);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            ans++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(int neighbour : adjList[node])
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }
    }
    return ans;
}