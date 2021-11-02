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
bool solve(vector<vector<int>> edges) {
    vector<int> parent(100001 , -1);
    for (auto node:edges )
        {
            int i = node[0];
            int j = node[1];

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);
            if (s1 != s2)
            {
                union_set(s1, s2, parent);
            }
            else
            {
                // cout<<"Same parents "<<s1<<" and "<<s2<<endl;
                return false;
            }
        }
        return true;
}