//TC-O(N)
//SC-O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int n=prices.size();
        int ans=0;
        for(int i=1;i<n;i++){
            mini=min(mini, prices[i]);
            ans=max(ans, prices[i]-mini);
        }
        return ans;
    }
};