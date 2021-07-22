/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
     Logic: Divide The code in 3 parts left, leaft and reverse right
     Source: code library
*/
class Solution {
public:
    void LeftTree(Node* root,vector <int> &ans)
    {
        if(!root)
        return ;
        if(root->left)
        {
            ans.push_back(root->data);
            LeftTree(root->left,ans);
        }
        else if(root->right)
        {
            ans.push_back(root->data);
            LeftTree(root->right,ans);
        }
    }
    void Leaf(Node* root,vector <int> &ans)
    {
        if(!root)
        return;
        Leaf(root->left,ans);
        if(!root->left and !root->right)
        ans.push_back(root->data);
        Leaf(root->right,ans);
    }
    void RightTree(Node* root,vector <int> &ans)
    {
        if(!root)
        return ;
        if(root->right)
        {
            RightTree(root->right,ans);
            ans.push_back(root->data);
        }
        else if(root->left)
        {
            RightTree(root->left,ans);
            ans.push_back(root->data);
        }
    }
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        ans.push_back(root->data);
        LeftTree(root->left, ans);
        Leaf(root, ans);
        RightTree(root->right, ans);
        return ans;
    }
};