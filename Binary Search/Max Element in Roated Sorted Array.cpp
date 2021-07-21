/*
     Name: Bhishit Dave
     Link : NA
     Logic:Binary Search
     Source:Self
*/

#include <bits/stdc++.h>
using namespace std;
// [5, 7, 11, 1, 3] would return 11.  N
// [7, 9, 15, 1, 3] would return 15.
int binarysearch(int a[], int start, int end)
{
    while(start<end)
    {
        int mid=(start+end)/2;
        if(mid!=0 and a[mid]>a[mid-1] and a[mid]>=a[mid+1])
            return a[mid];
        else if(a[mid]>a[mid+1])
            return a[mid];
        if(a[mid]>=a[start])
            start=mid+1;
        else
            end=mid-1;
    }
    return a[start];
}
int main()
{
    int arr[] = {7,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans= binarysearch(arr,0,n-1);
    cout<<ans;
    return 0; 
}