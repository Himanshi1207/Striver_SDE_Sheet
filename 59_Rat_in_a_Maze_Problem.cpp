// TC-exponential 4^(m*n)
// SC-O(N*N)
#include<bits/stdc++.h>
using namespace std;
// User function template for C++


class Solution{
    public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis){
        if(i==n-1 and j==n-1)
        {
            ans.push_back(move);
            return;
        }
        int dr[4]={1,0,0,-1};
        int dc[4]={0,-1,1,0};
        char ch[4]={'D','L','R','U'};
        for(int k=0;k<4;k++){
            int ni=dr[k]+i;
            int nj=dc[k]+j;
            if(ni>=0 and ni<n and nj>=0 and nj<n and vis[ni][nj]==0 and a[ni][nj]==1){
                // cout<<"enter";
                vis[i][j]=1;
                // cout<<ch[k]<<endl;
                solve(ni, nj, a, n, ans, move+ch[k], vis);
                vis[i][j]=0;
            }
            
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        if(m[0][0]==1)
        solve(0,0,m,n,ans,"",vis);
        return ans;
    }
};

    