/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
     Logic: use unordered map to store the tree in string format
     Source: code library
*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<string,int>mp;
    string solve(Node* root)
    {
        if(root==NULL) return "$";
        string s=" ";
        if(!root->left and !root->right)
        {
            s=to_string(root->data);
            return s;
        }
        s=s+to_string(root->data);
        s=s+solve(root->left);
        s=s+solve(root->right);
        mp[s]++;
        return s;
    }
    int dupSub(Node *root) {
         // code here
        mp.clear();
        solve(root);
        for(auto x:mp)
        {
            if(x.second>=2)
            return 1;
        }
        return 0;
    }
};