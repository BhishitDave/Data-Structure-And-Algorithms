/*
     Complexity: Time=>O(n)   , Space=>O(1)
     Link : https://leetcode.com/problems/max-consecutive-ones-iii/
     Logic: sliding window similar to 6
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& s, int k) {
        int start=0 , ans =0,max_freq = 0;
        int mp[2]={0,0};
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(s[i]==1)
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