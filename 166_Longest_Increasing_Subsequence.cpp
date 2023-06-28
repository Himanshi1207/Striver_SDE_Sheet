#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int ans = INT_MIN;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i]++;
            for (int j = i - 1; j >= 0; j--)
            {
                // cout<<"j loop"<<endl;
                // cout<<dp[j]<<"<"<<dp[i]<<endl;
                if (nums[j] < nums[i])
                {
                    // cout<<"enter "<<i<<" "<<j<<endl;
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};