/*
     Complexity: Time=>O(v3)   , Space=>O(v2)
     Link : https://atcoder.jp/contests/abc143/tasks/abc143_e
     Logic: use floyd wrashall twice 1st on distance and then on fuel matrix;
     Source:
*/

#include<bits/stdc++.h>
using namespace std;
#define inf 1e9

vector<int> travelByCar(int n,int l, vector<vector<int>>edges ,vector<vector<int>> queries)
{
    vector<vector<int>>dis(n+1,vector<int>(n+1,inf)),fuel(n+1,vector<int>(n+1,inf));
    int x,y,val;
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1],val=edges[i][2];
        x--;
        y--;
        dis[x][x]=0;
        dis[y][y]=0;
        fuel[x][x]=0;
        fuel[y][y]=0;
        dis[x][y]=val;
        dis[y][x]=val;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(dis[j][k]>dis[j][i]+dis[i][k])
                {
                    dis[j][k]=dis[j][i]+dis[i][k];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(dis[i][j]<=l)
            {
                fuel[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(fuel[j][k]>fuel[j][i]+fuel[i][k])
                {
                    fuel[j][k]=fuel[j][i]+fuel[i][k];
                }
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<queries.size();i++)
    {
        x=queries[i][0],y=queries[i][1];
        x--;
        y--;
        if(fuel[x][y]==inf)
        {
            ans.push_back(-1);
        }
        else{
            ans.push_back(fuel[x][y]-1);
        }
    }
    return ans;
}

int main()
{
    int n, m ,l;
    cin>>n>>m>>l;
    vector<vector<int>> edges(m , vector<int>(3,0));
    for(int i=0;i<m;i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        edges[i][0]=x;
        edges[i][1]=y;
        edges[i][2]=z;
    }
    int q;
    cin>>q;
    vector<vector<int>> query(q , vector<int>(2,0));
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        query[i][0]=x;
        query[i][1]=y;
    }
    auto x =travelByCar(n, l , edges , query);
    for(auto i: x)
    {
        cout<<i<<endl;
    }
    return 0;
}