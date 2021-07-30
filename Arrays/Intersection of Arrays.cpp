/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1#
     Logic: 
     Source: 
*/
//!Time complexity O(m+n)  
class Solution{
    public:
    //Function to return the count of the number of elements in
    //the intersection of two arrays.
    int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
        // Your code goes here
    unordered_set<int> s;
    for(int i = 0 ; i < n ; i++)
    s.insert(a[i]);
    int ans = 0;
    for(int i = 0 ; i < m ; i++) {
    if(s.find(b[i]) != s.end()) 
    {
    ans++;
    s.erase(b[i]);
    }
    }
    return ans;
    }
};