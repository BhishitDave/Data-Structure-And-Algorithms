/*
     Complexity: Time=>O(n)   , Space=>O(1)
     Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
     Logic: sliding window
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0 , start =0;
        unordered_map<char, int> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.count(s[i]))
            {
                start = max(start , mp[s[i]]+1);
            }
            mp[s[i]]=i;
            ans = max(ans , i - start+1);
        }
        return ans;
    }
};