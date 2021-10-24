/*
     Complexity: Time=>O(n)   , Space=>O(n)
     Link : https://leetcode.com/problems/n-ary-tree-preorder-traversal/
     Logic: 
     Source:
*/
//******recursive******


class Solution {
public:
    void help(Node* root , vector<int> &ans)
    {
        if(root==NULL) return ;
        ans.push_back(root->val);
        for(auto child: root->children )
            help(child , ans);
    }
    vector<int> preorder(Node* root) {
        vector<int> ans;
        help(root , ans);
        return ans;
    }
};

//******iterative******
class Solution {
public:
    vector<int> preorder(Node* root) {
        
        vector<int>ans;
        if(!root)
            return {};
        stack<Node*>s;
        s.push(root);
        while(!s.empty())
        {
            Node*p=s.top();
            s.pop();
            ans.push_back(p->val);
            for(int i=p->children.size()-1;i>=0;i--)
                s.push(p->children[i]);
        }
        return ans;
        
    }
};