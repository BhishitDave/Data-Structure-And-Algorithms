class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0)
			return 0;
		unordered_map<int,int>m;
		m.insert({0,1});
		int sum = 0,ans=0;
		for(int i=0;i<nums.size();i++){
			sum +=nums[i];
			int rsum = sum-k;
			if(m.count(rsum))
				ans += m[rsum];
			m[sum]++;
		}
		return ans;
    }
};