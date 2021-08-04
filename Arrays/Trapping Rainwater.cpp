/*
     Link : https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
     Logic: use 2 pointer to keep track of max on both side
     Source: tuf
*/
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int start=0;
        int end=n-1;
        int lmax=0;
        int rmax=0;
        int res=0;
        while(start<=end)
        {
            if(arr[start]<=arr[end])
            {
                if(arr[start]>=lmax)
                lmax=arr[start];
                else
                res+=lmax-arr[start];
                start++;
            }
            else
            {
                if(arr[end]>=rmax)
                rmax=arr[end];
                else
                res+=rmax-arr[end];
                end--;
            }
        }
        return res;
    }
};