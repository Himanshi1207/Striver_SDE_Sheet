#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int pre = 1, suffix = 1;
        int ans = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1;
            if (suffix == 0)
                suffix = 1;
            pre = pre * nums[i];
            suffix = suffix * nums[n - i - 1];
            ans = max(ans, max(suffix, pre));
        }
        return ans;
    }
};