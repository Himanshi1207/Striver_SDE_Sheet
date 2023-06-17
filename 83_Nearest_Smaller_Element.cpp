#include <bits/stdc++.h>
using namespace std;
vector<int> prevSmaller(vector<int> &a)
{
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            st.push(a[i]);
        else if (st.top() < a[i])
        {
            ans[i] = st.top();
            st.push(a[i]);
        }
        else
        {
            while (!st.empty() and st.top() >= a[i])
                st.pop();
            if (!st.empty() and st.top() < a[i])
                ans[i] = st.top();
            st.push(a[i]);
        }
    }
    return ans;
}
