// TC-Exponential as recursive
// SC-Auxilliary Stack space
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(vector<int> &arr, int idx, int sum, vector<int> &ans)
    {
        if (idx == -1)
        {
            ans.push_back(sum);
            return;
        }
        helper(arr, idx - 1, sum + arr[idx], ans);
        helper(arr, idx - 1, sum, ans);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        helper(arr, n - 1, 0, ans);
        return ans;
    }
};