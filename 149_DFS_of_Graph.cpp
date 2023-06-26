#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int src, vector<int> adj[], vector<int> &ans, vector<int> &visited){
        visited[src]=1;
        ans.push_back(src);
        for(auto it: adj[src]){
            if(!visited[it]){
                dfs(it, adj, ans, visited);
            }
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> visited(v,0);
        for(int i=0;i<v;i++){
            if(!visited[i])
                dfs(i, adj, ans, visited);
        }
        return ans;
    }
};