class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    if(arr[0]>arr[1])
	    return arr[0];
	    if(arr[n-1]>arr[n-2])
	    return arr[n-1];
	    int l=1;
	    int r =n-2;
	    while(l<=r)
	    {
	        int mid = (l+r)/2;
	        if(arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1])
	        return arr[mid];
	        else if(arr[mid] < arr[mid+1] and arr[mid] > arr[mid-1])
	        l=mid+1;
	        else
	        r=mid-1;
	    }
	    return arr[r];
	}
};
