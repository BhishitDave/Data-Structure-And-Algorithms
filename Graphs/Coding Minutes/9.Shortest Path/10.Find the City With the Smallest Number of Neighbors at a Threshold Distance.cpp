/*
     Complexity: Time=>O(n3)   , Space=>O(n2)
     Link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
     Logic: use floyd warsall
     Source:
*/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int INF=100000;
        vector<vector<int>> graph(n,vector<int>(n,INF));
        for(auto i : edges)
        {
            graph[i[0]][i[1]] = i[2];
            graph[i[1]][i[0]] = i[2];
        }
        for(int i=0;i<n;i++)
            graph[i][i]=0;
        vector<vector<int>> dist(graph);
        for (int k = 0; k < n; k++)
        {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=distanceThreshold)
                    ans[i]++;
            }
        }
        int minIdx=0;
        int minimum=ans[0];
        for(int i=1;i<n;i++)
        {
            if(ans[i]<=minimum)
            {
                minimum=ans[i];
                minIdx=i;
            }
        }
        return minIdx;
    }
};