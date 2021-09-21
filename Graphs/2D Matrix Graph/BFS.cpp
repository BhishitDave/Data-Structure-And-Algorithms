#include <bits/stdc++.h>
using namespace std;

char arr[1001][1001]; // for taking input
bool vis[1001][1001]; // for visited array
int dist[1001][1001];
int dx[]={-1,0,1,0};  // for 4 direction
int dy[]={0,1,0,-1};
int n ,m; //no of vertex and edges

bool isValid(int x , int y)  // checks if it is possible to go to x,y
{
    if(x<1 or x>m or y<1 or y>n)
    return false;
    if(vis[x][y]==true)
    return false;

    return true;
}
void bfs(int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    dist[x][y]=0;
    vis[x][y]=1;

    while (!q.empty())
    {
        int xtemp=q.front().first;
        int ytemp=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(isValid(xtemp+dx[i] ,ytemp +dy[i]))
            {
                int newX=xtemp+dx[i];
                int newY=ytemp +dy[i];

                dist[newX][newY] =dist[xtemp][ytemp]+1;
                vis[newX][newY] =1;
                q.push({newX,newY});
            }
        }
    }
    
    
}