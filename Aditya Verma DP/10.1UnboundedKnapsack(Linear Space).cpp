#include <bits/stdc++.h>
using namespace std;

int UnboundedKnapsack(int wt[], int val[], int W, int n)
{
    int t[W + 1]; // dp matrix
    memset(t,0,sizeof t);
    for(int i=0;i<=W;i++){
        for(int j=0;j<n;j++){
            if(wt[j]<=i){
                t[i]=max(t[i],t[i-wt[j]]+val[j]);
            }
        }
    }
    return t[W];
    
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
    cout << UnboundedKnapsack(wt, val, W, n) << endl;
    return 0;
}