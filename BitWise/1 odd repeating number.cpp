/*
     Complexity: Time=>O(N)   , Space=>O(1)
     Link : https://practice.geeksforgeeks.org/problems/find-the-odd-occurence4820/1
     Logic: xor of even number will cancel out each other
     Source: gfg
*/
class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        // code here
        int _xor=0;
        for(int i=0;i<n;i++)
        {
            _xor=_xor^arr[i];
        }
        return _xor;
    }
};