#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int dp[N + 1][N + 1];
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int helper(int ind, int w, int wt[], int val[])
    {
        if (ind == 0)
        {
            if (wt[0] <= w)
            {
                return val[0];
            }
            return 0;
        }
        if (dp[ind][w] != -1)
            return dp[ind][w];
        int notTake = 0 + helper(ind - 1, w, wt, val);
        int take = INT_MIN;
        if (wt[ind] <= w)
            take = val[ind] + helper(ind - 1, w - wt[ind], wt, val);
        return dp[ind][w] = max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        memset(dp, -1, sizeof(dp));
        return helper(n - 1, W, wt, val);
    }
};