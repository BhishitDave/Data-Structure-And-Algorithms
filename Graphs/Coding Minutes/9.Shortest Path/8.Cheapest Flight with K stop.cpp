/*
     Complexity: Time=>O(kn)   , Space=>O(n)
     Link : https://leetcode.com/problems/cheapest-flights-within-k-stops/
     Logic: use bellman ford dp algorithm(Catch of temp vector)
     Source: leetcode
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        for(int count=0; count<=k; count++){
            vector<int> temp = dist;
            for(vector<int>& v: flights){
                if(dist[v[0]] == INT_MAX)
                    continue;
				//Relax Operation
                if(temp[v[1]] > dist[v[0]] + v[2])
                    temp[v[1]] = dist[v[0]] + v[2];
            }
            dist = temp;
        }
        return (dist[dst] == INT_MAX ? -1 : dist[dst]);
    }
};