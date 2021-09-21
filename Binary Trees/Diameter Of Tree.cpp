/*
     Complexity: Time=>O()   , Space=>O()
     Link : https://leetcode.com/problems/diameter-of-binary-tree/
     Logic: similar to height
     Source:
*/
class Solution {
public:
    int height(TreeNode* root , int &diameter)
    {
        if(root==NULL)
            return 0;
        int x = height(root->left , diameter);
        int y= height (root->right , diameter);
        diameter = max(diameter , x+y);
        return max(x,y)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;
            height(root , diameter);
        return diameter; 
    }
};