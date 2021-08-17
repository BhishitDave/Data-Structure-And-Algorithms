/*
     Selection Sort is not stable;
     Complexity: Time=>O(n2)   , Space=>O(1)
     Link : https://practice.geeksforgeeks.org/problems/selection-sort/1
     Logic: 
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int min_index;
    for(int i=0;i<n-1;i++)
    {
        min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
            min_index=j;
            
        }
        swap(arr[min_index], arr[i]);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}