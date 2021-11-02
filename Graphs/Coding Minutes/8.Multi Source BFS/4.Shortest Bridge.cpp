/*
     Complexity: Time=>O()   , Space=>O()
     Link : https://www.udemy.com/course/learn-kubernetes/
     Logic: flood fill(dfs) + count distance btw every 1s or dfs+bfs + (MultiSOurce)bfs
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& A, int i, int j, vector <pair<int, int>> &r)
    {
        if(i < 0 || j < 0 || i >= A.size() || j >= A[i].size() || A[i][j]==0)
            return;
        A[i][j] = 0;
        r.push_back(make_pair(i,j));
        dfs(A, i+1, j, r);
        dfs(A, i-1, j, r);
        dfs(A, i, j-1, r);
        dfs(A, i, j+1, r);
        return;
    }
    int shortestBridge(vector<vector<int>>& A) {
        int count = 0;
        vector <pair<int, int>> x;
        vector <pair<int, int>> y;
        for(int i=0; i<A.size(); i++)
        {
            for(int j=0; j<A[i].size(); j++)
            {
                if(A[i][j] == 1)
                {
                    count++;
                    if(count == 1)
                    {
                        dfs(A, i, j, x);   
                    }
                    if(count == 2)
                    {
                        dfs(A, i, j, y);   
                    }   
                }
            }
        }
        int min_dist = INT_MAX;
        for(int i=0; i<x.size(); i++)
        {
            for(int j=0; j<y.size(); j++)
            {
                int dist = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second) - 1;
                if(dist < min_dist)
                    min_dist = dist;
            }
        }
        return min_dist;
    }
};

// ***************MULTI SOURCE BFS SOLUTION************
class Solution1{
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<pair<int, int>> direction = {
		{-1, 0}, {0, -1}, {0, 1}, {1, 0}
	};
        vector<vector<int>> visited(row, vector<int>(col,0));
        queue<pair<int, int>> Q1 , Q2;
        //finding 1st node island
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    visited[i][j]=1;
                    Q1.push({i,j});
                    i=row;j=col;
                }
            }
        }
        //pushing 1st island to q2
        while(!Q1.empty())
        {
            auto curr =Q1.front();
            Q1.pop();
            Q2.push(curr);
            for(int i=0;i<4;i++)
            {
                int x=curr.first +direction[i].first;
                int y=curr.second +direction[i].second;
                if(x>=0 and x<row and y>=0 and y<col and grid[x][y]==1 and visited[x][y]==0)
                {
                    visited[x][y]=1;
                    Q1.push({x,y});
                }
            }
        }
        int qsize=0, nodelevel=-1;
        while(!Q2.empty())
        {
            qsize=Q2.size();
            nodelevel++;
            while(qsize--)
            {
                auto curr=Q2.front();
                Q2.pop();
                for(int i=0;i<4;i++)
                {
                int x=curr.first +direction[i].first;
                int y=curr.second +direction[i].second;
                if(x>=0 and x<row and y>=0 and y<col and visited[x][y]==0)
                {
                    if(grid[x][y])
                        return nodelevel;
                    visited[x][y]=1;
                    Q2.push({x,y});
                }
                }
            }
        }
        return -1;
    }
};