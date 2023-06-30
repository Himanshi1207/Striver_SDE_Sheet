#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPal(string &s)
    {
        int i = 0, j = s.length() - 1;
        while (i <= j)
        {
            if (s[i++] != s[j--])
                return 0;
        }
        return 1;
    }

    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int mini = INT_MAX;
            string temp = "";
            for (int j = i; j < n; j++)
            {
                temp += str[j];
                if (isPal(temp))
                {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};