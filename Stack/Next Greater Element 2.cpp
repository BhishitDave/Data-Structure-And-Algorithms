/*
     Complexity: Time=>O(n)   , Space=>O(n)
     Link : https://leetcode.com/problems/next-greater-element-ii/
     Logic:
     Source:
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--)
            s.push(nums[i]);
        vector<int> v(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(s.size()!=0 and s.top()<=nums[i])
                s.pop();
        if(s.size()==0)
            v[i]=-1;
        else
            v[i]=s.top();
        s.push(nums[i]);
        }
            
        return v; 
    }
};
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> nge(n, -1);
        stack<int> st; 
        for(int i = 2*n-1;i>=0;i--) {
            while(!st.empty() && st.top() <= nums[i%n]) {
                st.pop(); 
            }
            
            if(i<n) {
                if(!st.empty()) nge[i] = st.top(); 
            }
            st.push(nums[i%n]);
        }
        return nge; 
    }
};