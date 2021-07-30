/*
     Name: Bhishit Dave
     Link : https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/min-jumps-re-official/ojquestion
     Logic: use bfs to print the path
     Source: pepcoding
     Complexity: Time=>O(n2) , Space=>O(n)
*/

#include <bits/stdc++.h>
using namespace std;
class Pair{
    public:
    int i; // index
    int s; // step a[index]
    int j; // no of jumps dp[index]
    string psf; // path to print

    Pair(int i ,int s , int j , string psf)
    {
        this->i=i;
        this->s=s;
        this->j=j;
        this->psf=psf;
    }
};

void solve(int a[] , int n)
{
    int dp[n];
    memset(dp,-1,sizeof dp);
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        int steps =a[i];
        int minimum = INT_MAX;
        for(int j=1; j<=steps and i+j<n ;j++)
        {
            if(dp[i+j]!=-1 and minimum >  dp[i+j])
            {
                minimum=dp[i+j];
            }
            if(minimum != INT_MAX)
            {
                dp[i]=minimum+1;
            }
        }  
    }
    cout<<dp[0]<<"\n";
    deque<Pair> q;
    Pair p(0 ,a[0] , dp[0] , "0");
    q.emplace_back(p);
    while(!q.empty())
    {
        Pair temp = q.front();
        q.pop_front();
        if(temp.j==0)
        {
           cout<<temp.psf<<"."<<"\n" ;
        }
        for(int j=1;j<=temp.s and temp.i +j < n;j++)
        {
            int curr_index=temp.i+j;
            if(dp[curr_index]!=-1 and dp[curr_index]==temp.j-1)
            {
                Pair p(curr_index ,a[curr_index] , dp[curr_index] , temp.psf+"->"+to_string(curr_index));
                q.emplace_back(p);
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    solve(a,n);
    return 0; 
}