#include <bits/stdc++.h>
using namespace std;
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &m, int n)
    {
        // code here
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);
        while (st.size() >= 2)
        {
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            if (m[i][j] == 1)
                st.push(j);
            else
                st.push(i);
        }
        int pot = st.top();
        st.pop();
        for (int i = 0; i < n; i++)
        {
            if (i != pot)
            {
                if (m[i][pot] == 0 or m[pot][i] == 1)
                    return -1;
            }
        }
        return pot;
    }
};