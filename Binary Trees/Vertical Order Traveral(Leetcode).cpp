/*
     Complexity: Time=> O(N*logN*logN*logN)  , Space=>O()
     Link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
     Logic: 
     Source:Vertical Order Traveral(Leetcode) tuf
*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // storing [vertical level][horizontal level]=>{multiset}
        queue<pair<TreeNode*, pair<int, int>>> todo; //pair{vertical , horizontal}
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                for(auto x : q.second)
                    col.push_back(x);
                // col.insert(col.end(), q.second.begin(), q.second.end());
                
            }
            ans.push_back(col);
        }
        return ans;
    }
};
