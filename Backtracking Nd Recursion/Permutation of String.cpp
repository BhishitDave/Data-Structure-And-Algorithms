/*
     Name: Bhishit Dave
     Link : https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#
     Logic: Do - Recur - Undo
     Source: gfg
*/

//! O(n!*n);
#include <bits/stdc++.h>
using namespace std;

void permutation(string s, int left , int right){
    if(left==right){
        cout<<s<<endl;
    }
    else{
    for(int i=left;i<=right;i++){
        //do
    swap(s[left], s[i]);
        //recur
    permutation(s,left+1,right);
        //undo
    swap(s[left], s[i]);
        
        }
    }

}
int main()
{
    string s;
    cin>>s;
    permutation(s,0, s.size()-1);
    return 0; 
}