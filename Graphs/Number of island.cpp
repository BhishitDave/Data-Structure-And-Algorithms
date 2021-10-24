/*
     Complexity: Time=>O(m*n)   , Space=>O()
     Link : https://leetcode.com/problems/number-of-islands/
     Logic: count no of compnents in 2d matrix
     Source:
*/

//!dfs
class Solution {
public:
    
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j] == '1') {
            grid[i][j] = 0;
            dfs(grid, i-1, j, m, n);
            dfs(grid, i+1, j, m, n);
            dfs(grid, i, j-1, m, n);
            dfs(grid, i, j+1, m, n);
        }
        else
            return;
            
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0)
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        
        return ans;
    }
};

//! bfs
class Solution {
public:  
    
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0)
            return 0;
        
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    q.emplace(make_pair(i,j));
                    
                    while(!q.empty()) {
                        auto pos = q.front();
                        q.pop();
                        int u = pos.first;
                        int v = pos.second;
                        
                        if(grid[u][v] == '1') {
                            grid[u][v] = '0';
                            for(auto dir : dirs) { 
                                int a = u + dir[0];
                                int b = v + dir[1];
                                if(a>=0 && a<m && b>=0 && b<n)
                                    q.emplace(make_pair(a, b));
                            }
                        }
                            
                    }
                }
            }
        }
        
        return ans;
    }
};