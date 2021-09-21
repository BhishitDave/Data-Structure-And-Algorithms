#include <bits/stdc++.h>
using namespace std;

class Complex
{
    private:
    int real;
    int img;
    public:
    Complex(int r=0 , int i=0)
    {
        real=r;
        img=i;
    }
    Complex operator+(Complex x)
    {
        Complex temp;
        temp.real=real+x.real;
        temp.img=img+x.img;
        return temp;
    } 
    friend ostream &operator<<(ostream &o , Complex & x);
    friend istream & operator >> (istream &in,  Complex &c);
};
ostream &operator<<(ostream &o , Complex & x)
    {
        o<<x.real<<" + i"<<x.img;
        return o;
    } 
istream & operator >> (istream &in,  Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imaginary Part ";
    in >> c.img;
    return in;
}
int main()
{
    Complex c1;
    Complex c2;
    cin>>c1;
    cin>>c2;
    Complex c3 =c1+c2;
    cout<<c3;
    return 0; 
}