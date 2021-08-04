/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#
     Logic: hashing
     Source: gfg
*/
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> s;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(s.find(sum)!=s.end() or sum==0)
            {
                return true;
            }
            s.insert(sum);
        }
        return false;
    }
};