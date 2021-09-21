/*
     Complexity: Time=>O(n)   , Space=>O(n)
     Link : https://leetcode.com/problems/binary-tree-level-order-traversal/
     Logic: 
     Source: tuf
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>  ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int qsize=q.size();
            vector<int> level;
            while(qsize)
            {
                TreeNode *temp = q.front();
                q.pop(); 
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                qsize--;
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};