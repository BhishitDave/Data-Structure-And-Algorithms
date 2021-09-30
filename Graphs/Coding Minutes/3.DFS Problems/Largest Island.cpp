/*
     Complexity: Time=>O(n*m)   , Space=>O(n*m)
     Link : https://leetcode.com/problems/max-area-of-island/
     Logic: use dfs or bfs to count
     Source: codencode
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m ,n;
    int dfs(int x , int y , vector<vector<int>>& grid)
    {
        if(x<0 or x>=m or y<0 or y>=n or grid[x][y]==0) return 0;
        grid[x][y]=0;
        return 1+dfs(x+1,y,grid)+dfs(x,y+1,grid)+dfs(x-1,y,grid)+dfs(x,y-1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m= grid.size();
        n = grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    ans=max(dfs(i,j,grid), ans);
                }
            }
        }
        return ans;
    }
};