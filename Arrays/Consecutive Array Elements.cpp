/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/consecutive-array-elements2711/1
     Logic: use ap logic
     Source:
*/
class Solution{
	
	
	public:
	bool areConsecutives(long long arr[], int n) 
	{ 
	    // Your code goes here
	    long long sum=0;
	    long long ap_sum;
	    long long mini=INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        mini=min(mini,arr[i]);
	    }
	    
	    ap_sum=(n)*((2*mini)+(n-1)) /2;
	    return ap_sum==sum;
	}
		 

};