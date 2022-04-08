#include <bits/stdc++.h>
using namespace std;

const int D = 1000; // DP - matrix dimension, assume this is maximum value
int t[D][D]; // DP matrix

int Knapsack(int wt[], int val[], int W, int n){
    if(n==0 ||W==0){ // base case
        return 0;
    }
    // if already calculated
    if(t[n][W]!=-1){
        return t[n][W];  
    }
    if(wt[n]<=W){ // if we can include weight
        return t[n][W]=max(val[n] + Knapsack(wt, val, W - wt[n], n - 1),
		           Knapsack(wt, val, W, n - 1));
    }
    else{ // if we cannot include weight
        return t[n][W]= Knapsack(wt,val, W,n-1);
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
    cin >> W; // Knapsack capacity
    memset(t,-1,sizeof(t));
    cout << Knapsack(wt, val, W, n-1) << endl;
    return 0;
}