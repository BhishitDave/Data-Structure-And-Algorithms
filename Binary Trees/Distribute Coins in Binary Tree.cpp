/*
     Complexity: Time=>O(n)   , Space=>O(h)
     Link : https://leetcode.com/problems/distribute-coins-in-binary-tree/
     Logic:
     Source:leetcode
*/
class Solution {
public:
    int dfs(TreeNode* root , int &moves)
    {
        if(!root) return 0;
        int left=dfs(root->left , moves);
        int right=dfs(root->right , moves);
        moves+=abs(left)+abs(right);
        return root->val+left+right-1;
    }
    int distributeCoins(TreeNode* root) {
        if(root==NULL)
            return 0;
        int moves=0;
        dfs(root , moves);
        return moves;
    }

};

  // int distributeCoins(TreeNode* r, TreeNode* p = nullptr) {
  // if (r == nullptr) return 0;
  // int res = distributeCoins(r->left, r) + distributeCoins(r->right, r);
  // if (p != nullptr) p->val += r->val - 1;
  // return res + abs(r->val - 1);}