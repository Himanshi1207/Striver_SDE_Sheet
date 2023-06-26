#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
            {
                color[i] = -1;
                queue<int> q;
                q.push(i);
                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();
                    for (auto it : graph[x])
                    {
                        if (color[it] == color[x])
                        {
                            return false;
                        }
                        else if (color[it] == 0)
                        {
                            color[it] = -color[x];
                            q.push(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};