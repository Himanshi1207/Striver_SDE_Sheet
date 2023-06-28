#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        st.insert({0, S});
        dist[S] = 0;
        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgW = it[1];
                if (dis + edgW < dist[adjNode])
                {
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};