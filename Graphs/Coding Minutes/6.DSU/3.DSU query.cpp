#include<bits/stdc++.h>
using namespace std;
    int findSet(int i, vector<int> &parent)
    {
        //basecase
        if (parent[i] == -1)
            return i;

        return findSet(parent[i], parent);
    }
    //Union
    void union_set(int x, int y, vector<int> &parent)
    {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if (s1 != s2)
        {
            parent[s1] = s2;
        }
    }
vector<bool> DSU(vector<vector<int>>query)
{
    vector<bool> ans;
    vector<int> v(1e5 + 1 ,-1);
    for(auto i: query)
    {
        if(i[0]==1)
        {
            union_set(i[1] , i[2] , v);
        }
        else
        {
            int s1=findSet(i[1] , v);
            int s2=findSet(i[2] , v);
            if(s1==s2)
            ans.push_back(true);
            else
            ans.push_back(false);
        }
    }
    return ans;
}