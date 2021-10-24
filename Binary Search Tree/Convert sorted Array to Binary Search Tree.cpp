/*
     Complexity: Time=>O()   , Space=>O()
     Link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/
     Logic: 
     Source:
*/

class Solution {
public:
    TreeNode* help(vector<int>& nums , int l , int h)
    {
        if(l<=h)
        {
            int mid = l + (h-l)/2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = help(nums , l , mid-1);
            root->right = help(nums , mid+1 , h );
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return NULL;
        return help(nums , 0 , n-1);
        
    }
};