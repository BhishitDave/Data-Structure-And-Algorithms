#include <bits/stdc++.h>
using namespace std;
const int D = 1000;
int t[D][D];
//!! O(n3)
int Solve(int arr[], int i, int j) {
    if (i >= j)
    {
        t[i][j]=0;
        return t[i][j];
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    t[i][j] = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        t[i][j] = min(t[i][j],Solve(arr, i, k) + Solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]));
        
    }
    return t[i][j];
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(t, -1, sizeof(t));

	cout << Solve(arr, 1, n - 1) << endl;
	return 0;
}