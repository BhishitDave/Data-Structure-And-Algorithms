/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
     Logic: Inorder
     Source: code library
*/
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void solve(Node* root, Node* &head, Node* &prev)
    {
        if(root==NULL)
        return;
        solve(root->left,head,prev);
        if(prev==NULL)
        {
            head=root;
            prev=root;
        }
        else
        {
            prev->right=root;
            root->left=prev;
            prev=root;
        }
        solve(root->right,head,prev);
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        Node *head =NULL;
        Node *prev=NULL;
        solve(root,head,prev);
        return head;
    }
};