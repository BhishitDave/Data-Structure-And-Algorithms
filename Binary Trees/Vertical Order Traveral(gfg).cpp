/*
     Complexity: Time=>O()   , Space=>O()
     Link : https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
     Logic:
     Source:
*/
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        int mindist=0,maxdist=0;
        if(root==NULL)
        return ans;
        unordered_map<int,vector<int>> mp;
        queue<pair<Node*, int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            Node *temp=q.front().first;
            int distance=q.front().second;
            q.pop();
            maxdist=max(maxdist,distance);
            mindist=min(mindist,distance);
            mp[distance].emplace_back(temp->data);
            if(temp->left)
            {
                q.push({temp->left,distance-1});
            }
            if(temp->right)
            {
                q.push({temp->right,distance+1});
            }
        }
        while(mindist<=maxdist)
        {
            if(mp.find(mindist)!=mp.end())
            {
                for(auto i: mp[mindist])
                    ans.push_back(i);
            }
            mindist++;
        }
        return ans;
    }
};