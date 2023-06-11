#include<bits/stdc++.h>
using namespace std;
class Solution{

	public:
	int minCoins(int nums[], int n, int target) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(n, vector<int> (target+1,0));
	    for(int t=0;t<=target;t++){
	        if(t%nums[0]==0)
	            dp[0][t]=t/nums[0];
	       else
	       dp[0][t]=1e9;
	    }
	    for(int ind=1;ind<n;ind++){
	        for(int t=0;t<=target;t++){
	            int nottake=0+dp[ind-1][t];
	            int take=INT_MAX;
	            if(nums[ind]<=t){
	                take=1+dp[ind][t-nums[ind]];
	            }
	            dp[ind][t]=min(take, nottake);
	        }
	    }
	    int ans=dp[n-1][target];
	    if(ans>=1e9)
	    return -1;
	    return ans;
	} 
	  
};