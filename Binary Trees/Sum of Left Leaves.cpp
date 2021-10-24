/*
     Complexity: Time=>O()   , Space=>O()
     Link : https://leetcode.com/problems/sum-of-left-leaves/submissions/
     Logic:
     Source:
*/
class Solution {
public:
    int dfs(TreeNode* root , bool flag , int &sum )
    {
        if(root==NULL)
        return 0;
        dfs(root->left , true , sum);
        dfs(root->right , false , sum);
        if(root->left ==NULL and root->right ==NULL and flag==true)
            sum+=root->val;
        
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool flag=false;
        int sum=0;
        dfs(root, flag , sum);
        return sum;
    }
};