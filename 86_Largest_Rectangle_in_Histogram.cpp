#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int n=heights.size();
        vector<int> leftsmaller(n), rightsmaller(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())
                leftsmaller[i]=0;
            else
                leftsmaller[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())
                rightsmaller[i]=n-1;
            else
                rightsmaller[i]=st.top()-1;
            st.push(i);
        }
        for(int i=0;i<n;i++){
            ans=max(ans, heights[i]*(rightsmaller[i]-leftsmaller[i]+1));
        }
        return ans;
    }
};