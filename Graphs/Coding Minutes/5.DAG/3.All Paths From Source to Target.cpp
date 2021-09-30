/*
     Complexity: Time=>O(V+E)   , Space=>O()
     Link : https://leetcode.com/problems/all-paths-from-source-to-target/
     Logic: dfs
     Source:
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    int target;
    void dfs(vector<vector<int>> graph , int node)
    {
        temp.push_back(node);
        if(node==target) res.push_back(temp);
        for(auto i : graph[node])
        {
            dfs(graph ,i);
        }
        temp.pop_back();
            
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size()-1;
        dfs(graph , 0);
        return res;
    }
};