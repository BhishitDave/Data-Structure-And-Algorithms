/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1/#
     Logic: simililar to n friends problem
     Source: -
*/

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        const unsigned int M = 1000000007;
        long long dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(long i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]%M +dp[i-2]%M;
        }
        return dp[n]%M;
    }
};
