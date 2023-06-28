#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    //  topological sort using dfs changing in stack
    void dfsTopo(vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st, int s)
    {
        vis[s] = true;
        for (int i : adj[s])
        {
            if (!vis[i])
                dfsTopo(adj, vis, st, i);
        }
        st.push(s);
    }
    void dfsNorm(vector<int> adjT[], vector<bool> &vis, int s)
    {
        vis[s] = true;
        for (int i : adjT[s])
        {
            if (!vis[i])
                dfsNorm(adjT, vis, i);
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // Kosaraju algorithm consists of 3 steps
        // 1. find topological sort (here we'll use dfs for it)
        // 2. reverse all edges (here we'll create a new adjacency list)
        // 3. perform normal dfs using topological sorted order
        //
        // Step 1. finding topological sort in stack
        stack<int> st;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfsTopo(adj, vis, st, i);
        }
        // Step 2. creating new adjacency list
        vector<int> adjT[V];
        for (int i = 0; i < V; i++)
        {
            vis[i] = false;
            for (int u : adj[i])
            {
                adjT[u].push_back(i);
            }
        }
        // Step 3. performing normal dfs
        int ans = 0;
        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            if (!vis[u])
            {
                ans++;
                dfsNorm(adjT, vis, u);
            }
        }
        return ans;
    }
};