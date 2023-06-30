#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &coins, int idx, int amt, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (amt % coins[0] == 0)
                return amt / coins[0];
            else
                return 1e9;
        }
        if (dp[idx][amt] != -1)
            return dp[idx][amt];
        int notTake = solve(coins, idx - 1, amt, dp);
        int take = 1e9;
        if (coins[idx] <= amt)
        {
            take = 1 + solve(coins, idx, amt - coins[idx], dp);
        }
        return dp[idx][amt] = min(take, notTake);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(coins, coins.size() - 1, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};