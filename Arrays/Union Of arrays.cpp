/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
     Logic: use hashmap
     Source: 
*/

class Solution
{
public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)
    {
        // Your code goes here
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
            s.insert(a[i]);
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            s.insert(b[i]);
        }
        return s.size();
    }
};
