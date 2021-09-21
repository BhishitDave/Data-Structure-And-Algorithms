/*
     Complexity: Time=>O(n)   ,A Space=>O(n)
     Link : https://leetcode.com/problems/same-tree/
     Logic:
     Source: tuf
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        else if(p == nullptr)
            return false;
        else if(q == nullptr)
            return false;
        
        if(p->val != q->val)
            return false;
        
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};