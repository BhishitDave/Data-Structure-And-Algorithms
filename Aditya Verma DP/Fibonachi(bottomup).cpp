#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    int t[1001];
    t[0]=0;
    t[1]=1;
    for(int i=2;i<=n;i++){
        t[i]=t[i-1]+t[i-2];
    }
    return t[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
    return 0; 
}