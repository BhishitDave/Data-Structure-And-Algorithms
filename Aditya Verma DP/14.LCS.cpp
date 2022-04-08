#include <bits/stdc++.h>
using namespace std;
int LCS(string X, string Y, int n, int m){
    if(m==0 or n==0){
        return 0;
    }
    if(X[n-1]==Y[m-1]){
        return 1+LCS(X,Y,n-1,m-1);
    }
    else{
        return max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
    }
}

int main()
{
    string x,y;
    cin>>x>>y;
    int n=x.size(),m=y.size();
    cout<<LCS(x,y,n,m)<<endl;
    return 0; 
}