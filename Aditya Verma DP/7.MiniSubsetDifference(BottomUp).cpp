#include <bits/stdc++.h>
using namespace std;

vector<int> isSubsetPoss(int arr[], int n, int sum) {
	bool t[n + 1][sum + 1]; // DP - matrix
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0)
				t[i][j] = false;
			if (j == 0) 
				t[i][j] = true;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}
    vector<int> v;
    for(int j=0;j<=sum;j++){
        if(t[n][j]==true)
        {
            v.push_back(j);
        }
    }

    return v;

}

int minSubDiff(int arr[],int n, int range){

    vector<int> v = isSubsetPoss(arr,n,range);
    int mini=INT_MAX;
    for(int i=0;i<v.size();i++){
        mini=min(mini, abs(range- 2*v[i]));
    }
    return mini;

}
int main()
{
    int n,range(0);
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        range+=arr[i];
    }
    cout<<minSubDiff(arr,n,range);

    return 0;
}