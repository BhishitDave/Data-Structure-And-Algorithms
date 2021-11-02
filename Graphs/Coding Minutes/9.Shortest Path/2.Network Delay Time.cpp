/*
     Complexity: Time=>O()   , Space=>O()
     Link : https://leetcode.com/problems/network-delay-time/submissions/
     Logic: use dijkstra
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

class Dijkstra
{
	public:
	vector<int> dis,par;
	vector<vector<pair<int,int>>> adj;
	Dijkstra(int n,vector<vector<pair<int,int>>> A)
	{
		dis.resize(n+1);
		par.resize(n+1,0);
		for(int i=1;i<=n;++i)
			dis[i]=INT_MAX;	
		adj = A; 
	}
	
	int find_dis(int root ,int n)
	{
		set<pair<int,int>> s;
		s.insert({0,root});
		dis[root]=0;
		par[root]=root;
        int ans=0;
		while(!s.empty())
		{
			pair<int,int> p=*s.begin();
			s.erase(p);
			for(auto i:adj[p.second])
			{
				if(p.first+i.first<dis[i.second])
				{
					s.erase({dis[i.second],i.second});
					dis[i.second]=p.first+i.first;
					// par[i.second]=p.second;
					s.insert({dis[i.second],i.second});
				}
			}
		}
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX)
                return -1;
            else
                ans=max(ans,dis[i]);
        }
        return ans;
	}	
};
int main()
{
    
    return 0; 
}