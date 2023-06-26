#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    void dfs(vector<int> adj[], vector<int> &visited, int src, vector<int> &ans)
    {
        visited[src] = 1;
        for (auto it : adj[src])
        {
            if (!visited[it])
            {
                dfs(adj, visited, it, ans);
            }
        }
        ans.push_back(src);
    }
    vector<int> topoSort(int v, vector<int> adj[])
    {
        // code here
        vector<int> visited(v, 0);
        vector<int> ans;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
                dfs(adj, visited, i, ans);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};