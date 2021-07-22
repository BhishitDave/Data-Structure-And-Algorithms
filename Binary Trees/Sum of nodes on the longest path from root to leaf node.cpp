/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
     Logic:modify height function
     Source:gfg
*/

class Solution
{
public:
    void solve(Node *root,int &maxsum,int sum,  int &maxheight , int height )
    {
        if(!root)
        {
            if(maxheight<height)
            {
                maxheight=height;
                
                maxsum=sum;
            }
            else if(maxheight==height and maxsum<sum)
            {
                maxsum=sum;
            }
            return;
        }
        solve(root->left,maxsum,sum+root->data,maxheight,height+1);
        solve(root->right,maxsum,sum+root->data,maxheight,height+1);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum=0;
        int maxsum=INT_MIN;
        int height=0;
        int maxheight=0;
        solve(root,maxsum,sum,maxheight,height);
        return maxsum;
    }
};
