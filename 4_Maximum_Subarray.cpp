//using kadane's algo
//TC-O(N)
//SC-O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int ans=INT_MIN;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(curr<=0)
                curr=0;
            ans=max(ans, curr);
        }
        return ans;
    }
};