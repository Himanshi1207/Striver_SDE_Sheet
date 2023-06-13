// TC-exponential
// SC-O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node, bool graph[101][101], int color[], int n, int col)
    {
        for (int k = 0; k < n; k++)
        {
            if (k != node and graph[k][node] == 1 and color[k] == col)
                return false;
        }
        return true;
    }
    bool solve(int node, int color[], bool graph[101][101], int m, int n)
    {
        if (node == n)
            return true;
        for (int i = 1; i <= m; i++)
        {
            if (isSafe(node, graph, color, n, i))
            {
                color[node] = i;
                if (solve(node + 1, color, graph, m, n))
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {
        // your code here
        int color[n] = {0};
        if (solve(0, color, graph, m, n))
            return true;
        return false;
    }
};