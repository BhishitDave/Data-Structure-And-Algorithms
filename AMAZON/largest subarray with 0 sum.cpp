class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum==0)
                ans = i+1;
            else
            {
                if(mp.find(sum)!=mp.end())
                {
                    int range = i-mp[sum];
                    ans = max(ans , range);
                }
                else
                {
                    mp[sum]=i;
                }
            }
            
        }
        return ans;
    }
};