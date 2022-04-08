/*
     Complexity: Time=>O(n)   , Space=>O(1)
     Link : https://leetcode.com/problems/fruit-into-baskets/
     Logic: sliding window , similar to no 3
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& s) {
    unordered_map<int, int> um;
    int n = s.size();
    int start=0;
    int end=0;
        int k=2;
    int maxlength = 0;
    for(end = 0 ; end <n; end++)
    {
        um[s[end]]++;
        while(um.size()>k)
        {
            um[s[start]]--;
            if(um[s[start]]==0)
            um.erase(s[start]);
            start++;
        }
        maxlength = max(maxlength, end - start +1); 
    }
    return maxlength;
    }
};