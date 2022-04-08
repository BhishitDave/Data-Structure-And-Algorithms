#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
	
}

// Driver program to test above function
int main()
{
	int a , b;
    cout<<"Enter Value of a and b\n";
	cin >> a >> b;
	// int a = 98, b = 56;
	cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b)<<endl;
	if(gcd(a,b)==1)
	cout<<a<<" and "<<b<<" are coprime";
	return 0;
}
