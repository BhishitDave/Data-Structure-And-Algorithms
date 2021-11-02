/*
     Complexity: Time=>O()   , Space=>O()
     Link : https://leetcode.com/problems/minimum-height-trees/
     Logic: toposort 
     Source:
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    //edge case
    if(n<2)
    {
        return {0};
    }
    vector<int>ans;
    vector<vector<int>>v(n+1);
    int x,y;
    vector<int>deg(n+1);
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(deg[i]==1)
        {
            q.push(i);
        }
    }
    int cnt=n;
    vector<int>visit(n+1);
    while(cnt>2)
    {
        // vector<int>vec;
        int qsize=q.size();
        while(qsize--)
        {
            x=q.front();
            q.pop();
            cnt--;
            visit[x]=1;
            for(auto itr:v[x])
            {
                if(!visit[itr])
                {
                    deg[itr]--;
                    if(deg[itr]==1)
                    {
                        q.push(itr);
                    }
                }
            }
        }
        // for(auto itr:vec)
        // {
        //     q.push(itr);
        // }
    }
    while(q.size())
    {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}
};