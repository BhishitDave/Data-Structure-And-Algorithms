/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/levelorder-in-bst/1/
     Logic: 
     Source: gfg
*/
//!!Not a good aproach beacuse worst time complexity can be O(n2) in skwed tree
int height(Node *root)
{
    if(root==NULL)
    return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    return max(h1,h2)+1;
}
void solve(struct Node* root,vector<int> &ans,int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        ans.push_back(root->data);
    else if (level > 1)
    {
        solve(root->left,ans, level-1);
        solve(root->right,ans, level-1);
    }
}
vector<int> levelOrder(Node *root) 
{ 
    //Your code here
    int h=height(root);
    vector <int> ans;
    for(int i=1;i<=h;i++)
    solve(root,ans,i);
	return ans;
} 