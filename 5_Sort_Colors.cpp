//Using DNF(Dutch National Flag)
//TC-O(N)
//SC-O(1)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high){
            if(nums[mid]==0)
                swap(nums[mid++], nums[low++]);
            else if(nums[mid]==1)
                mid++;
            else if(nums[mid]==2){
                swap(nums[mid], nums[high--]);
            }
        }
    }
};