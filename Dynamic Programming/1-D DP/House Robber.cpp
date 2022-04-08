/*
     Complexity: Time=>O(n)   , Space=>O(n)
     Link : https://leetcode.com/problems/house-robber/
     Logic:
     Source:
*/
// *******recursive*******
class Solution {
public:
    int solve(vector<int>& nums ,int i)
    {
        if(i<0)
            return 0;
        if(i==0)
            return nums[0];
        return max(solve(nums, i-1) , nums[i]+solve(nums, i-2));
        
    }
    int rob(vector<int>& nums) {
        return solve(nums , nums.size()-1);
    }
};
//************dp************
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        if(n==1)
            return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1] , dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};