/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#
     Logic: use key pair logic
     Source:
     Complexity: 
*/

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    int hasArrayTwoCandidates(int arr[],int start, int n, int x) {
	    // code here
	    int count=0;
	    while(start<n)
	    {
	        if(arr[start]+arr[n]==x)
	        {
	            count++;
	            start++;
	            n--;
	        }
	        else if(arr[start]+arr[n]>x)
	        n--;
	        else
	        start++;
	    }
	    return count;
	}
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        int count=0;
        for(int i=0;i<n-2;i++)
        {
            int x=hasArrayTwoCandidates(A,i+1,n-1,X-A[i]);
            count+=x;
        }
        return count;
    }

};