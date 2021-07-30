/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#
     Link : https://leetcode.com/problems/sort-colors/
     Logic: 2 pointer approach
     Source: tuf
*/
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int l=0,m=0,h=n-1;
        while(m<=h)
        {
            if(a[m]==0)
            {
                swap(a[l],a[m]);
                m++;
                l++;
            }
            else if(a[m]==1)
            {
                m++;
            }
            else if(a[m]==2)
            {
                swap(a[m],a[h]);
                h--;
            }
        }
    }
    
};