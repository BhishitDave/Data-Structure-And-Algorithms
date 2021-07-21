/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/reach-a-given-score1418/1/
     Logic: 
     Source: gfg
*/

ll count(ll n) 
{
    //code here
    if(n==0)
    return 1;
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=3;i<=n;i++)
    dp[i]+=dp[i-3];
    for(int i=5;i<=n;i++)
    dp[i]+=dp[i-5];
    for(int i=10;i<=n;i++)
    dp[i]+=dp[i-10];
    
    return dp[n];
}