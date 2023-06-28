#include <bits/stdc++.h>
using namespace std;
int maxSumIS(int arr[], int n)
{
    // Your code goes here
    int ans = 0;
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = arr[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}