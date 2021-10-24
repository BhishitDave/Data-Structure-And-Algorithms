#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int> v(n+1 , 0);
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        v[x]++;
    }
    cout<<n-1<<" ";
    for(int i=2;i<=n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0; 
}