
/*
     Name: Bhishit Dave
     Link : https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/
     Logic: 2 pointer
     Source: gfg
*/
#include <iostream>
using namespace std;
void RearrangePosNeg(int arr[], int n)
{
    int i=0 ,j=n-1;
    while(i<j)
    {
        if(arr[i]<0)
            i++;
        if(arr[i]>=0)
        {
            swap(arr[i],arr[j]);
            j--;
        }
    }
}
int main()
{
    int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6  };
    int n = sizeof(arr) / sizeof(arr[0]);
    RearrangePosNeg(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
 