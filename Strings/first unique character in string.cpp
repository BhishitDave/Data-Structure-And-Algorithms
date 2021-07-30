/*
     Name: Bhishit Dave
     Link : https://leetcode.com/problems/first-unique-character-in-a-string/submissions/
     Logic: Use hashmap to store frequency
     Source:
     Complexity: space =>O(n), time=> O(n);
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int a[26]={0};
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            a[s[i]-'a']++;
        }
        for(int  i=0;i<n;i++)
        {
            if(a[s[i]-'a'] ==1)
                 return i;
        }
        return -1;
    }
};