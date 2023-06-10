// ṬC-O(N)
// SC-O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                curr++;
                ans = max(ans, curr);
            }
            else
            {
                curr = 0;
            }
        }
        return ans;
    }
};