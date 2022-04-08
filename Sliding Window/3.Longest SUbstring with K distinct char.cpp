/*
     Complexity: Time=>O(n)   , Space=>O(1)
     Link : https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/
     Logic: sliding window
     Source:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char, int> um;
    int n = s.size();
    int start=0;
    int end=0;
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
        if(um.size()==k)
        maxlength = max(maxlength, end - start +1); 
    }
    if(maxlength<k or maxlength ==0)
    return -1;
    else
    return maxlength;
    }
};