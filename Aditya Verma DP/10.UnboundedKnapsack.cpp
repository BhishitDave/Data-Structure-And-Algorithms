#include <bits/stdc++.h>
using namespace std;

int UnboundedKnapsack(int wt[], int val[], int W, int n)
{
    int t[n + 1][W + 1]; // dp matrix
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 or j == 0)
            { //initialization
                t[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                int val1 =val[i - 1]+t[i][j - wt[i - 1]];
                 // complicated
                int val2 = t[i - 1][j];
                t[i][j] = max(val1, val2);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
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