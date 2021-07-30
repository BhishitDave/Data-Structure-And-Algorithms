/*
     Name: Bhishit Dave
     Link : https://leetcode.com/problems/jump-game/submissions/
     Logic: greedy approach
     Source: 
     Complexity: Space=>O(1) Time=>O(n)
*/

class Solution {
public:
   bool canJump(vector<int>& nums) {
    unsigned int maxReach = 0;
    for (unsigned int i = 0; i < nums.size(); i++) {
        if (maxReach < i)  // cannot reach i 
            return false;
        if (maxReach >= nums.size()-1)
            return true;  //early return 
        maxReach = max(maxReach, i+nums[i]);
    }
    return true;
}
};