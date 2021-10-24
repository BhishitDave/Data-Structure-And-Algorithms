/*
     Complexity: Time=>O(m+n)   , Space=>O()
     Link : https://leetcode.com/problems/01-matrix/
     Logic: use multi source bfs
     Source: coding minutes
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m =mat.size();
        int n =mat[0].size();
        queue<pair<int, int>> q;
        int dx[4] = {1, -1, 0, 0};
	    int dy[4] = {0, 0, 1, -1};
        vector<vector<int>> ans(m, vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        while(!q.empty())
        {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0 and xx<m and yy>=0 and yy<n)
            {
                if(ans[xx][yy]==INT_MAX)
                {
                    q.push({xx,yy});
                    ans[xx][yy]=ans[x][y]+1;
                }
            }
        }
        }
        return ans;
    }
};