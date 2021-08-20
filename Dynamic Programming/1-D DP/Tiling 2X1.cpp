/*
     Complexity: Time=>O(n)   , Space=>O(n)
     Link : https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1
     Logic: 
     Source: pepcoding
*/
long long numberOfWays(long long N)
{
    //code here
    long long dp[N + 1] = {0};
    int m = 1000000007;
    dp[1] = 1;
    dp[2] = 2;
    for (long long i = 3; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % m;
    }
    return dp[N];
}