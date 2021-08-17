/*
     Complexity: Time=>O(2^n)   , Space=>O(1)
     Link : https://practice.geeksforgeeks.org/problems/power-set4302/1#
     Logic: use set bits to form string (0 to 2^n - 1 ) , can be solved using recursion
     Source:gfg
*/
class Solution{
	public:
	
	   
		vector<string> AllPossibleStrings(string str){
		    // Code here
    <string> ans;
	int n = str.length();

	int powSize = pow(2, n);

	for(int counter = 0; counter < powSize; counter++)
	{ string x="";
		for(int j = 0; j < n; j++)
		{
			if((counter & (1 << j)) != 0)
                x+=str[j];
		}
		if(x.size()!=0)
		ans.push_back(x);
	}
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};