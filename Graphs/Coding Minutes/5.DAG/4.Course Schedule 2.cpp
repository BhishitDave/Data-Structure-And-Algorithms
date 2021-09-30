/*
     Complexity: Time=>O(V+E)   , Space=>O()
     Link : https://leetcode.com/problems/course-schedule-ii/submissions/
     Logic: topo sort + cycle detection in dfs
     Source:
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> l(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            l[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto nbr : l[i])
            {
                indegree[nbr]++;
            }
        }
        //bfs
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            int node =q.front();
            // cout<<node<<" ";
            ans.push_back(node);
            q.pop();
            cnt++;
            for( auto nbr : l[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]<=0)
                {
                    q.push(nbr);
                }
            }
        }
        if(cnt ==numCourses) return ans;
        ans.clear();
        return ans;
        
    }
};