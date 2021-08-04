/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/key-pair5616/1#
     Logic: hashing
     Source:
*/
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_set<int> s;
	    for(int i=0;i<n;i++)
	    {
	        int temp=x-arr[i];
	        if((s.find(temp)!=s.end()))
	            return true;
	       s.insert(arr[i]);
	    }
	    return false;
	}
};