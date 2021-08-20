/*
     Complexity: Time=>O(2ⁿ)   , Space=>O(n2)
     Link : https://leetcode.com/discuss/interview-question/1282577/selling-wine-dp-easy-c
     Logic: 
     Source:
*/

#include <bits/stdc++.h>
using namespace std;
int wine(int p[] , int l , int n , int y)
{
    if(l>n)
    return 0;
    int sum=0;
    sum+=max(p[l]*y +wine(p,l+1 ,n ,y+1) ,p[n]*y +wine(p,l ,n-1 ,y+1));
    return sum;

}
int main()
{
    int p[]={ 2, 4, 6, 2, 5};
    int n=5;
    cout<<wine(p,0,n-1 ,1);
    return 0; 
}