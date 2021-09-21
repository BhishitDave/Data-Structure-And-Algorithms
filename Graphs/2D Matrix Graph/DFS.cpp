#include <bits/stdc++.h>
using namespace std;

char arr[1001][1001]; // for taking input
bool vis[1001][1001]; // for visited array
int dx[]={-1,0,1,0};  // for 4 direction
int dy[]={0,1,0,-1};
int n ,m; //no of vertex and edges

bool isValid(int x , int y)  // checks if it is possible to go to x,y
{
    if(x<1 or x>m or y<1 or y>n)
    return false;
    if(vis[x][y]==true or arr[x][y]=='#')
    return false;

    return true;
}
void dfs(int x , int y)
{
    vis[x][y]=true;
    cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i] , y+dy[i]))
        dfs(x+dx[i] , y+dy[i]);
    }
    // if(isValid(x-1 ,y))
    // dfs(x-1 ,y);
    // if(isValid(x ,y+1))
    // dfs(x ,y+1);
    // if(isValid(x+1 ,y))
    // dfs(x+1 ,y);
    // if(isValid(x ,y-1))
    // dfs(x ,y-1);
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        cin>>arr[i][j];
    }
    int count=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        if(arr[i][j]=='.' and vis[i][j] ==false)
        {
            dfs(i,j);
            count++;
        }
    }
    cout<<count;
    return 0; 
}
