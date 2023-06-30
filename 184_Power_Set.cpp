#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        // Code here
        int sz = s.size();
        vector<string> ans;
        for (int i = 0; i < ((1 << sz)); i++)
        {
            string str = "";
            for (int j = 0; j < sz; j++)
            {
                if (i & (1 << j))
                {
                    str.push_back(s[j]);
                }
            }
            //  cout<<str<<endl;
            if (str == "")
                continue;
            ans.push_back(str);
        }
        //  for(int i=0;i<ans.size();i++)
        //  cout<<ans[i]<<endl;
        //  cout<<endl;
        sort(ans.begin(), ans.end());
        return ans;
    }
};