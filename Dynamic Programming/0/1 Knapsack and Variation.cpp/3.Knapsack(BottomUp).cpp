#include <bits/stdc++.h>
using namespace std;

int Knapsack(int wt[], int val[], int W, int n)
{
    vector<vector<int>> dp(n , vector<int>(W+1));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=0;
    }
    for(int w=0;w<=W;w++)
    {
        if(wt[0]<=w)
        {
            dp[0][w]=val[0];
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            int profit1 = 0, profit2 = 0;
            if(wt[i]<=j)
            {
                profit1=val[i]+dp[i-1][j-wt[i]];
            }
            profit2 = dp[i-1][j];
            dp[i][j] = max(profit1 , profit2);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n-1][W];
}
int main()
{
    int n;
    cin >> n;          // number of items
    int val[n], wt[n]; // values and wts array
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int W;
    cin >> W; // Knapsack capacity
    cout << Knapsack(wt, val, W, n) << endl;
    return 0;
}