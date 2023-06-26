#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCycle(vector<int> adj[], vector<int> &visited, int id){
        if(visited[id]==1)return true;
        if(visited[id]==0){
            visited[id]=1;
            for(auto it: adj[id]){
                if(isCycle(adj, visited, it))
                    return true;
            }
        }
        visited[id]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(isCycle(adj, visited, i))
                return false;
        }
        return true;
    }
};