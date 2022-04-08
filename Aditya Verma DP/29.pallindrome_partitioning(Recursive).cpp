#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string X, int i, int j) {
    while(i<=j){
        if(X[i]!=X[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int Solve(string X, int i, int j) {
	if (i >= j || isPallindrome(X, i, j))
    {
        return 0;
    }
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=Solve(X, i, k)+Solve(X,k+1,j)+1;
        ans=min(ans,temp);
    }
    return ans;
}

int main() {
	string X; cin >> X;

	cout << Solve(X, 0, X.length() - 1) << endl;
	return 0;
}