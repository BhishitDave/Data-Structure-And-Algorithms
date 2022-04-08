/*
     Complexity: Time=>O(n)   , Space=>O(1)
     Link : https://leetcode.com/problems/majority-element/
     Logic: moore voting algorithm
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element, count=0;
        for(auto num: nums)
        {
            if(count==0)
            {
                count++;
                element=num;
            }
            else
            {if(element==num)
                count++;
            else
                count--;}
        }
        return element;
    }
};
