/*
     Complexity: Time=>O(nlogn)   , Space=>O(n)
     Link : https://leetcode.com/problems/reorganize-string/
     Logic: heap and greedy
     Source:
*/

class Solution {
public:
    string reorganizeString(string s) {
        map<char , int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int , char>> pq;
        for(auto i :mp)
        {
            pq.push({i.second, i.first});
        }
        string res="";
        while(pq.size()>1)
        {
            auto p=pq.top();
            pq.pop();
            auto q=pq.top();
            pq.pop();
            res+=p.second;
            res+=q.second;
            p.first--;
            q.first--;
            if(p.first>0)
                pq.push({p.first , p.second});
            if(q.first>0)
                pq.push({q.first , q.second});
        }
        if(!pq.empty())
        {
            if(pq.top().first==1)
                res+=pq.top().second;
            else
                return "";
        }
        return res;
    }
};