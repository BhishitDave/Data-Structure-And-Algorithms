/*
     Complexity: Time=>O(N²)  , Space=>O(n2)
     Link : https://leetcode.com/discuss/interview-question/1282577/selling-wine-dp-easy-c
     Logic: 
     Source:
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000] ={0};
int wine(int p[] , int l , int n , int y)
{
    if(l>n)
    return 0;

    if(dp[l][n]!=0)
    return dp[l][n];
    int sum;
    sum=max(p[l]*y +wine(p,l+1 ,n ,y+1) ,p[n]*y +wine(p,l ,n-1 ,y+1));
    return dp[l][n]=sum;

}
int main()
{
    int p[]={ 2, 4, 6, 2, 5};
    int n=5;
    cout<<wine(p,0,n-1 ,1);
    return 0; 
}