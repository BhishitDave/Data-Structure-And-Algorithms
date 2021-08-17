/*
     Complexity: Time=>O(logn)   , Space=>O(1)
     Link : https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#
     Logic: any power of 2 will have only 1 set bit
     Source: gfg
*/
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here 
        if(n==0) return false;
        return ((n&(n-1))==0);
        
    }
};