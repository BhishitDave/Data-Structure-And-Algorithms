/*
     Link : https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#
     Logic: 
     Source: gfg
*/
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      unordered_set<int> s;
      int ans=0;
      for(int i=0;i<n;i++)
      {
          s.insert(arr[i]);
      }
      for(int i=0;i<n;i++)
      {
          if(s.find(arr[i]-1)==s.end())
          {
              int j=arr[i];
              while(s.find(j)!=s.end())
              j++;
              
              ans=max(ans,j-arr[i]);
          }
      }
      return ans;
    }
};