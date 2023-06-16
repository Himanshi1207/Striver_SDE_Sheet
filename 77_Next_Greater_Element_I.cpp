#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            int check = 0, a = -1;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                    check = 1;
                if (check and nums2[j] > nums1[i])
                {
                    a = nums2[j];
                    break;
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};