#include <bits/stdc++.h>
using namespace std;

char arr[1001][1001];
bool vis[1001][1001];
int n ,m;
bool isValid(int x , int y)
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
    if(isValid(x-1 ,y))
    dfs(x-1 ,y);
    if(isValid(x ,y+1))
    dfs(x ,y+1);
    if(isValid(x+1 ,y))
    dfs(x+1 ,y);
    if(isValid(x ,y-1))
    dfs(x ,y-1);
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
