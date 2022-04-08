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
    int characterReplacement(string s, int k) {
        int start=0 , ans =0,max_freq = 0;
        unordered_map<char , int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            max_freq =  max(max_freq , mp[s[i]]);
            if(i-start+1 - max_freq > k )
            {
                mp[s[start]]--;
                start++;
            }
            ans = max(ans , i-start+1);
        }
        return ans;
    }
};