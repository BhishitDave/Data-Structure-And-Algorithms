#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int start = 0;
    int end = 0;
    int maximum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        if (sum < 0)
        {
            start = i + 1;
            sum = 0;
        }
        if (maximum < sum)
        {
            maximum = sum;
            end = i;
        }
    }
    for (int i = start; i <= end; i++)
    {
        cout <<nums[i] << " ";
    }
    cout << "\n";
    return maximum;
}
int main()
{

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
    return 0;
}