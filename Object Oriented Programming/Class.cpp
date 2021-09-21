#include <bits/stdc++.h>
using namespace std;

class Rectangle{
    public:
    int length;
    int breadth;

    int area()
    {
        return length*breadth;
    }
    int perimeter()
    {
        return 2*(length+breadth);
    }
};
// We can access member of class via  . operator if we use variable obj
// We can access member of class via  . operator if we use pointer obj
int main()
{ // created in stack
    Rectangle r;
    Rectangle *p;  // pointer to object
    Rectangle  p1;
    p=&p1;
    r.length=99;
    p->length=99;
    //created in heap
    Rectangle *x =new Rectangle();
    x->length=99;
    return 0; 
}
