/*
     Complexity: Time=>O(n)   , Space=>O(n)
     Link : https://practice.geeksforgeeks.org/problems/children-sum-parent/1#
     Logic:
     Source:
*/
class Solution
{
public:
    //Function to check whether all nodes of a tree have the value
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if (root == NULL)
            return 1;
        if (root->left == NULL and root->right == NULL)
        {
            return true;
        }
        int sum = 0;
        if (root->right)
        {
            sum += root->right->data;
        }
        if (root->left)
        {
            sum += root->left->data;
        }
        return (sum == root->data and isSumProperty(root->right) and isSumProperty(root->left));
    }
};