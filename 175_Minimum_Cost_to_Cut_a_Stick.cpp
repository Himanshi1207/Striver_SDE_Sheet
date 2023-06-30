#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[102][102];
    int minCost(int n, vector<int> &cuts)
    {
        memset(dp, 0, sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        for (int left = cuts.size() - 1; left >= 0; left--)
        {
            for (int right = left + 1; right < cuts.size(); right++)
            {
                for (int i = left + 1; i < right; i++)
                {
                    int currcost = (cuts[right] - cuts[left]) + dp[left][i] + dp[i][right];
                    dp[left][right] = min(dp[left][right] == 0 ? INT_MAX : dp[left][right], currcost);
                }
            }
        }
        return dp[0][cuts.size() - 1];
    }
};