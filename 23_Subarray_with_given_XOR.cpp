// TC-O(n)
// SC-O(n)
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B) {
unordered_map<int,int> mp;
    int cnt=0, xorr=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        xorr=xorr^A[i];
        if(mp.find(xorr^B)!=mp.end()){
            cnt+=mp[xorr^B];
        }
        if(xorr==B)
            cnt++;
        mp[xorr]++;
        
    }
    return cnt;
}
