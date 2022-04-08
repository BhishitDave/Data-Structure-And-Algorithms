#include <bits/stdc++.h>
using namespace std;
//!!O(n3) complexity
int Solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = Solve(arr, i, k) + Solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]); //partition from i to k + pratition from k+1 to j + mul cost
        ans = min(ans, temp);
    }
    return ans;
}

signed main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << Solve(arr, 1, n - 1) << endl;
    return 0;
}