// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
// if a knows b push b in stack
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        while(st.size()>1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(M[a][b]) //a knows b
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        int candidate = st.top();
        int count1=0;
        for(int i=0;i<n;i++)
        {
            if(M[i][candidate])
            count1++;
        }
        int count0=0;
        for(int i=0;i<n;i++)
        {
            if(!M[candidate][i])
            count0++;
        }
        if(count1==(n-1) and count0==n)
        return candidate;
        else
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends