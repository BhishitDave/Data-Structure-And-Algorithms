#include <bits/stdc++.h>
using namespace std;
//!min heap
bool CompareHeight(pair<int , char>p1 ,pair<int , char> p2)
{
    return p1.first>p2.first;
}

int solution(string s, vector<int>x, vector<int> y)
{
    priority_queue<pair<int , char> , vector<pair<int, char>> , std::function<bool(pair<int , char> ,pair<int , char>)>>Q(CompareHeight);
}