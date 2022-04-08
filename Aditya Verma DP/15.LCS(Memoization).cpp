#include <bits/stdc++.h>
using namespace std;
int t[100][100];
int LCS(string X, string Y, int n, int m){
    //base case
    if(m==0 or n==0){
        t[n][m]=0;
    }
    //if lcs is called for current n,m
    if(t[n][m]!=-1){
        return t[n][m];
    }
    //if the last char is same
    if(X[n-1]==Y[m-1]){
        t[n][m]=1+LCS(X,Y,n-1,m-1);
    }
    else{// if the last char is not same 
        t[n][m]=max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
    }
    return t[n][m];
}

int main()
{
    string x,y;
    cin>>x>>y;
    int n=x.size(),m=y.size();
    memset(t,-1,sizeof t);
    cout<<LCS(x,y,n,m)<<endl;
    return 0; 
}