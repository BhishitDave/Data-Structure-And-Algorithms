//  Given a number, transform it in two numbers p1 and p2 such that sum of p1 and p2 is minimum.
//             Ex - 4523 - 59 ( 24 + 35)

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ll n;
    cin>>n;
    vector<int> v;
    while(n>0)
    {
        v.push_back(n%10);
        n/=10;
    }
    sort(v.begin(),v.end());
   string s1,s2;
    
    for(int i=0;i<v.size();i++)
    {   
        string temp=to_string(v[i]);
        if(i%2==0) s1=s1+temp;
        else s2=s2+temp;
    }
 
    int x=stoi(s1);
    int y=stoi(s2);
    cout<<x+y<<endl;
}