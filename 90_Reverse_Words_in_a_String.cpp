#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            string temp = "";
            if (s[i] == ' ')
                continue;
            while (s[i] != ' ' and i < s.size())
            {
                temp += s[i];
                i++;
            }

            st.push(temp);
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
            if (!st.empty())
            {
                ans += " ";
            }
        }
        return ans;
    }
};