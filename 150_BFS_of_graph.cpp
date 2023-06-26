#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<int> visited(v, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for (auto it : adj[temp])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        return ans;
    }
};