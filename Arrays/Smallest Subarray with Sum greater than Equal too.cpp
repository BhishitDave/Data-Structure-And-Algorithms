/*
     Complexity: Time=>O(n)   , Space=>O(1)
     Link : 
     Logic: Two pointer approach
     Source: gfg
*/
#include <bits/stdc++.h>
using namespace std;

int findMinOps(int arr[], int n)
{
    int ans=0;
    int i=0,j =n-1;
    while(i<j)
    {
        if(arr[i]==arr[j])
        {
            i++;
            j--;
            ans++;
        }
        else if(arr[i] < arr[j])
        {
            i++;
            arr[i]+=arr[i-1];
            ans++;
        }
        else
        {
            j--;
            arr[j]+=arr[j+1];
            ans++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Count of minimum operations is "
         <<  findMinOps(arr, n) << endl;
    return 0;
}