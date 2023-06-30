#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        // memset(dp,0,sizeof(dp));
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i == 1)
                    dp[i][j] = j;
                else if (j == 1)
                    dp[i][j] = 1;
                else
                {
                    int mini = INT_MAX;
                    for (int mj = j - 1, pj = 0; mj >= 0; mj--, pj++)
                    {
                        int v1 = dp[i][mj];
                        int v2 = dp[i - 1][pj];
                        int val = max(v1, v2);
                        mini = min(mini, val);
                    }
                    dp[i][j] = mini + 1;
                }
            }
        }
        return dp[n][k];
    }
};