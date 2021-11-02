#include <bits/stdc++.h>
using namespace std;

bool CompareHeight(pair<int , char>p1 ,pair<int , char> p2)
{
    return p1.first>p2.first;
}



int solution(string s, vector<int>x, vector<int> y)
{
    priority_queue<pair<int , char> , vector<pair<int, char>> , std::function<bool(pair<int , char> ,pair<int , char>)>>Q(CompareHeight);
    for(int i=0;i<x.size();i++)
    {
        double distance = sqrt(pow(x[i],2)+pow(y[i],2));
        Q.push({distance , s[i]});
    }

    map<char , int>mp;
    while(mp.size()!=x.size())
    {
        auto p=Q.top();
        Q.pop();
        if(mp.find(p.second)==mp.end())
        {
            mp.insert({p.second,p.first});
        }
        else{
            auto x = mp[p.second];
            if(x==p.first)
            {
                return mp.size()-1;
            }
            else
            {
                return mp.size();
            }
        }
    }
    return mp.size();
}
int main()
{
    vector<int> a{2,-1,-4 , -3 , 3};
    vector<int> b{2 , -2 , 4, 2 , -3};
    string s="ABDCA";
    cout<<solution(s,a,b)<<endl;
    return 0; 
}