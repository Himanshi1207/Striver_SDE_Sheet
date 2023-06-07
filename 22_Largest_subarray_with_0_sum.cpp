// TC-O(n)
// SC-O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==0)
                maxi=i+1;
            else{
                if(mp.find(sum)!=mp.end()){
                    maxi=max(maxi, i-mp[sum]);
                }
                else{
                    mp[sum]=i;
                }
            }
        }
        return maxi;
    }
};