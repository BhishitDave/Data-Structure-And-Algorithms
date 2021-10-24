#include <bits/stdc++.h>
using namespace std;

class Graph
{
    vector<pair<int, int>> *l;
    int V;

public:
    Graph(int n)
    {
        V = n;
        l = new vector<pair<int, int>>[n];
    }
    void addEdge(int x , int y , int wt)
    {
        l[x].push_back({y,wt});
        l[y].push_back({x,wt});
    }
    int prim_mst()
    {
        priority_queue<pair<pair<int,int>,int> , vector<pair<pair<int,int>,int>> , greater<pair<pair<int,int>,int>>> Q;
        bool *visited = new bool[V]{0};
        vector<pair<pair<int, int> ,int>> res;
        int ans=0;
        Q.push({{0,0},0}); // weight , node
        while(!Q.empty())
        {
            auto best=Q.top(); // edge with min weight
            Q.pop();
            int to=best.first.second;
            int weight=best.first.first;
            int from=best.second;
            if(visited[to])
            {
                continue; //discard the edge, and continue
            }
            res.push_back({{from , to },weight});
            ans+=weight;
            visited[to]=1;

            for(auto x:l[to])
            {
                if(visited[x.first==0])
                {
                    Q.push({{x.second,x.first},to});
                }
            }
        }
        for(auto i: res)
        {
            cout<<i.first.first<<" to "<<i.first.second<<" weight "<<i.second<<endl;
        }
        return ans;
    }
};

int main()
{
    int n,m;
	cin>>n>>m;

	Graph g(n+1);
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		g.addEdge(x-1,y-1,w);
	}

	cout<<g.prim_mst()<<endl;
    return 0;
}
// test cases
// 4 5
// 1 2 10
// 2 3 15
// 1 3 5
// 4 2 2
// 4 3 40