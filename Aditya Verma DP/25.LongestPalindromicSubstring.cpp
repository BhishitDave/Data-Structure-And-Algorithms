#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m)
{
    int dp[n + 1][m + 1]; // DP - matrix

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;
    int mx = INT_MIN;
    int row, col,count(0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if(mx<dp[i][j]){
                    mx=dp[i][j];
                    row=i;
                    col=j;
                }
            }
            else //discontinuity check 
            {
                dp[i][j] = 0; 
            }
        }
    string ans="";
    while(dp[row][col]!=0){
        ans.push_back(X[row-1]);
        row--;
        col--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return mx;
}

int LPSubstring(string X, int n) {
	string rev_X = X;
	reverse(rev_X.begin(), rev_X.end());
	return LCS(X, rev_X, n, n);
}

signed main() {
	string X, Y; cin >> X;
	int n = X.length();
	cout << LPSubstring(X, n) << endl;
	return 0;
}