/*
     Complexity: Time=>O(nm)   , Space=>O(1)
     Link : https://leetcode.com/problems/set-matrix-zeroes/
     Logic:
     Source: tuf
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int flag=false;
        for(int i=0;i<m;i++)
        {   
            if(matrix[i][0]==0) flag=true;
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=matrix[0][j] =0;
                }
            }
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=1;j--)
            {
                if(matrix[0][j]==0 or matrix[i][0]==0)
                    matrix[i][j]=0;
            }
            if(flag) matrix[i][0]=0;
        }
        return;
    }
};