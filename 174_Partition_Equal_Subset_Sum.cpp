#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(vector<int> &nums, int idx, int sum, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (nums[idx] == sum or sum == 0)
                return true;
            else
                return false;
        }
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        bool notTake = solve(nums, idx - 1, sum, dp);
        bool take = false;
        if (nums[idx] <= sum)
        {
            take = solve(nums, idx - 1, sum - nums[idx], dp);
        }
        return dp[idx][sum] = take or notTake;
    }
    bool canPartition(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return false;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        if (sum % 2 == 1)
            return 0;
        int k = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (arr[0] <= k)
            dp[0][arr[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool nottake = dp[ind - 1][target];
                bool take = false;
                if (arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = nottake or take;
            }
        }
        return dp[n - 1][k];
    }
};