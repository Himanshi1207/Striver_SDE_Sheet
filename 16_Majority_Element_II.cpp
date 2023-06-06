// TC-O(n)
// SC-O(1)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int cnt1=0, cnt2=0;
	int el1=INT_MIN;
	int el2=INT_MIN;
	for(int i=0;i<v.size();i++){
		if(cnt1==0 and el2!=v[i]){
			cnt1=1;
			el1=v[i];
		}
		else if(cnt2==0 and el1!=v[i]){
			cnt2=1;
			el2=v[i];
		}
		else if(v[i]==el1) cnt1++;
		else if(v[i]==el2) cnt2++;
		else
		{
			cnt1--;
			cnt2--;
		}
	}
	cnt2=0, cnt1=0;
	for(int i=0;i<v.size();i++){
		if(v[i]==el1)cnt1++;
		else if(v[i]==el2)cnt2++;
	}
	vector<int> ans;
	int mini=(int)v.size()/3+1;
	if(cnt1>=mini)
	ans.push_back(el1);
	if(cnt2>=mini)
	ans.push_back(el2);
	sort(ans.begin(), ans.end());
	return ans;
    }
};