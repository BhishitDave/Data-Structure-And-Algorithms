/*
     Complexity: Time=>O(V+E)   , Space=>O()
     Link : https://leetcode.com/problems/course-schedule/
     Logic:
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        bool dfs(int node, vector<bool> &visited, vector<bool> &instack ,vector<vector<int>> l)
    {
        //arrive at node
        visited[node]=true;
        instack[node]=true;

        //do some work at node,return true if backedge is found here itself
        for(auto nbrs: l[node])
        {
            if(instack[nbrs]==true)
            return true;
            else if(visited[nbrs]==false)
            {
                bool nbrFoundCycle = dfs(nbrs , visited , instack ,l);
                if(nbrFoundCycle)
                return true;
            }
        }
        //going back
        instack[node]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> instack(numCourses, false);
        vector<vector<int>> l(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int bi = prerequisites[i][1];
            int ai = prerequisites[i][0];
            l[bi].push_back(ai);
        }
        for (int i = 0; i < numCourses; i++)
        {
            int source = i;
            if (visited[source] == false)
            {
                if (dfs(source, visited, instack ,l))
                    return false;
            }
        }
        return true;
    }
};