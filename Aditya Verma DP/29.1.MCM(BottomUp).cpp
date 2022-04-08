#include <bits/stdc++.h>
using namespace std;
//!!O(n3) complexity
int Solve(int arr[],int n)
{
    int j,minimum,q;
    int dp[n][n]={0};
    int s[n][n]={0};
    for (int d = 1; d < n-1; d++)
    {
        for(int i=1;i<=n-d;i++)
        {
            j=i+d;
            minimum=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                q=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(q<minimum)
                {
                    minimum=q;
                    s[i][j]=k;
                }
            }
            dp[i][j]=minimum;
        }
    }
    return dp[1][n-1];
    
}

signed main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << Solve(arr,n) << endl;
    return 0;
}