/*
     Complexity: Time=>O(n.size)   , Space=>O(n)
     Link :  https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#
     Logic: (to understand properly dry run code on few testcases)
     Source: cb
*/
#include <bits/stdc++.h>
using namespace std;

long long countCoins(long long coins[] , long long size , long long n)
{
    long long dp[n+1]={0};
    for(long long i=1;i<=n;i++) // loop for value 1 to n
    {
        dp[i]=INT_MAX; 
        for(long long j=0;j<size;j++)  // loop to check for every denomination of coins
        {
            if(i>=coins[j]) // if the value is less than coins value
            {
                long long subprob=dp[i-coins[j]];
                dp[i]=min(dp[i], subprob+1);
            }
        }
        
    }
    if(dp[n]!=INT_MAX) // checking if the denomonation can be changed or not
    return dp[n];
    else return -1;
}

int main()
{
    long long a[]={9, 2 ,11, 5, 14, 17, 8 ,18};
    long long n;
    cin>>n;
    cout<<countCoins(a,8, n);
    return 0; 
}