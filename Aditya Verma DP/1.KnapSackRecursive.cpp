#include <bits/stdc++.h>
using namespace std;

int Knapsack(int wt[], int val[], int W, int n){
    if(n==0 ||W==0){ // base case
        return 0;
    }
    if(wt[n-1]<=W){ // if we can include weight
        return max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),
		           Knapsack(wt, val, W, n - 1));
    }
    else{ // if we cannot include weight
        return Knapsack(wt,val, W,n-1);
    }
}
int main()
{
    int n;
    cin >> n;          // number of items
    int val[n], wt[n]; // values and wts array
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int W;
    cin >> W; // Knappsack capacity

    cout << Knapsack(wt, val, W, n) << endl;
    return 0;
}
