/*
     Complexity: Bubble Sort is an easy-to-implement, stable sorting algorithm with a time complexity of O(n²) in the average and worst cases – and O(n) in the best case.
     Link : https://practice.geeksforgeeks.org/problems/bubble-sort/1
     Logic: 
     Source: 
*/
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[] , int n)
{
    bool flag; // to check if the array is sorted or not
    for(int i=0;i<n-1;i++)
    {
        flag=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
        if(flag==false)
        break;
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}