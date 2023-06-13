// TC-exponential
// SC-O(N)
#include <bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution
{
public:
    void solve(unordered_map<string, int> &mp, string s, vector<string> &ans, string temp)
    {
        if (s.size() == 0)
        {
            ans.push_back(temp.substr(1));
            return;
        }
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.find(s.substr(0, i + 1)) != mp.end())
            {
                solve(mp, s.substr(i + 1), ans, temp + " " + s.substr(0, i + 1));
            }
        }
        return;
    }
    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        // code here
        vector<string> ans;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
            mp[dict[i]]++;
        string ds = "";
        solve(mp, s, ans, ds);
        return ans;
    }
};