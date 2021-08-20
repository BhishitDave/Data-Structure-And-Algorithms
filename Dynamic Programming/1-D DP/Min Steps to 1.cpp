#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
    int dp[n+1];
    dp[1]=dp[0]=0;
    int d1,d2,d3;
    for(int i=2;i<=n;i++)
    {
        d1=dp[i-1]+1;
        if(n%3==0)
        d2=dp[i/3]+1;
        else
        d2=INT_MAX;
        if(n%2==0)
        d3=dp[i/2]+1;
        else
        d3=INT_MAX;
        dp[i]=min(d1,min(d2,d3));
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<fun(n);
    return 0; 
}