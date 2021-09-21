/*
     Complexity: Time=>O()   , Space=>O()
     Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
     Logic:
     Source:
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or root==p or root==q)
            return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(!r)
            return l;
        else if(!l)
            return r;
        else
            return root;
        
    }
};