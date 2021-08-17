/*
     Complexity: Time=>O(n2)   , Space=>O(n)
     Link : https://leetcode.com/problems/arithmetic-slices/
     Logic: dp
     Source: 
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return 0;
        int dp[n];
        dp[0]=0;
        dp[1]=0;
        int result=0;
        for(int i=2;i<n;i++)
        {
            if((nums[i-2]-nums[i-1])==(nums[i-1]-nums[i]))
            {
                dp[i]=dp[i-1]+1;
                result+=dp[i];
            }
            else
            {
                dp[i]=0;
            }
        }
        return result;
    }
};