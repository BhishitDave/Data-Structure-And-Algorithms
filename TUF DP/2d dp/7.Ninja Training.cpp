/*
    Time Complexity: O(2^N)
    Space Complexity: O(2^N)
    recursive solution
    where 'N' is the number of days.
*/

int rec(int n, int i, vector<vector<int>> &points){

    if (n == 0){
        // No more days left.
        return 0;
    }

    // Merit points of ith task on nth day.
    int ans = points[n - 1][i - 1];
    int mx = 0;
    if (i == 1){
        mx = max(rec(n - 1, 2, points), rec(n - 1, 3, points));
    }

    if (i == 2){
        mx = max(rec(n - 1, 1, points), rec(n - 1, 3, points));
    }

    if (i == 3){
        mx = max(rec(n - 1, 1, points), rec(n - 1, 2, points));
    }

    return ans + mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    int ans = 0;
    ans = max(ans, rec(n, 1, points));
    ans = max(ans, rec(n, 2, points));
    ans = max(ans, rec(n, 3, points));

    return ans;
}
/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the number of days.
*/
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int dp[n][3];
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            dp[i][0]=points[0][0];
            dp[i][1]=points[0][1];
            dp[i][2]=points[0][2];
            continue;
        }
        dp[i][0]=max(dp[i-1][1] , dp[i-1][2]) + points[i][0];
        dp[i][1]=max(dp[i-1][0] , dp[i-1][2]) + points[i][1];
        dp[i][2]=max(dp[i-1][1] , dp[i-1][0]) + points[i][2];
    }
    int ans = 0;
    ans = max(ans, dp[n - 1][0]);
    ans = max(ans, dp[n - 1][1]);
    ans = max(ans, dp[n - 1][2]);
    return ans;
}