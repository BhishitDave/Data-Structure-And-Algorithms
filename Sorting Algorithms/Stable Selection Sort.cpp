/*
     Selection Sort is not stable by nature;
     Complexity: Time=>O(n2)   , Space=>O(1)
     Link : https://www.geeksforgeeks.org/stable-selection-sort/
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
        int key =arr[min_index];
        while(min_index>i)
        {
            arr[min_index] =arr[min_index-1];
            min_index--;
        }
        arr[i]=key;
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