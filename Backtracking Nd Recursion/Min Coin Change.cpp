/*
     Complexity: Time=>O(V^size)   , Space=>O()
     Link : 
     Logic:
     Source:
*/
#include <bits/stdc++.h>
using namespace std;

int countCoins(int coins[] , int size , int v)
{
    if(v==0)
        return 0;
    
    int ans=INT_MAX;
    for(int i=0;i<size;i++)
    {
        if(coins[i]<=v)
        {
            int sub_ans = countCoins(coins,size ,v-coins[i]);
            if(sub_ans!=INT_MAX and sub_ans+1<ans)
                ans=sub_ans+1;
        }
    }
    return ans;
}

int main()
{
    int coins[]={1,3,5};
    int v;
    cin>>v;
    cout<<countCoins(coins,3 , v);
    return 0; 
}