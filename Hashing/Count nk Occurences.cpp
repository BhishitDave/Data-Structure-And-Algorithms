/*
     Link : https://practice.geeksforgeeks.org/problems/count-element-occurences/1#
     Logic: use map to keep track of elements
     Source:
*/
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int a[], int n, int k) {
        // Your code here
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[a[i]]++;
        int ans=0;
        for(auto i: mp)
        {
            if(i.second>(n/k))
            ans++;
        }
        return ans;
    }
};