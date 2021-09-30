/*
     Complexity: Time=>O()   , Space=>O()
     Link : https://leetcode.com/problems/word-ladder/
     Logic:
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wordsize = beginWord.size();
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> word;
        for(auto s : wordList)
        {
            word.insert(s);
        }
        if(word.find(endWord)==word.end())
            return 0;
        int len=0;
        while(!q.empty())
        {
            len++;
            int qlen=q.size();
            for(int i=0;i<qlen;i++)
            {
                string s =q.front();
                q.pop();
                for(int j=0;j<wordsize;j++)
                {
                    char org =s[j];
                    for(char ch='a';ch<='z';ch++)
                    {
                        s[j]=ch;
                        if(s==endWord) return len+1;
                        if(word.find(s) ==word.end()) continue;
                        
                        word.erase(s);
                        q.push(s);
                    }
                    s[j] =org;
                }
            }
        }
        return 0;
    }
};