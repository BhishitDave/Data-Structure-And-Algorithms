class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2){
            return 0;
        }
        int leftmax= height[0];
        int rightmax=height[n-1];
        int l=1;
        int r=n-2;
        int ans=0;
        while(l<=r)
        {
            if(leftmax < rightmax)
            {
                if(height[l]>=leftmax)
                {
                    leftmax=height[l];
                    l++;
                }
                else
                {
                    ans+=leftmax-height[l];
                    l++;
                }
            }
            else
            {
                if(height[r]>=rightmax)
                {
                    rightmax=height[r];
                    r--;
                }
                else
                {
                    ans+=rightmax-height[r];
                    r--;
                }
            }
        }
        return ans;
    }
};