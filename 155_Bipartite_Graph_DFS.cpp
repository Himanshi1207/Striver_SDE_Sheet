#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int src, int col, vector<int> &color, vector<int> adj[])
    {
        color[src] = col;
        for (auto it : adj[src])
        {
            if (color[it] == -1)
            {
                if (dfs(it, !col, color, adj) == false)
                    return false;
            }
            else if (color[it] == col)
                return false;
        }
        return true;
    }
    bool isBipartite(int v, vector<int> adj[])
    {
        // Code here
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, color, adj) == false)
                    return false;
            }
        }
        return true;
    }
};
