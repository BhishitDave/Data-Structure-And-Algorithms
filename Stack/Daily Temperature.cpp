/*
     Complexity: Time=>O()   , Space=>O()
     Link : https://leetcode.com/problems/daily-temperatures/
     Logic: 
     Source:
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> s;
        vector<int> ans(temp.size() , 0);
        for(int i=0;i<temp.size();i++)
        {
            while(s.size()!=0 and s.top().first<temp[i])
            {
                auto top=s.top();
                ans[top.second]=abs(top.second -i);
                s.pop();
            }
            s.push({temp[i],i});
        }
        return ans;
    }
};