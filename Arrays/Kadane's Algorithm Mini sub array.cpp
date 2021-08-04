#include <bits/stdc++.h>
using namespace std;

int minSubArray(vector<int> &nums)
{
   int minimum=INT_MAX;
   int curr_sum=INT_MAX;
   for(int i=0;i<nums.size();i++)
   {
       if(curr_sum>0)
       {
           curr_sum=nums[i];
       }
       else
       {
           curr_sum+=nums[i];
       }
       if(minimum>curr_sum)
       {
           minimum=curr_sum;
       }
   }
   return minimum;
}
int main()
{

    vector<int> nums = {3, -4, 2, -3, -1, 7, -5};
    cout << minSubArray(nums);
    return 0;
}