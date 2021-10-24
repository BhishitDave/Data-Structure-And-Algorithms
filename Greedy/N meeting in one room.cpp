/*
     Complexity: Time=>O(nlogn)   , Space=>O()
     Link : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
     Logic:
     Source:
*/
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comparator(pair<int , int>p1, pair<int , int>p2)
    {
        return (p1.second<p2.second);
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int , int>> p;
        for(int i=0;i<n;i++)
        {
            p.push_back({start[i] , end[i]});
        }
        sort(p.begin() , p.end() , comparator);
        int count=1;
        vector<pair<int , int>> result;
        result.push_back(p[0]);
        int last=p[0].second;
        for(int i=1;i<n;i++)
        {
            if(p[i].first>last)
            {
                count++;
                result.push_back(p[i]);
                last=p[i].second;
            }
        }
        for(auto i: result)
        {
            cout<<i.first<<" "<<i.second<<"\n";
        }
        return count;
    }
};