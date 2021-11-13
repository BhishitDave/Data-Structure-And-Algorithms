/*
     Complexity: Time=>O(n2)   , Space=>O(n)
     Link : https://leetcode.com/problems/number-of-provinces/
     Logic: use dsu and count parent node.
     Source:
*/

class Solution {
public:
    int findSet(int i, vector<int> &parent)
	{
		if (parent[i] == -1)
		{
			return i;
		}
		int p = findSet(parent[i], parent);
		// compress the path for next time
		parent[i] = p;
		return p;
	}
	void union_set(int u, int v, vector<int> &rank, vector<int> &parent)
	{

		int p1 = findSet(u, parent);
		int p2 = findSet(v, parent);

		if (p1 != p2)
		{
			if (rank[p1] < rank[p2])
			{
				parent[p1] = p2;
				rank[p2] += rank[p1];
			}
			else
			{
				parent[p2] = p1;
				rank[p1] += rank[p2];
			}
		}
	}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> parent(n+1,-1);
        vector<int> rank(n+1,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] and i!=j)
                {
                    int p1 = findSet(i+1,parent);
                    int p2 = findSet(j+1,parent);
                    isConnected[j][i]=0;
                    if(p1!=p2)
                    {
                        union_set(p1,p2,rank,parent);
                    }
                }
                
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            // cout<<parent[i]<<" ";
            if(parent[i]==-1)
                ans++;
        }
        return ans;  
    }
};