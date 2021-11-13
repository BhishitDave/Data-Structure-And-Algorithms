/*
     Complexity: Time=>O(n)   , Space=>O()
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
