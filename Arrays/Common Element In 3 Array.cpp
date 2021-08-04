/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/common-elements1132/1#
     Logic: Similar to 2 pointer approach
     Source:
*/
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int i=0,j=0,k=0;
            vector <int> ans;
            while(i<n1 and  j<n2 and k<n3)
            {
                if(A[i]==B[j] and B[j]==C[k])
                {
                    ans.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                }
                else if(A[i]<B[j])
                {
                    i++;
                }
                else if(B[j]<C[k])
                {
                    j++;
                }
                else
                k++;
                
            }
            vector<int>::iterator ip;
            ip = std::unique(ans.begin(), ans.end());
            ans.resize(std::distance(ans.begin(), ip));
            return ans;
        }

};