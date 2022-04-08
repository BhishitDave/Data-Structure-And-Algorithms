/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int solve(BinaryTreeNode<int>* root , map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mp)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int ans =0;
    map<BinaryTreeNode<int>*, int> vis;
    while(!q.empty())
    {
        int flag=0;
        int qsize= q.size();
        while(qsize--)
        {
            auto temp =q.front();
            q.pop();
            if(temp->left and vis[temp->left] == 0)
            {
                flag=1;
                q.push(temp->left);
                vis[temp->left] =1;
            }
            if(temp->right and vis[temp->right] == 0)
            {
                flag=1;
                q.push(temp->right);
                vis[temp->right] =1;
            }
            if(mp[temp] and vis[mp[temp]]==0)
             {
                flag=1;
                q.push(mp[temp]);
                vis[mp[temp]] =1;
            }  
        }
        if(flag) ans++;
    }
    return ans;
    
}
BinaryTreeNode<int>* bfs(BinaryTreeNode<int>* root , int start , map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mp)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>*  res;
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        if(temp->data == start)
            res= temp;
        if(temp->left)
        {
            mp[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            mp[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return res;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mp; // child , parent;
    BinaryTreeNode<int>* res =  bfs(root,start, mp);
    int ans = solve(res , mp );
    return ans;
    
}
