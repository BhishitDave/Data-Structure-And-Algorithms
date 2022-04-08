#include <bits/stdc++.h>
using namespace std;
int countSubsets(vector<int> &nums, int n, int M)
{
    int t[n + 1][M + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= M; j++) // we are taking zero here because we can have all elements zero and sum zero as well
        {
            if (nums[i - 1] <= j)
                t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;i<=M;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<'\n';
    }
    return t[n][M];
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];

    int M = (sum + target) / 2;
    if (sum < target || (sum + target) % 2 != 0)
        return 0;
    return countSubsets(nums, n, M);
}
int main()
{
    int n; cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
		arr.push_back(x);
    }
	int diff; 
    cin >> diff;
	cout << findTargetSumWays(arr, diff) << endl;
	return 0;
}