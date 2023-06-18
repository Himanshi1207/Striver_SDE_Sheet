#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int start = -1, end = -1;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; j++, i++)
            {
                if (gap == 0)
                    dp[i][j] = 1;
                else if (gap == 1)
                {
                    if (s[i] == s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                {
                    if (s[i] == s[j] and dp[i + 1][j - 1] == 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                if (dp[i][j])
                {
                    start = i;
                    end = j;
                }
            }
        }
        string ans = "";
        for (int i = start; i <= end; i++)
            ans += s[i];
        return ans;
    }
};