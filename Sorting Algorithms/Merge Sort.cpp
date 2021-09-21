#include <bits/stdc++.h>
using namespace std;
void PrintArray(int arr[],int size);

void Merge(int A[],int left,int mid,int right)
{
        int i=left,j=mid+1,k=left;
        int B[100];

        while(i<=mid && j<=right)
        {
        if(A[i]<A[j]) 
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
        }
        for(;i<=mid;i++)
            B[k++]=A[i];
        for(;j<=right;j++)
            B[k++]=A[j];

        for(i=left;i<=right;i++)
            A[i]=B[i];
}

void MergeSort(int arr[],int left, int right)
{
    if(left<right)
    {
        int m=(left+right)/2;

        MergeSort(arr,left,m);
        MergeSort(arr,m+1,right);
        
        Merge(arr,left,m,right);
    }
}

int main()
{

    int n;
    cout<<"Number of elements :"<<"\n";
    cin>>n;
    int arr[n];
    for(int i=0; i< n; i++){
        cout<<"Enter Element "<<i<<"= ";
        cin>>arr[i];
        cout<<endl;
    }
    printf("Given array is \n");
    PrintArray(arr,n);
    MergeSort(arr,0,n-1);
    printf("\nSorted array is \n");
    PrintArray(arr,n);
    return 0;
}




void PrintArray(int arr[],int size)
{
    cout<<"Your array is: ";
    for(int i =0;i<size;i++)
    {
        
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}