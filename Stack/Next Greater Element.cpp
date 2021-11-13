/*
     Complexity: Time=>O(n)   , Space=>O(n)
     Link : https://leetcode.com/problems/next-greater-element-i/
     Logic: 
     Source: aditya verma
*/
/*
    code snippet
    stack<int> s;
    int res[n];
    for (int i = n - 1; i >= 0; i--) {
        if (!s.empty()) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mp; // used to store index of nums1
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]=i;
        }
        vector<int>ans(nums1.size(),0);
        for(int i=nums2.size()-1;i>=0;i--) //monotonic stack
        {
            while(!s.empty() and s.top()<=nums2[i])
            {
                s.pop();
            }
            if(mp.find(nums2[i])!=mp.end())
            {
                if(s.size()==0)
                    ans[mp[nums2[i]]]=-1;
                else
                    ans[mp[nums2[i]]]=s.top();
            }
            s.push(nums2[i]);
        }
        return ans;
        
}
};
// **** 4 ms, faster than 92.46% of C++ online submissions*****
// in this we loop from index 0;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mp; // used to store maximum of elements
        for(int i=0;i<nums2.size();i++)
        {
            while(s.size()!=0 and s.top()<nums2[i])
            {
                mp[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            if(mp.find(nums1[i])!=mp.end())
            {
                ans.push_back(mp[nums1[i]]);
            }
            else
                ans.push_back(-1);
        }
        return ans;
}
};