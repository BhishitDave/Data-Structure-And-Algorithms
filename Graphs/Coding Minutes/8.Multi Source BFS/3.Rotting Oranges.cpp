/*
     Complexity: Time=>O(mn)   , Space=>O()
     Link : https://leetcode.com/problems/rotting-oranges/
     Logic: multi source bfs
     Source:
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //directions
        int dx[4]={1,-1,0,0};
        int dy[4]={0 ,0 ,1, -1};
        
        if(grid.empty())
            return 0;
        
        int count=0 , days=0 , total=0;
        queue<pair<int , int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]!=0)
                {
                    total++;  // to check in end if any tomato is left 
                }
            }
        }
        while(!q.empty())
        {
            int k=q.size();
            count+=k;
            while(k--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int xx=x+dx[i];
                    int yy=y+dy[i];
                    if(xx>=0 and xx<m and yy>=0 and yy<n and grid[xx][yy]==1)
                    {
                        grid[xx][yy]=2;
                        q.push({xx,yy});
                    }
                }
            }
            if(!q.empty()) days++;
        }
        return total==count?days:-1;

    }
};