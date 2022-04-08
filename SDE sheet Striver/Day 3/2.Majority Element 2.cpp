/*
     Complexity: Time=>O(n)   , Space=>O(1)
     Link : https://leetcode.com/problems/majority-element-ii/
     Logic: moore voting algorithm(Modeified)
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        int element1, element2, count1 = 0, count2 = 0;
        for (auto num : nums)
        {
            if (num == element1)
            {
                count1++;
            }
            else if (num == element2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                element1 = num;
                count1++;
            }
            else if (count2 == 0)
            {
                element2 = num;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        cout << element1 << " " << element2;
        count1 = count2 = 0;
        for (auto num : nums)
        {
            if (num == element1)
                count1++;
            else if (num == element2)
                count2++;
        }
        if (count1 > (n / 3))
            ans.push_back(element1);
        if (count2 > (n / 3))
            ans.push_back(element2);
        return ans;
    }
};