#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int vertices, vector<vector<int>> &adj, int source)
    {
        // Code here
        vector<int> dist(vertices, 1e8);
        dist[source] = 0;
        for (int i = 0; i < vertices; i++)
        {
            for (auto edge : adj)
            {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                dist[v] = min(dist[v], dist[u] + weight);
            }
        }
        for (auto edge : adj)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if (dist[v] > dist[u] + weight)
                return {-1};
        }
        return dist;
    }
};