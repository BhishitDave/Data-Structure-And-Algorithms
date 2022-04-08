#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[] , int l , int r , int x)
{
    if(r>=l)
    {
        int mid = l + (r-l)/2;
        if(arr[mid] == x)
        return mid;
        if(arr[mid] > x)
        {
            return binarysearch(arr, l , mid-1 , x);
        }
        else
        return binarysearch(arr , mid+1  , r , x);
    }
    return -1;
}

int infiniteArray(int arr[] , int key)
{
    int l=0 , h=1;
    int val = arr[0];

    while(val<key)
    {
        l=h;
        h=h*2;
        val =arr[h];
    }
    return binarysearch(arr , l , h , key);
}
int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
                               140, 160, 170};
    int ans = infiniteArray(arr, 10);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}
