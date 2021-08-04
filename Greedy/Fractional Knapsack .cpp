/*
     Complexity: Time=>O(n)   , Space=>O(1)
     Link : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
     Logic: greedy approach
     Source:
*/
class Solution
{
    public:
    static bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, struct Item arr[], int n)
    {
        // Your code here
        int wei=W;
        sort(arr, arr + n, cmp);
        double ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight<=W)
            {
                ans+=arr[i].value;
                W=W-arr[i].weight;
            }
            else
            {
                ans+=(double(W)/double(arr[i].weight))*double(arr[i].value);
                break;
            }
        }
        return ans;
    }
        
};