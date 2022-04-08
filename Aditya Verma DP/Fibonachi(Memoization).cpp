#include <bits/stdc++.h>
using namespace std;
int t[1001];
int fib(int n){
    if(n==0 or n==1){
        t[n]=n;
        return n;
    }
    if(t[n-1]!=-1 and t[n-2]!=-1)
    t[n]=t[n-1]+t[n-2];
    else
    t[n]=fib(n-1)+fib(n-2);

    return t[n];
}

int main()
{
    int n;
    cin>>n;
    memset(t,-1,sizeof(t));
    cout<<fib(n);
    return 0; 
}