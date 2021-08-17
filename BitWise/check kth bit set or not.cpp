/*
     Complexity: Time=>O(logn)   , Space=>O(1)
     Link : https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1#
     Logic: use left shift or right shift operator
     Source: gfg
*/

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        if((n&(1<<(k))) !=0) //((n>>k) &1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};