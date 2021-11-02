#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n][m], dist[n][m];
    pair<int, int> nearest[n][m]; // for storing neighbor
    queue<pair<int, int>> q;

    int dx[4]={1, -1 ,0 , 0};
    int dy[4]={0 , 0 ,1, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            dist[i][j] = INT_MAX;
            if(a[i][j])
            {
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    //bfs
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0 and xx<n and yy>=0 and yy<m)
            {
                if(dist[xx][yy]==INT_MAX)
                {
                    q.push({xx,yy});
                    dist[xx][yy]=dist[x][y]+1;
                }
            }
        }
    }

    //output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// 3 4
// 0 0 0 1
// 0 0 1 1
// 0 1 1 0