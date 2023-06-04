//TC-O(3N)
//SC-O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==0 or n==1)
            return;
        if(n==2){
            swap(nums[0],nums[1]);
            return;
        }
        int bp=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                bp=i;
                break;
            }
        }
        if(bp==-1){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(int i=n-1;i>=0;i--){
                if(nums[i]>nums[bp]){
                    swap(nums[i], nums[bp]);
                    break;
                }
            }
            reverse(nums.begin()+bp+1, nums.end());
        }
    }
};