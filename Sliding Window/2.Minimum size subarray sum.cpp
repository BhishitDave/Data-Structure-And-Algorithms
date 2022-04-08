/*
     Complexity: Time=>O(n)   , Space=>O(1)
     Link : https://leetcode.com/problems/minimum-size-subarray-sum/
     Logic:
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int start=0 ,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                ans = min(ans,i - start +1);
                sum-=nums[start];
                start++;
            }
        }
        if(ans== INT_MAX)
            return 0;
        return ans;
    }
};