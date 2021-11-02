#include <bits/stdc++.h>
using namespace std;
int maxValidAns;
void dfs(int curNode, vector<vector<int>> &graph, string &s, int dp[])
{

    vector<int> possiblePathsFromThisNode; // it will store all the Valid paths possible from this node to leaf
    dp[curNode] = 1;
    for (auto it : graph[curNode])
    {
        dfs(it, graph, s, dp);
        if (s[curNode] != s[it])
            possiblePathsFromThisNode.push_back(dp[it]);
    }

    int sz = possiblePathsFromThisNode.size();
    if (sz - 1 >= 0)
        dp[curNode] += possiblePathsFromThisNode[sz - 1];
    if (sz - 2 >= 0)
        dp[curNode] += possiblePathsFromThisNode[sz - 2];

    maxValidAns = max(maxValidAns, dp[curNode]);
}
int solution(string &s, vector<int> &A)
{
    maxValidAns=0;
    int n = s.length();
    int dp[n];                                   // dp[i] will store the maximum valid path that can be obtained from the subtree of node i including node i.
    vector<vector<int>> graph(n, vector<int>()); // creating ajdacency list
    maxValidAns = 0;

    for (int i = 1; i < A.size(); i++)
    {
        graph[A[i]].push_back(i);
    }

    dfs(0, graph, s, dp); // usind depth first search

    return maxValidAns;
}
int main()
{

    string s="ab";
    vector<int> v={-1,0};
    cout<<solution(s,v);
    return 0;
}