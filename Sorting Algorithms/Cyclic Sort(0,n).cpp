#include <bits/stdc++.h>
using namespace std;

void CyclicSort(vector<int> &v)
{
    int i=0;
    while(i<v.size())
    {
        int correct =v[i]-1;
        if(v[i]!= v[correct])
        {
            swap(v[i],v[correct]);
        }
        else{
            i++;
        }
    }
}
int main()
{
    vector<int > v ={5,4,3,2,1};
    CyclicSort(v);
    for(int &x:v)
    {
        cout<<x<<" ";
    }
    return 0; 
}