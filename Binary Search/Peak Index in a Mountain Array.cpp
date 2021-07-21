
/*
     Name: Bhishit Dave
     Link : https://leetcode.com/problems/peak-index-in-a-mountain-array/
     Logic: similar to max peak element
     Source: leetcode
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return search(arr, 0, arr.size() - 1);
    }
     int search(vector<int>nums, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }
};